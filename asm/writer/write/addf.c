
#if 0
#include <debug.h>

#include "../../tables/floatregs.h"

#include "../../tables/fktors.h"

/*#include "../../location/write.h"*/

#include "../write.h"

#include "addf.h"

static const char* lookup[number_of_float_kinds] = {
	[fk_float] = "addss",
	[fk_double] = "addsd",
};

int asm_writer_write_addf(
	struct asm_writer* this,
	enum float_register_id fid1,
	enum float_register_id fid2,
	enum float_kind result_kind)
{
	int error = 0;
/*	char src_buffer[30], dst_buffer[30];*/
/*	enum register_size rs = fktors[result_kind];*/
	ENTER;
	
	asm_writer_write(this, "%s %s, %s",
		lookup[result_kind],
		floatregs[fid1],
		floatregs[fid2]);
	
	EXIT;
	return error;
}










#endif
