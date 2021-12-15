
#include <debug.h>

#include <memory/tfree.h>

#include <type/struct.h>

#include <expression/struct.h>
#include <expression/function_call/new.h>

#include "function_call.h"

int postfix_expression_function_call_callback(
	struct expression** retval,
	struct expression* function_expression,
	struct expression_ll* expressions,
	struct types* types)
{
	int error = 0;
	ENTER;
	
	if (function_expression->type->kind != tk_function)
	{
		TODO;
		error = 1;
	}
	else error = new_function_call_expression(
		(struct function_call_expression**) retval,
		function_expression, expressions, types);
	
	tfree(function_expression);
	tfree(expressions);
	
	EXIT;
	return error;
}

