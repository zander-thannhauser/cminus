
#include <debug.h>

#include <types/struct.h>

#include <expression/literal/new.h>

#include "float.h"

int primary_expression_float_callback(
	struct expression** retval,
	struct types* types,
	float floatlit)
{
	int error = 0;
	ENTER;
	
	dpv(floatlit);
	
	error = new_literal_expression_as_double(
		(struct expression**) retval,
		types->floats[fk_float],
		floatlit);
	
	EXIT;
	return error;
}

