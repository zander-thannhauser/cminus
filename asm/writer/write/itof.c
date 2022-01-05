
#include <debug.h>

#include "../../tables/intregs.h"
#include "../../tables/floatregs.h"

#include "../write.h"

#include "itof.h"

static const char* const lookup[2][number_of_float_kinds] = {
	[0][fk_float ] =    "cvt"   "si2s""s",
	[1][fk_float ] = "v""cvt""u""si2s""s",
	[0][fk_double] =    "cvt"   "si2s""d",
	[1][fk_double] = "v""cvt""u""si2s""d",
};

void asm_writer_write_itof(
	struct asm_writer* this,
	ssize_t src_offset, enum integer_register_id src_relto, enum integer_kind src_kind,
	enum float_register_id dest, enum float_kind dest_kind)
{
	ENTER;
	
	// can't refer to the memory location directly,
	// first mov the memory into a register of the right size,
	// then convert the "long" into float/double.
	TODO;
	
	asm_writer_write(this,
		"%s %zi(%s), %s",
		lookup[src_kind & 1][dest_kind],
		src_offset, intregs[src_relto][quadword],
		floatregs[dest]);
	
	EXIT;
}

