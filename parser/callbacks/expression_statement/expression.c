
#include <debug.h>

#include <memory/tfree.h>

#include <statement/expression/new.h>

#include "expression.h"

int expression_statement_expression_callback(
	struct statement** retval,
	unsigned line,
	struct expression* expression)
{
	int error = 0;
	ENTER;
	
	error = new_expression_statement(
		(struct expression_statement**) retval, line, expression);
	
	tfree(expression);
	
	EXIT;
	return error;
};

