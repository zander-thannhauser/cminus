
#include <stdio.h>

#include <assert.h>

#include <memory/tfree.h>

#include <parser/parameter_ll/new.h>

#include <parser/ptree/declarator/function/new.h>

#include "function.h"

int direct_declarator_function_callback(
	struct declarator** new,
	struct declarator* inner)
{
	int error = 0;
	ENTER;
	
	struct parameter_ll* parameters = NULL;
	
	error = 0
		?: new_parameter_ll(&parameters)
		?: new_function_declarator(
			(struct function_declarator**) new, inner, parameters);
	
	tfree(parameters);
	tfree(inner);
	
	EXIT;
	return error;
}

