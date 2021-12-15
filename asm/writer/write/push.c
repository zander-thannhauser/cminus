
#include <debug.h>

#include "../../tables/intregs.h"

#include "../write.h"

#include "push.h"

int asm_writer_write_push(
	struct asm_writer* this,
	enum integer_register_id rid)
{
	int error = 0;
	ENTER;
	
	asm_writer_write(this, "pushq %s", intregs[rid][quadword]);
	
	EXIT;
	return error;
}

