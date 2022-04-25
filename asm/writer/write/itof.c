
#include <assert.h>

#include "../../tables/iktors.h"
#include "../../tables/intregs.h"
#include "../../tables/floatregs.h"

#include "../write.h"

#include "movi.h"
#include "movsx.h"
#include "itof.h"

static const char* const lookup[2][number_of_float_kinds] = {
	[0][fk_float ] =  "cvtsi2ss",
	[1][fk_float ] = "vcvtusi2ss",
	[0][fk_double] =  "cvtsi2sd",
	[1][fk_double] = "vcvtusi2sd",
};

void asm_writer_write_itof(
	struct asm_writer* this,
	ssize_t src_offset, enum integer_register_id src_relto, enum integer_kind src_kind,
	enum float_register_id dest, enum float_kind dest_kind)
{
	ENTER;
	enum register_size irs = iktors[src_kind];
	
	if (irs < quadword)
	{
		// can't refer to the memory location directly,
		// first mov the memory into a register of the right size,
		// then convert the "long" into float/double.
		
		asm_writer_write_movi_to_v2(this,
			src_offset, src_relto, working_1, irs);
		
		if (src_kind & 1)
		{
			TODO;
			#if 0
			asm_writer_write_movz(
				this,
				working_1, irs,
				working_2, quadword);
			#endif
		}
		else
		{
			asm_writer_write_movsx(
				this,
				working_1, irs,
				working_2, quadword);
		}
		
		asm_writer_write(this,
			"%s %s, %s",
			lookup[src_kind & 1][dest_kind],
			intregs[working_2][quadword],
			floatregs[dest]);
	}
	else
	{
		asm_writer_write(this,
			"%s %zi(%s), %s",
			lookup[src_kind & 1][dest_kind],
			src_offset, intregs[src_relto][quadword],
			floatregs[dest]);
	}
	
	EXIT;
}
















