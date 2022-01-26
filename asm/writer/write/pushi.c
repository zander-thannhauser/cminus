
#if 0
#include <debug.h>

#include "../write.h"

#include "pushi.h"

void asm_writer_write_pushi(struct asm_writer* this, uint64_t val)
{
	ENTER;
	
	if (val >= UINT32_MAX)
	{
		asm_writer_write(this, "movq $%lu, %%r10", val);
		asm_writer_write(this, "movq %%r10, -8(%%rsp)");
	}
	else
	{
		asm_writer_write(this, "movq $%lu, -8(%%rsp)", val);
	}
	
	asm_writer_write(this, "sub $8, %%rsp");
	
	EXIT;
}
#endif
