#include "kernel.h"

static void	print_kernel_visu(void)
{
	vga_setcolor(vga_entry_color(VGA_COLOR_LIGHT_RED, VGA_COLOR_BLACK + current_tty));
	vga_putstr("\n"
			"                             ___---___\n"
			"                          .--         --.\n"
			"                        ./   ()      .-. \\.\n"
			"                       /   o    .   (   )  \\\n"
			"                      / .            '-'    \\\n"
			"                     | ()    .  O         .  |\n"
			"                    |                         |\n"
			"                    |    o           ()       |\n"
			"                    |       .--.          O   |\n"
			"                     | .   |    |            |\n"
			"                      \\    `.__.'    o   .  /\n"
			"                       \\                   /\n"
			"                        `\\  o    ()      /'\n"
			"                          `--___   ___--'\n"
			"                         Moonlight Kernel\n"
			"################################################################################\n"
			);
	vga_setcolor(vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK + current_tty));

}

void kmain (unsigned long magic, unsigned long addr)
{
	init_tty();
	init_vga();
	memory_init(magic, addr);

// ------------------------

	printk("Kernel half destination %p\n", KERNEL_POS);
	printk("Kernel virtual position %p %p\n", KERNEL_START, KERNEL_END);
	printk("Kernel real position %p %p\n", KERNEL_REAL_START, KERNEL_REAL_END);
	printk("Kernel size %p\n", KERNEL_SIZE);
	printk("Kernel virtual bss position %p %p\n", KERNEL_BSS_START, KERNEL_BSS_END);
	printk("Kernel real bss position %p %p\n", KERNEL_REAL_BSS_START, KERNEL_REAL_BSS_END);
	printk("Kernel size %p\n", KERNEL_BSS_SIZE);
// ------------------------

//	print_kernel_visu();
	page_setup();
	init_gdt();
	page_setup();
//	launchshell();
}
