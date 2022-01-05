
#include <debug.h>

#include "../../enums/register_size.h"
#include "../../tables/iktors.h"
#include "../../tables/intregs.h"
/*#include "../../location/write.h"*/
#include "../write.h"

#include "movi.h"

static const char* mov[number_of_register_sizes] = 
{
	[byte] = "movb",
	[word] = "mov",
	[doubleword] = "movl",
	[quadword] = "movq",
};

int asm_writer_write_movi_between(
	struct asm_writer* this,
	enum integer_register_id src_id,
	enum integer_register_id dst_id,
	enum integer_kind ikind)
{
	int error = 0;
	ENTER;
	
	enum register_size rs = iktors[ikind];
	
	asm_writer_write(this,
		"%s %s, %s",
		mov[rs],
		intregs[src_id][rs],
		intregs[dst_id][rs]);
	
	EXIT;
	return error;
}

int asm_writer_write_movi_to(
	struct asm_writer* this,
	/* from: */ ssize_t offset, enum integer_register_id srcid,
	/* to:   */ enum integer_register_id dstid,
	enum integer_kind ikind)
{
	int error = 0;
	ENTER;
	
	enum register_size rs = iktors[ikind];
	
	asm_writer_write(this,
		"%s %zi(%s), %s",
		mov[rs],
		offset, intregs[srcid][quadword],
		intregs[dstid][rs]);
	
	EXIT;
	return error;
}

int asm_writer_write_movi_from(
	struct asm_writer* this,
	/* from: */ enum integer_register_id srcid,
	/* to:   */ ssize_t offset, enum integer_register_id dstid,
	enum integer_kind ikind)
{
	int error = 0;
	ENTER;
	
	enum register_size rs = iktors[ikind];
	
	asm_writer_write(this,
		"%s %s, %zi(%s)",
		mov[rs],
		intregs[srcid][rs],
		offset, intregs[dstid][quadword]);
	
	EXIT;
	return error;
}


#if 0
int asm_writer_write_mov(
	struct asm_writer* this,
	struct asm_location* src_loc, enum integer_kind src_kind,
	struct asm_location* dst_loc, enum integer_kind dst_kind)
{
	int error = 0;
	char src_buffer[30], dst_buffer[30];
	enum register_size src_size = iktors[src_kind], dst_size = iktors[dst_kind];
	ENTER;
	
	if (dst_size < src_size)
	{
		TODO; // truncate?
	}
	else if (dst_size > src_size)
	{
		TODO; // promotion?
	}
	else
	{
		// same size: just copy:
		asm_writer_write(this,
			"%s %s, %s",
			mov_lookup[dst_size],
			write_asm_location(src_loc, src_size, src_buffer),
			write_asm_location(dst_loc, dst_size, dst_buffer));
	}
	
	EXIT;
	return error;
}













#endif
