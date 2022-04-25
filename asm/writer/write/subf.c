
#include <assert.h>

#include "../../tables/floatregs.h"
/*#include "../../tables/fktors.h"*/

/*#include "../../location/write.h"*/

#include "../write.h"

#include "movf.h"
#include "addf.h"

static const char* lookup[number_of_float_kinds] = {
	[fk_float ] = "subss",
	[fk_double] = "subsd",
};

int asm_writer_write_subf(
	struct asm_writer* this,
	enum float_register_id a,
	enum float_register_id b,
	enum float_register_id q,
	enum float_kind result_kind)
{
	int error = 0;
	ENTER;
	
	asm_writer_write(this, "%s %s, %s",
		lookup[result_kind],
		floatregs[b],
		floatregs[a]);
	
	if (a != q)
		asm_writer_write_movf_between(this, a, q, result_kind);
	
	EXIT;
	return error;
}











