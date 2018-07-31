#ifndef MEMORY_H
# define MEMORY_H

# include "multiboot2.h"
# include "typedef.h"
# include "printk.h"
# include "list.h"
# include "panic.h"

# define MAX_RAM_PAGE 0x100000
# define HIGH_MEMORY_BEGIN 0x100000

void memory_init(unsigned long magic, unsigned long addr);

unsigned char	mm_bitmap[MAX_RAM_PAGE / 8];

#endif
