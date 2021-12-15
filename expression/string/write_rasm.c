
#include <stdio.h>

#include <debug.h>

#include <asm/location/struct.h>
/*#include <asm/writer/comment.h>*/
#include <asm/writer/write/lea.h>
#include <asm/writer/write/push.h>

#include "struct.h"
#include "write_rasm.h"

int string_expression_write_rasm(
	struct expression* super, struct asm_writer* writer)
{
	int error = 0;
	struct string_expression* const this = (typeof(this)) super;
	ENTER;
	
	asm_writer_write_lea(writer,
		ASMSTR(this->string_id),
		working_1);
	
	asm_writer_write_push(writer,
		working_1);
	
	EXIT;
	return error;
}

