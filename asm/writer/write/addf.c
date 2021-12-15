
#include <debug.h>

/*#include "../../tables/intregs.h"*/

#include "../../tables/fktors.h"

#include "../../location/write.h"

#include "../write.h"

#include "addf.h"

static const char* lookup[number_of_float_kinds] = {
	[fk_float] = "addss",
	[fk_double] = "addsd",
};

int asm_writer_write_addf(
	struct asm_writer* this,
	struct asm_location* src_loc,
	struct asm_location* dst_loc,
	enum float_kind result_kind)
{
	int error = 0;
	char src_buffer[30], dst_buffer[30];
	enum register_size rs = fktors[result_kind];
	ENTER;
	
	asm_writer_write(this, "%s %s, %s",
		lookup[result_kind],
		write_asm_location(src_loc, rs, src_buffer),
		write_asm_location(dst_loc, rs, dst_buffer));
	
	EXIT;
	return error;
}











