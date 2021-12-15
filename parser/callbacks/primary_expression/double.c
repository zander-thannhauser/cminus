
#include <debug.h>

#include <types/struct.h>

#include <expression/literal/new.h>

#include "double.h"

int primary_expression_double_callback(
	struct expression** retval,
	struct types* types,
	double doublelit)
{
	int error = 0;
	ENTER;
	
	TODO;
	#if 0
	dpv(doublelit);
	
	error = new_literal_expression_as_double(
		(struct expression**) retval,
		types->primitives[pk_double],
		doublelit);
	#endif
	
	EXIT;
	return error;
}

