/*
 * Copyright (c) 2018 ETH Zurich, University of Bologna, GreenWaves Technologies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <string.h>
#include <stdio.h>
#include <pmsis.h>
#include "alloc.h"
#include "cluster.h"
#include "implem/implem.h"
#include <init.h>


// Allocate at least 4 bytes to avoid misaligned accesses when parsing free blocks 
// and actually 8 to fit free chunk header size and make sure a e free block to always have
// at least the size of the header.
// This also requires the initial chunk to be correctly aligned.
#define MIN_CHUNK_SIZE 8

L2_DATA rt_alloc_t alloc_l1[NB_CLUSTERS];
L2_DATA rt_alloc_t alloc_l2;

#define ALIGN_UP(addr,size)   (((addr) + (size) - 1) & ~((size) - 1))
#define ALIGN_DOWN(addr,size) ((addr) & ~((size) - 1))

#define Max(x, y) (((x)>(y))?(x):(y))

/*
  A semi general purpose memory allocator based on the assumption that when something is freed it's size is known.
  The rationnal is to get rid of the usual meta data overhead attached to traditionnal memory allocators.
*/

void rt_alloc_info(rt_alloc_t *a, int *_size, void **first_chunk, int *_nb_chunks)
{
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

void rt_alloc_dump(rt_alloc_t *a)
{
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

void *rt_alloc(rt_alloc_t *a, int size)
{
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

void *rt_alloc_align(rt_alloc_t *a, int size, int align)
{
  if (align < (int)sizeof(rt_alloc_chunk_t)) return rt_alloc(a, size);

  // As the user must give back the size of the allocated chunk when freeing it, we must allocate
  // an aligned chunk with exactly the right size
  // To do so, we allocate a bigger chunk and we free what is before and what is after

  // We reserve enough space to free the remaining room before and after the aligned chunk
  int size_align = size + align + sizeof(rt_alloc_chunk_t) * 2;
  unsigned int result = (unsigned int)rt_alloc(a, size_align);
  if (!result) return NULL;

  unsigned int result_align = (result + align - 1) & -align;
  unsigned int headersize = result_align - result;

  // In case we don't get an aligned chunk at first, we must free the room before the first aligned one
  if (headersize != 0) {

    // If we don't have enough room before the aligned chunk for freeing the header, take the next aligned one
    if (result_align - result < sizeof(rt_alloc_chunk_t)) result_align += align;

    // Free the header
    rt_free(a, (void *)result, headersize);
  }

  // Now free what remains after
  rt_free(a, (unsigned char *)(result_align + size), size_align - headersize - size);

  return (void *)result_align;
}

void __attribute__((noinline)) rt_free(rt_alloc_t *a, void *_chunk, int size)

{
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
extern unsigned char __l2_heap_start;
extern unsigned char __l2_heap_size;

void l1_alloc_init(int cid)
{
  // TODO add support for multiple clusters
  alloc_init(&alloc_l1[cid], ((char *)&__l1_heap_start), (int)&__l1_heap_size);

}

static int l2_alloc_init()
{
  alloc_init(&alloc_l2, ((char *)&__l2_heap_start), (int)&__l2_heap_size);
  return 0;
}

void __rt_alloc_cluster_req(void *_req)
{
  pi_cl_alloc_req_t *req = (pi_cl_alloc_req_t *)_req;
  req->result = rt_alloc(&alloc_l2, req->size);
  req->done = 1;
  __rt_cluster_notif_req_done(req->cid);
}

void __rt_free_cluster_req(void *_req)
{
  pi_cl_free_req_t *req = (pi_cl_free_req_t *)_req;
  rt_free(&alloc_l2, req->chunk, req->size);
  req->done = 1;
  __rt_cluster_notif_req_done(req->cid);
}


void rt_alloc_cluster(int flags, int size, pi_cl_alloc_req_t *req)
{
  req->flags = flags;
  req->size = size;
  req->cid = pi_cluster_id();
  req->done = 0;
  req->event.implem.kpoll = 0;
  pi_task_callback(&req->event, __rt_alloc_cluster_req, (void *)req);
  __rt_cluster_push_fc_event(&req->event);
}

void rt_free_cluster(int flags, void *chunk, int size, pi_cl_free_req_t *req)
{
  req->flags = flags;
  req->size = size;
  req->chunk = chunk;
  req->cid = pi_cluster_id();
  req->done = 0;
  req->event.implem.kpoll = 0;
  pi_task_callback(&req->event, __rt_free_cluster_req, (void *)req);
  __rt_cluster_push_fc_event(&req->event);
}

void pi_cl_l2_malloc(int size, pi_cl_alloc_req_t *req)
{
  rt_alloc_cluster(0, size, (pi_cl_alloc_req_t *)req);
}

void pi_cl_l2_free(void *chunk, int size, pi_cl_free_req_t *req)
{
  rt_free_cluster(0, chunk, size, (pi_cl_free_req_t *)req);
}

void *pmsis_l1_malloc(uint32_t size)
{
  return rt_alloc(&alloc_l1[0], size);
}

void pmsis_l1_malloc_free(void *_chunk, int size)
{
  rt_free(&alloc_l1[0], _chunk, size);
}

void *pmsis_l2_malloc(uint32_t size)
{
  return rt_alloc(&alloc_l2, size);
}

void pmsis_l2_malloc_free(void *_chunk, int size)
{
  rt_free(&alloc_l2, _chunk, size);
}

SYS_INIT(l2_alloc_init, PRE_KERNEL_1, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT);