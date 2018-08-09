#include "vga.h"
#include "io.h"

#define SHIFT_PRESSED(x) (x == 0x36 || x == 0x2A)
#define SHIFT_RELEASED(x) (x == 0xB6 || x == 0xAA)

const unsigned char value_table_shift[] = 	{
	0,
	0, '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '\b',
	0, 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '\n',
	0, 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'', '~',
	0, '|', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?', 0,
	'*', 0, ' ', 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0,
	'7', '8', '9', '-',
	'4', '5', '6', '+',
	'1', '2', '3',
	'0', '.', '6',
	0, 0, 0, 0, 0,
};

const unsigned char value_table[] = 	{
	0,
	0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
	0, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
	0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ':', '\"', '`',
	0, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0,
	'*', 0, ' ', 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0,
	'7', '8', '9', '-',
	'4', '5', '6', '+',
	'1', '2', '3',
	'0', '.', '6',
	0, 0, 0, 0, 0
};

/*
* dont have yet interrupt ! we'll use it until we've got a good IDT
*/

char	getc(void)
{
	static char shift_locked = FALSE;
	unsigned int cr;
	unsigned int tmp;

/*
* Status Register - PS/2 Controller
* Bit Meaning
* 0   Output buffer status (0 = empty, 1 = full) (must be set before attempting to read data from IO port 0x60)
* 1   Input buffer status (0 = empty, 1 = full) (must be clear before attempting to write data to IO port 0x60 or IO port 0x64)
* 2   System Flag - Meant to be cleared on reset and set by firmware (via. PS/2 Controller Configuration Byte) if the system passes self tests (POST)
* 3   Command/data (0 = data written to input buffer is data for PS/2 device, 1 = data written to input buffer is data for PS/2 controller command)
* 4   Unknown (chipset specific) - May be "keyboard lock" (more likely unused on modern systems)
* 5   Unknown (chipset specific) - May be "receive time-out" or "second PS/2 port output buffer full"
* 6   Time-out error (0 = no error, 1 = time-out error)
* 7   Parity error (0 = no error, 1 = parity error)
*/
	if (inb(0x64) & 1)
	{
		cr = inb(0x60);
		tmp = cr;
		if (SHIFT_PRESSED(cr))
			shift_locked = TRUE;
		if (SHIFT_RELEASED(cr))
			shift_locked = FALSE;
		cr &= 0x7F;
		if (tmp == cr)
		{
			if (shift_locked)
				return value_table_shift[cr];
			else
				return value_table[cr];
		}
	}
	return 0;
}
