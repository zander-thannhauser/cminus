
#include <stdio.h>

#include <assert.h>

#include <memory/tfree.h>

#include <parser/expression_ll/new.h>

#include <expression/function_call/new.h>

#include <parser/yylloc/new.h>

#include "empty_function_call.h"

int postfix_expression_empty_function_call_callback(
	struct expression** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* function_expression)
{
	int error = 0;
	struct yylloc* loc = NULL;
	struct expression_ll* expressions = NULL;
	ENTER;
	
	error = 0
		?: new_yyloc(&loc,
			first_line, first_column,
			last_line, last_column)
		?: new_expression_ll(&expressions)
		?: new_function_call_expression(
			(struct function_call_expression**) new,
			loc, function_expression, expressions);
	
	tfree(function_expression);
	tfree(expressions);
	tfree(loc);
	
	EXIT;
	return error;
}












