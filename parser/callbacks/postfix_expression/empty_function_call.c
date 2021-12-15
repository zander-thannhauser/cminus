
#include <stdio.h>

#include <debug.h>

#include <memory/tfree.h>

#include <parser/expression_ll/new.h>

#include <expression/function_call/new.h>

#include "empty_function_call.h"

int postfix_expression_empty_function_call_callback(
	struct expression** new,
	struct expression* function_expression,
	struct types* types)
{
	int error = 0;
	struct expression_ll* expressions = NULL;
	ENTER;
	
	error = 0
		?: new_expression_ll(&expressions)
		?: new_function_call_expression(
			(struct function_call_expression**) new,
			function_expression, expressions, types);
	
	tfree(function_expression);
	tfree(expressions);
	
	
	EXIT;
	return error;
}

