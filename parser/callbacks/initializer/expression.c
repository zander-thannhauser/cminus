
#include <stddef.h>

#include <debug.h>

#include <memory/tfree.h>

#include <parser/yylloc/new.h>

#include <parser/initializer/new.h>

#include "expression.h"

int initializer_expression_callback(
	struct initializer** out,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* expression)
{
	int error = 0;
	struct yylloc* loc = NULL;
	ENTER;
	
	error = 0
		?: new_yyloc(&loc, first_line, first_column, last_line, last_column)
		?: new_initializer_as_expression(out, loc, expression);
	
	tfree(loc);
	
	tfree(expression);
	
	EXIT;
	return error;
}

