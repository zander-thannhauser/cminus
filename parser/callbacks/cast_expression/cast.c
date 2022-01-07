
#include <debug.h>

#include <expression/cast/new.h>

#include <parser/yylloc/new.h>

#include "cast.h"

int cast_expression_cast_callback(
	struct expression** out,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct type* type,
	struct expression* inner)
{
	int error = 0;
	struct yylloc* loc = NULL;
	ENTER;
	
	error = 0
		?: new_yyloc(&loc, first_line, first_column, last_line, last_column)
		?: new_cast_expression(out, loc, type, inner);
	
	tfree(loc);
	tfree(type);
	tfree(inner);
	
	EXIT;
	return error;
}

