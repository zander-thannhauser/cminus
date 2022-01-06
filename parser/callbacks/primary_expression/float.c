
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
	
	TODO;
	#if 0
	error = new_literal_expression_as_float(
		(struct expression**) retval,
		types->floats[fk_float],
		floatlit);
	#endif
	
	EXIT;
	return error;
}

