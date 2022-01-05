
#include <debug.h>

#include "../../tables/fktors.h"
#include "../../tables/floatregs.h"
#include "../../tables/intregs.h"

/*#include "../../location/struct.h"*/
/*#include "../../location/write.h"*/

#include "../write.h"

#include "movf.h"

static const char* movf[number_of_float_kinds] = 
{
	[fk_float] = "movss",
	[fk_double] = "movsd",
};

int asm_writer_write_movf_to(
	struct asm_writer* this,
	/* from: */ ssize_t offset, enum integer_register_id iid,
	/* to:   */ enum float_register_id fid,
	enum float_kind fkind)
{
	int error = 0;
	ENTER;
	
	asm_writer_write(this,
		"%s %zi(%s), %s",
		movf[fkind],
		offset, intregs[iid][quadword],
		floatregs[fid]);
	
	EXIT;
	return error;
}

int asm_writer_write_movf_from(
	struct asm_writer* this,
	/* from: */ enum float_register_id fid,
	/* to:   */ ssize_t offset, enum integer_register_id iid,
	enum float_kind fkind)
{
	int error = 0;
	ENTER;
	
	asm_writer_write(this,
		"%s %s, %zi(%s)",
		movf[fkind],
		floatregs[fid],
		offset, intregs[iid][quadword]);
	
	EXIT;
	return error;
}

#if 0
static const char* mov_lookup[number_of_register_sizes] = 
{
	[doubleword] = "movl",
	[quadword] = "movq",
};

int asm_writer_write_movf(
	struct asm_writer* this,
	struct asm_location* src_loc, enum float_kind src_kind,
	struct asm_location* dst_loc, enum float_kind dst_kind)
{
	int error = 0;
	char src_buffer[30], dst_buffer[30];
	enum register_size src_size = fktors[src_kind], dst_size = fktors[dst_kind];
	ENTER;
	
	if (dst_size < src_size)
	{
		asm_writer_write(this,
			"cvtsd2ss %s, %s",
			write_asm_location(src_loc, src_size, src_buffer),
			write_asm_location(dst_loc, dst_size, dst_buffer));
	}
	else if (dst_size > src_size)
	{
		asm_writer_write(this,
			"cvtss2sd %s, %s",
			write_asm_location(src_loc, src_size, src_buffer),
			write_asm_location(dst_loc, dst_size, dst_buffer));
	}
	else if (src_loc->kind == al_register && dst_loc->kind == al_float_register)
	{
		const char* m1 = mov_lookup[src_size], *m2 = movf_lookup[dst_kind];
		
		asm_writer_write(this,
			"%s %s, -8(%%rsp)",
			m1,
			write_asm_location(src_loc, src_size, src_buffer));
			
		asm_writer_write(this,
			"%s -8(%%rsp), %s",
			m2,
			write_asm_location(dst_loc, dst_size, dst_buffer));
	} 
	else if (src_loc->kind == al_float_register && dst_loc->kind == al_register)
	{
		const char* m1 = movf_lookup[src_kind], *m2 = mov_lookup[dst_size];
		
		asm_writer_write(this,
			"%s %s, -8(%%rsp)",
			m1,
			write_asm_location(src_loc, src_size, src_buffer));
			
		asm_writer_write(this,
			"%s -8(%%rsp), %s",
			m2,
			write_asm_location(dst_loc, dst_size, dst_buffer));
	}
	else if (src_loc->kind == al_offset && dst_loc->kind == al_register)
	{
		// moss doesn't like it when both are registers
		// so we need to switch to the integer mov for this:
		asm_writer_write(this,
			"%s %s, %s",
			mov_lookup[src_size],
			write_asm_location(src_loc, src_size, src_buffer),
			write_asm_location(dst_loc, dst_size, dst_buffer));
	}
	else if (src_loc->kind == al_register && dst_loc->kind == al_deref_register)
	{
		// moss doesn't like it when both are registers
		// so we need to switch to the integer mov for this:
		asm_writer_write(this,
			"%s %s, %s",
			mov_lookup[src_size],
			write_asm_location(src_loc, src_size, src_buffer),
			write_asm_location(dst_loc, dst_size, dst_buffer));
	}
	else
	{
		
		// same size: just copy:
		asm_writer_write(this,
			"%s %s, %s",
			movf_lookup[src_kind],
			write_asm_location(src_loc, src_size, src_buffer),
			write_asm_location(dst_loc, dst_size, dst_buffer));
	}
	
	EXIT;
	return error;
}










#endif
