
#include <debug.h>

#include <memory/tfree.h>

#include <statement/expression/new.h>

#include "expression.h"

int expression_statement_expression_callback(
	struct statement** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* expression)
{
	int error = 0;
	ENTER;
	
	error = new_expression_statement(
		(struct expression_statement**) retval, 
		first_line, first_column,
		last_line, last_column,
		expression);
	
	tfree(expression);
	
	EXIT;
	return error;
};

