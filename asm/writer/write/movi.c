
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

int asm_writer_write_movi_const_v2(
	struct asm_writer* this,
	uint64_t val,
	enum integer_register_id dst_id,
	enum register_size rs)
{
	int error = 0;
	ENTER;
	
	asm_writer_write(this,
		"%s $%lu, %s",
		mov[rs],
		val,
		intregs[dst_id][rs]);
	
	EXIT;
	return error;
}

int asm_writer_write_movi_between_v2(
	struct asm_writer* this,
	enum integer_register_id src_id,
	enum integer_register_id dst_id,
	enum register_size rs)
{
	int error = 0;
	ENTER;
	
	asm_writer_write(this,
		"%s %s, %s",
		mov[rs],
		intregs[src_id][rs],
		intregs[dst_id][rs]);
	
	EXIT;
	return error;
}

int asm_writer_write_movi_to_v2(
	struct asm_writer* this,
	/* from: */ ssize_t offset, enum integer_register_id srcid,
	/* to:   */ enum integer_register_id dstid,
	enum register_size rs)
{
	int error = 0;
	ENTER;
	
	asm_writer_write(this,
		"%s %zi(%s), %s",
		mov[rs],
		offset, intregs[srcid][quadword],
		intregs[dstid][rs]);
	
	EXIT;
	return error;
}

int asm_writer_write_movi_from_v2(
	struct asm_writer* this,
	/* from: */ enum integer_register_id srcid,
	/* to:   */ ssize_t offset, enum integer_register_id dstid,
	enum register_size rs)
{
	int error = 0;
	ENTER;
	
	asm_writer_write(this,
		"%s %s, %zi(%s)",
		mov[rs],
		intregs[srcid][rs],
		offset, intregs[dstid][quadword]);
	
	EXIT;
	return error;
}

