

#include <assert.h>

#include <assert.h>

#include "../../tables/intregs.h"
#include "../../tables/floatregs.h"

#include "../write.h"

#include "chfloat.h"

static const char* lookup[number_of_float_kinds][number_of_float_kinds] = {
	[fk_double][fk_float]  = "cvtsd2ss",
	[fk_float] [fk_double] = "cvtss2sd",
};

void asm_writer_write_chfloat(
	struct asm_writer* this,
	ssize_t src_off, enum integer_register_id src_relto, enum float_kind src_kind,
	enum float_register_id dst_rid, enum float_kind dst_kind)
{
	ENTER;
	
	assert(src_kind != dst_kind);
	
	asm_writer_write(this,
		"%s %zi(%s), %s",
		lookup[src_kind][dst_kind],
		src_off, intregs[src_relto][quadword],
		floatregs[dst_rid]);
	
	EXIT;
}


