/*
 * Copyright (c) 2018 ETH Zurich, University of Bologna, GreenWaves Technologies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <drivers/pulp/cluster.h>
#include <string.h>
#include <stdio.h>

typedef struct rt_alloc_block_s {
  int                      size;
  struct rt_alloc_block_s *next;
} rt_alloc_chunk_t;

typedef struct {
  rt_alloc_chunk_t *first_free;
} rt_alloc_t;

// Allocate at least 4 bytes to avoid misaligned accesses when parsing free blocks 
// and actually 8 to fit free chunk header size and make sure a e free block to always have
// at least the size of the header.
// This also requires the initial chunk to be correctly aligned.
#define MIN_CHUNK_SIZE 8

static __attribute__((section(".l1_ram"))) rt_alloc_t cluster_alloc_l1;

#define ALIGN_UP(addr,size)   (((addr) + (size) - 1) & ~((size) - 1))
#define ALIGN_DOWN(addr,size) ((addr) & ~((size) - 1))

#define Max(x, y) (((x)>(y))?(x):(y))

/*
  A semi general purpose memory allocator based on the assumption that when something is freed it's size is known.
  The rationnal is to get rid of the usual meta data overhead attached to traditionnal memory allocators.
*/

void cluster_alloc_info(struct cluster *cluster, int *_size, void **first_chunk, int *_nb_chunks)
{
  rt_alloc_t *a = &cluster_alloc_l1;

  int key = irq_lock();

  if (first_chunk) *first_chunk = a->first_free;

  if (_size || _nb_chunks) {
    int size = 0;
    int nb_chunks = 0;

    rt_alloc_chunk_t *pt = a->first_free;

    for (pt = a->first_free; pt; pt = pt->next) {
      size += pt->size;
      nb_chunks++;
    }

    if (_size) *_size = size;
    if (_nb_chunks) *_nb_chunks = nb_chunks;
  }

  irq_unlock(key);
}

void cluster_alloc_dump(struct cluster *cluster)
{
  rt_alloc_t *a = &cluster_alloc_l1;
  
  int key = irq_lock();

  rt_alloc_chunk_t *pt = a->first_free;

  printf("======== Memory allocator state: ============\n");
  for (pt = a->first_free; pt; pt = pt->next) {
    printf("Free Block at %8X, size: %8x, Next: %8X ", (unsigned int) pt, pt->size, (unsigned int) pt->next);
    if (pt == pt->next) {
      printf(" CORRUPTED\n"); break;
    } else printf("\n");
  }
  printf("=============================================\n");

  irq_unlock(key);
}

static void alloc_init(rt_alloc_t *a, void *_chunk, int size)
{
  rt_alloc_chunk_t *chunk = (rt_alloc_chunk_t *)ALIGN_UP((int)_chunk, MIN_CHUNK_SIZE);
  a->first_free = chunk;
  size = size - ((int)chunk - (int)_chunk);
  if (size > 0) {
    chunk->size = ALIGN_DOWN(size, MIN_CHUNK_SIZE);
    chunk->next = NULL;
  }
}

void *cluster_alloc(struct cluster *cluster, int size)
{
  rt_alloc_t *a = &cluster_alloc_l1;

  int key = irq_lock();

  rt_alloc_chunk_t *pt = a->first_free, *prev = 0;

  size = ALIGN_UP(size, MIN_CHUNK_SIZE);

  while (pt && (pt->size < size)) { prev = pt; pt = pt->next; }

  if (pt) {
    if (pt->size == size) {
      // Special case where the whole block disappears
      // This special case is interesting to support when we allocate aligned pages, to limit fragmentation
      if (prev) prev->next = pt->next; else a->first_free = pt->next;
      irq_unlock(key);
      return (void *)pt;
    } else {
      // The free block is bigger than needed
      // Return the end of the block in order to just update the free block size
      void *result = (void *)((char *)pt + pt->size - size);
      pt->size = pt->size - size;
      irq_unlock(key);
      return result;
    }
  } else {
    //rt_warning("Not enough memory to allocate\n");
    irq_unlock(key);
    return NULL;
  }
}

void *cluster_alloc_align(struct cluster *cluster, int size, int align)
{
  if (align < (int)sizeof(rt_alloc_chunk_t)) return cluster_alloc(cluster, size);

  // As the user must give back the size of the allocated chunk when freeing it, we must allocate
  // an aligned chunk with exactly the right size
  // To do so, we allocate a bigger chunk and we free what is before and what is after

  // We reserve enough space to free the remaining room before and after the aligned chunk
  int size_align = size + align + sizeof(rt_alloc_chunk_t) * 2;
  unsigned int result = (unsigned int)cluster_alloc(cluster, size_align);
  if (!result) return NULL;

  unsigned int result_align = (result + align - 1) & -align;
  unsigned int headersize = result_align - result;

  // In case we don't get an aligned chunk at first, we must free the room before the first aligned one
  if (headersize != 0) {

    // If we don't have enough room before the aligned chunk for freeing the header, take the next aligned one
    if (result_align - result < sizeof(rt_alloc_chunk_t)) result_align += align;

    // Free the header
    cluster_free(cluster, (void *)result, headersize);
  }

  // Now free what remains after
  cluster_free(cluster, (unsigned char *)(result_align + size), size_align - headersize - size);

  return (void *)result_align;
}

void __attribute__((noinline)) cluster_free(struct cluster *cluster, void *_chunk, int size)

{
  rt_alloc_t *a = &cluster_alloc_l1;
  
  int key = irq_lock();

  rt_alloc_chunk_t *chunk = (rt_alloc_chunk_t *)_chunk;
  rt_alloc_chunk_t *next = a->first_free, *prev = 0;
  size = ALIGN_UP(size, MIN_CHUNK_SIZE);

  while (next && next < chunk) {
    prev = next; next = next->next; 
  }

  if (((char *)chunk + size) == (char *)next) {
    /* Coalesce with next */
    chunk->size = size + next->size;
    chunk->next = next->next;
  } else {
    chunk->size = size;
    chunk->next = next;
  }

  if (prev) {
    if (((char *)prev + prev->size) == (char *)chunk) {
      /* Coalesce with previous */
      prev->size += chunk->size;
      prev->next = chunk->next;
    } else {
      prev->next = chunk;
    }
  } else {
    a->first_free = chunk;
  }

  irq_unlock(key);
}

extern unsigned char __l1_heap_start;
extern unsigned char __l1_heap_size;

static inline void *cluster_l1_base(int cid)
{
  return ((char *)&__l1_heap_start);
}

static inline int cluster_l1_size(int cid)
{
  return (int)&__l1_heap_size;
}

void cluster_alloc_init()
{
  alloc_init(&cluster_alloc_l1, cluster_l1_base(0), cluster_l1_size(0));
}
