
#include <debug.h>

#include <asm/tables/intregs.h>

#include "../write.h"

#include "on_zjmp.h"

void asm_writer_write_on_zjmp(
	struct asm_writer* this,
	enum integer_register_id rid, enum register_size rs,
	const char* label)
{
	ENTER;
	
	asm_writer_write(this, "cmp $0, %s", intregs[rid][rs]);
	
	asm_writer_write(this, "je .%s", label);
	
	EXIT;
}

