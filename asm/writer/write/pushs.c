
#if 0

#include <debug.h>

/*#include "../../tables/intregs.h"*/

#include "../write.h"

#include "pushs.h"

int asm_writer_write_pushs(
	struct asm_writer* this,
	size_t string_id)
{
	int error = 0;
	ENTER;
	
	asm_writer_write(this, "leaq string_%zu(%%rip), %%r10", string_id);
	asm_writer_write(this, "movq %%r10, -8(%%rsp)");
	asm_writer_write(this, "subq $8, %%rsp");
	
	EXIT;
	return error;
}

#endif
