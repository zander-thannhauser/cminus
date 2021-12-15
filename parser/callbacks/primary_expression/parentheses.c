
#include <debug.h>

#include <expression/parentheses/new.h>
#include <expression/free.h>

#include <types/struct.h>

#include "parentheses.h"

int primary_expression_parentheses_callback(
	struct expression** retval,
	struct expression* inner)
{
	int error = 0;
	ENTER;
	
	error = new_parentheses_expression(
		(struct expression**) retval,
		inner);
	
	free_expression(inner);
	
	EXIT;
	return error;
}

