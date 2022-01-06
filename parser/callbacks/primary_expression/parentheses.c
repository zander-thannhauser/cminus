
#include <debug.h>

#include <expression/parentheses/new.h>
#include <expression/free.h>

#include <types/struct.h>

#include "parentheses.h"

int primary_expression_parentheses_callback(
	struct expression** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* inner)
{
	int error = 0;
	ENTER;
	
	error = new_parentheses_expression(
		(struct expression**) retval,
		first_line, first_column,
		last_line, last_column,
		inner);
	
	free_expression(inner);
	
	EXIT;
	return error;
}

