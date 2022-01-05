
#include <debug.h>

#include <type/float/kind.h>

#include "../../tables/floatregs.h"
#include "../../tables/intregs.h"
#include "../../tables/iktors.h"

#include "../write.h"

#include "ftoi.h"

static const char* lookup[number_of_float_kinds][2] = {
	[fk_float ][0] =  "cvtss2si",
	[fk_float ][1] = "vcvtss2usi",
	[fk_double][0] =  "cvtsd2si",
	[fk_double][1] = "vcvtsd2usi",
};

void asm_writer_write_ftoi(
	struct asm_writer* this,
	ssize_t src_offset, enum integer_register_id src_relto, enum float_kind src_kind,
	enum integer_register_id dst, enum integer_kind dst_kind)
{
	ENTER;
	
	asm_writer_write(this,
		"%s %zi(%s), %s",
		lookup[src_kind][dst_kind & 1],
		src_offset, intregs[src_relto][quadword],
		intregs[dst][quadword]);
	
	EXIT;
}














