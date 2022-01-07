
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

int asm_writer_write_movf_between(
	struct asm_writer* this,
	/* from: */ enum float_register_id src,
	/* to:   */ enum float_register_id dst,
	enum float_kind fkind)
{
	int error = 0;
	ENTER;
	
	asm_writer_write(this,
		"%s %s, %s",
		movf[fkind],
		floatregs[src],
		floatregs[dst]);
	
	EXIT;
	return error;
}

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







