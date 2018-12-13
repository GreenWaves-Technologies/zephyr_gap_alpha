#include <device.h>
#include <init.h>

#if defined(CONFIG_PRINTK) || defined(CONFIG_STDOUT_CONSOLE)

static int console_out(int c)
{
	*(volatile int *)(0x1a110000) = c;
	return c;
}
#endif

#if defined(CONFIG_STDOUT_CONSOLE)
extern void __stdout_hook_install(int (*hook)(int));
#else
#define __stdout_hook_install(x)		\
	do {/* nothing */			\
	} while ((0))
#endif

#if defined(CONFIG_PRINTK)
extern void __printk_hook_install(int (*fn)(int));
#else
#define __printk_hook_install(x)		\
	do {/* nothing */			\
	} while ((0))
#endif


void pulp_sim_console_hook_install(void)
{
	__stdout_hook_install(console_out);
	__printk_hook_install(console_out);
}

static int pulp_sim_console_init(struct device *arg)
{
	ARG_UNUSED(arg);
	pulp_sim_console_hook_install();
	return 0;
}

/* UART consloe initializes after the UART device itself */
SYS_INIT(pulp_sim_console_init,
#if defined(CONFIG_EARLY_CONSOLE)
			PRE_KERNEL_1,
#else
			POST_KERNEL,
#endif
			CONFIG_PULP_CONSOLE_INIT_PRIORITY);



