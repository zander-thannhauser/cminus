
#include <debug.h>

#include <expression/write_rasm.h>

#include "struct.h"
#include "write_rasm.h"

int parentheses_expression_write_rasm(struct expression* super, struct asm_writer* writer)
{
	int error = 0;
	struct parentheses_expression* const this = (typeof(this)) super;
	ENTER;
	
	TODO;
	
	EXIT;
	return error;
}







