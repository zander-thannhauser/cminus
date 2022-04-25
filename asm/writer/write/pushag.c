
#if 0

#include <assert.h>

/*#include "../../tables/intregs.h"*/

#include "../write.h"

#include "pushag.h"

int asm_writer_write_pushag(
	struct asm_writer* this,
	const char* gname)
{
	int error = 0;
	ENTER;
	
	asm_writer_write(this,
		"pushq %s@PLT",
		gname);
	
	EXIT;
	return error;
}

#endif
