#ifndef KERNEL_H
# define KERNEL_H

# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

# include "position.h"

# include "GDT.h"
# include "vga.h"
# include "lib.h"
# include "tty.h"
# include "printk.h"
# include "io.h"
# include "shell.h"
# include "page.h"
# include "idt.h"
# include "lib.h"
# include "virt_mem_management.h"
# include "phys_mem_management.h"

# if !defined(__i386__)
#  error "This kernel needs to be compiled with a ix86-elf compiler"
# endif

#endif
