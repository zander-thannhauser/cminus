
#include <stdio.h>

#include <assert.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <parser/expression_ll/new.h>
#include <parser/expression_ll/append.h>

#include "head.h"

int argument_expression_list_head_callback(
	struct expression_ll** retval,
	struct expression* expression)
{
	int error = 0;
	ENTER;
	
	struct expression_ll* new = NULL;
	
	error = 0
		?: new_expression_ll(&new)
		?: expression_ll_append(new, expression);
	
	if (!error)
		*retval = tinc(new);
	
	tfree(expression);
	tfree(new);
	
	EXIT;
	return error;
}

