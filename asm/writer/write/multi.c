
#include <debug.h>

#include <asm/tables/intregs.h>
#include <asm/tables/iktors.h>

#include "../write.h"

#include "multi.h"

int asm_writer_write_multi_v2(
	struct asm_writer* this,
	enum integer_register_id a,
	enum integer_register_id b,
	enum integer_kind ikind)
{
	ENTER;
	
	enum register_size rs = iktors[ikind];
	
	asm_writer_write(this,
		"%s %s, %s",
		((char*[]) {"imul", "mul"})[ikind & 1],
		intregs[a][rs],
		intregs[b][rs]);
	
	EXIT;
	return 0;
}

