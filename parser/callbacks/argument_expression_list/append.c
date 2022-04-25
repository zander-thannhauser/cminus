
#include <stdio.h>

#include <assert.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <parser/expression_ll/new.h>
#include <parser/expression_ll/append.h>

#include "append.h"

int argument_expression_list_append_callback(
	struct expression_ll** retval,
	struct expression_ll* list,
	struct expression* expression)
{
	int error = 0;
	ENTER;
	
	error = expression_ll_append(list, expression);
	
	if (!error)
		*retval = tinc(list);
	
	tfree(list);
	tfree(expression);
	
	EXIT;
	return error;
}

