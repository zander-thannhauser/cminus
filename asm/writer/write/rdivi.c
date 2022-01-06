
#include <debug.h>

#include <asm/tables/intregs.h>
#include <asm/tables/iktors.h>

#include "../write.h"

#include "movi.h"
#include "rdivi.h"

int asm_writer_write_rdivi(
	struct asm_writer* this,
	enum integer_register_id numerator_reg,
	enum integer_register_id denominator_reg,
	enum integer_kind ikind)
{
	ENTER;
	
	enum register_size rs = iktors[ikind];
	
	asm_writer_write_movi_between_v2(this, numerator_reg, divn_reg, rs);
	if (rs > byte)
	{
		asm_writer_write_movi_const_v2(this, 0, divr_reg, rs);
	}
	
	asm_writer_write(this,
		"%s %s",
		((char*[]) {"idiv", "div"})[ikind & 1],
		intregs[denominator_reg][rs]);
	
	EXIT;
	return 0;
}

