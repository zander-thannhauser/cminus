
#include <stdio.h>

#include <debug.h>

#include <memory/tfree.h>

#include <parser/expression_ll/new.h>

#include <expression/function_call/new.h>

#include "empty_function_call.h"

int postfix_expression_empty_function_call_callback(
	struct expression** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* function_expression)
{
	int error = 0;
	struct expression_ll* expressions = NULL;
	ENTER;
	
	error = 0
		?: new_expression_ll(&expressions)
		?: new_function_call_expression(
			(struct function_call_expression**) new,
			first_line, first_column,
			last_line, last_column,
			function_expression, expressions);
	
	tfree(function_expression);
	tfree(expressions);
	
	EXIT;
	return error;
}












