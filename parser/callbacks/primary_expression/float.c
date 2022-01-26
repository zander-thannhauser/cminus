
#include <debug.h>

#include <memory/tfree.h>

#include <types/struct.h>

#include <expression/literal/new.h>

#include <parser/yylloc/new.h>

#include "float.h"

int primary_expression_float_callback(
	struct expression** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct types* types,
	float floatlit)
{
	int error = 0;
	struct yylloc* loc = NULL;
	ENTER;
	
	dpv(floatlit);
	
	TODO;
	#if 0
	error = 0
		?: new_yyloc(&loc,
			first_line, first_column,
			last_line, last_column)
		?: new_literal_expression_as_float(
			(struct expression**) retval,
			loc,
			types->floats[fk_float],
			floatlit);
	#endif
	
	tfree(loc);
	
	EXIT;
	return error;
}

