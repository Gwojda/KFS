#include "kernel.h"

void kmain(void)
{
	/* Initialize terminal interface */
	terminal_initialize();

	/* Newline support is left as an exercise. */
	terminal_color = vga_entry_color(VGA_COLOR_RED, VGA_COLOR_BLACK);
	terminal_putstr("\n"
"         ___---___\n"
"      .--         --.\n"
"    ./   ()      .-. \\.\n"
"   /   o    .   (   )  \\\n"
"  / .            '-'    \\\n"
" | ()    .  O         .  |\n"
"|                         |\n"
"|    o           ()       |\n"
"|       .--.          O   |\n"
" | .   |    |            |\n"
"  \\    `.__.'    o   .  /\n"
"   \\                   /\n"
"    `\\  o    ()      /'\n"
"      `--___   ___--'\n"
"            ---\n");
}
