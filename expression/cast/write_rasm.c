
#include <debug.h>

/*#include <asm/tables/pktors.h>*/

/*#include <type/primitive/struct.h>*/

#include <expression/write_rasm.h>

#include "struct.h"
#include "write_rasm.h"

int cast_expression_write_rasm(struct expression* super, struct asm_writer* writer)
{
	int error = 0;
	struct cast_expression* const this = (typeof(this)) super;
	struct type* const bt = this->inner->type;
	struct type* const at = this->type;
	struct primitive_type* const pbt = (typeof(pbt)) bt;
	struct primitive_type* const pat = (typeof(pat)) at;
	ENTER;
	
	TODO;
	#if 0
	error = expression_write_rasm(this->inner, writer);
	
	// checked in 'new()':
	assert(at->kind == tk_primitive || at->kind == tk_pointer);
	assert(bt->kind == tk_primitive || bt->kind == tk_pointer);
	
	enum primitive_kind const bk = (bt->kind == tk_pointer) ? pk_unsigned_long : pbt->kind;
	enum primitive_kind const ak = (at->kind == tk_pointer) ? pk_unsigned_long : pat->kind;
	
	const enum register_size brs = pktors[bk], ars = pktors[ak];
	
	if (bk == ak) { // same type?
		HERE;
	} else if (bk == pk_float && ak == pk_double) { // float -> double?
		TODO;
	} else if (bk == pk_double && ak == pk_float) { // double -> float?
		TODO;
	} else if (bk == pk_float) { // float -> *?
		TODO;
	} else if (bk == pk_double) { // double -> *?
		TODO;
	} else if (ak == pk_float) { // * -> float?
		TODO;
	} else if (ak == pk_double) { // * -> double?
		TODO;
	} else if (brs == ars) { // are register sizes equal?
		TODO;
	} else if (ars > brs) { // is after larger than before?
		// mov with zeros
		TODO;
	} else {
		// truncate
		TODO;
	}
	#endif
	
	EXIT;
	return error;
}










