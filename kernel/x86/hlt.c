#include "process.h"
#include "GDT.h"

struct process	*process_hlt_create(void)
{
	struct process	*proc;
	char		*stack = kmalloc(4096);

	if (stack == NULL)
		return NULL;
	if ((proc = process_new()) == NULL)
	{
		kfree(stack);
		return NULL;
	}

	proc->regs.esp = (u32)(stack + 4096);
	proc->regs.eip = (u32)process_hlt_user;
	proc->regs.cs = GDT_SEG_KCODE;
	proc->regs.ss = GDT_SEG_KSTACK;
	proc->regs.ds = GDT_SEG_KDATA;
	proc->regs.es = GDT_SEG_KDATA;
	proc->regs.fs = GDT_SEG_KDATA;
	proc->regs.gs = GDT_SEG_KDATA;
	return proc;
}
