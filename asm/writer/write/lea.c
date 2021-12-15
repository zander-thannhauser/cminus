
#include <debug.h>

#include "../../enums/register_size.h"
#include "../../tables/intregs.h"
#include "../../location/write.h"
#include "../write.h"

#include "lea.h"

int asm_writer_write_lea(
	struct asm_writer* this,
	struct asm_location* src_loc,
	enum integer_register_id rid)
{
	int error = 0;
	char src_buffer[30];
	ENTER;
	
	// same size: just copy:
	asm_writer_write(this,
		"lea %s, %s",
		write_asm_location(src_loc, quadword, src_buffer),
		intregs[rid][quadword]);
	
	EXIT;
	return error;
}














