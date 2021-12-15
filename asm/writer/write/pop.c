
#include <debug.h>

#include "../../tables/intregs.h"

#include "../write.h"

#include "pop.h"

int asm_writer_write_pop(
	struct asm_writer* this,
	enum integer_register_id rid)
{
	int error = 0;
	ENTER;
	
	asm_writer_write(this, "popq %s", intregs[rid][quadword]);
	
	EXIT;
	return error;
}

