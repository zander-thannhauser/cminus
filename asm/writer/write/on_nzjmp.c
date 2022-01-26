
#if 0
#include <debug.h>

#include <asm/tables/intregs.h>

#include "../write.h"

#include "on_nzjmp.h"

int asm_writer_write_on_nzjmp(
	struct asm_writer* this,
	enum integer_register_id rid, enum register_size rs,
	const char* label)
{
	int error = 0;
	ENTER;
	
	error = 0
		?: asm_writer_write(this, "cmp $0, %s", intregs[rid][rs])
		?: asm_writer_write(this, "jne .%s", label);
	
	EXIT;
	return error;
}

#endif
