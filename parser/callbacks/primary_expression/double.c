
#include <debug.h>

#include <types/struct.h>

#include <expression/literal/new.h>

#include "double.h"

int primary_expression_double_callback(
	struct expression** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct types* types,
	double doublelit)
{
	int error = 0;
	ENTER;
	
	dpv(doublelit);
	
	error = new_literal_expression_as_double(
		(struct expression**) retval,
		first_line, first_column,
		last_line, last_column,
		types->floats[fk_double],
		doublelit);
	
	EXIT;
	return error;
}

