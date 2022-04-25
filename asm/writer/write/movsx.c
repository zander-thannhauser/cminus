
#include <assert.h>

#include <asm/tables/intregs.h>

#include "../write.h"

#include "movsx.h"

int asm_writer_write_movsx(
	struct asm_writer* this,
	enum integer_register_id src, enum register_size src_rs,
	enum integer_register_id dst, enum register_size dst_rs)
{
	ENTER;
	
	asm_writer_write(this,
		"movsx %s, %s",
		intregs[src][src_rs],
		intregs[dst][dst_rs]);
	
	EXIT;
	return 0;
}

