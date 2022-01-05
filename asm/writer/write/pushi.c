
#include <debug.h>

#include "../write.h"

#include "pushi.h"

void asm_writer_write_pushi(
	struct asm_writer* this,
	uintmax_t val)
{
	ENTER;
	
	asm_writer_write(this, "movq $%ju, %%r10", val);
	asm_writer_write(this, "movq %%r10, -8(%%rsp)");
	asm_writer_write(this, "sub $8, %%rsp");
	
	EXIT;
}

