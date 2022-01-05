
#if 0

#include <debug.h>

/*#include "../../tables/intregs.h"*/

#include "../write.h"

#include "pushg.h"

int asm_writer_write_pushg(
	struct asm_writer* this,
	const char* gname)
{
	int error = 0;
	ENTER;
	
	asm_writer_write(this,
		"pushq (%s@PLT)",
		gname);
	
	EXIT;
	return error;
}

#endif
