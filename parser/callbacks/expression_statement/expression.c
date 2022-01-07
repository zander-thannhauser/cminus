
#include <stddef.h>
#include <debug.h>

#include <memory/tfree.h>

#include <statement/expression/new.h>

#include <parser/yylloc/new.h>

#include "expression.h"

int expression_statement_expression_callback(
	struct statement** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* expression)
{
	int error = 0;
	struct yylloc* loc = NULL;
	ENTER;
	
	error = 0
		?: new_yyloc(&loc, first_line, first_column, last_line, last_column)
		?: new_expression_statement(retval, loc, expression);
	
	tfree(loc);
	tfree(expression);
	
	EXIT;
	return error;
};

