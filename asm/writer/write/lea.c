
#include <assert.h>

#include "../../enums/register_size.h"
#include "../../tables/intregs.h"
/*#include "../../location/write.h"*/
#include "../write.h"

#include "lea.h"

int asm_writer_write_lea(
	struct asm_writer* this,
	ssize_t offset, enum integer_register_id relto,
	enum integer_register_id rid)
{
	int error = 0;
/*	char src_buffer[30];*/
	ENTER;
	
	// same size: just copy:
	asm_writer_write(this,
		"lea %zi(%s), %s",
		offset, intregs[relto][quadword],
		intregs[rid][quadword]);
	
	EXIT;
	return error;
}














