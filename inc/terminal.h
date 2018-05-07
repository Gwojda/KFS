#ifndef TERMINAL_H
# define TERMINAL_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#if !defined(__i386__)
 #error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

enum vga_color {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};

extern const size_t VGA_WIDTH;
extern const size_t VGA_HEIGHT;

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;

volatile uint16_t* terminal_buffer;

/*
* Note the use of the volatile keyword to prevent the compiler from eliminating dead stores.
*/

void	terminal_initialize(void);
void	terminal_clear_screen(void);
void	terminal_putchar(char c);
void	terminal_putstr(const char* data);
void	terminal_write(const char* data, size_t size);
void	terminal_putentryat(char c, uint8_t color, size_t x, size_t y);
void	terminal_setcolor(uint8_t color);

uint16_t	vga_entry(unsigned char uc, uint8_t color);
uint8_t		vga_entry_color(enum vga_color fg, enum vga_color bg);

#endif
