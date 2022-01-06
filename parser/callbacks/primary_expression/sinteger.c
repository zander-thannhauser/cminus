
#include <debug.h>

#include <expression/literal/new.h>

#include <types/struct.h>

#include "sinteger.h"

int primary_expression_sinteger_callback(
	struct expression** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct types* types,
	signed int sintegerlit)
{
	int error = 0;
	ENTER;
	
	error = new_literal_expression_as_signed_int(
		(struct expression**) retval,
		first_line, first_column,
		last_line, last_column,
		types->integers[ik_signed_int],
		sintegerlit);
	
	EXIT;
	return error;
}

