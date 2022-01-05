
#include <stdio.h>

#include <debug.h>

/*#include <asm/location/struct.h>*/
/*#include <asm/writer/comment.h>*/
#include <asm/writer/indent.h>
/*#include <asm/writer/write/lea.h>*/
#include <asm/writer/write/pushs.h>

#include "struct.h"
#include "write_rasm.h"

int string_expression_write_rasm(
	struct expression* super, struct asm_writer* writer)
{
	int error = 0;
	struct string_expression* const this = (typeof(this)) super;
	ENTER;
	
	asm_writer_write_pushs(writer, this->string_id);
	
	EXIT;
	return error;
}

