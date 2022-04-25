
#include <stddef.h>

#include <assert.h>

#include <memory/tfree.h>

#include <expression/parentheses/new.h>

#include <parser/yylloc/new.h>

#include <types/struct.h>

#include "parentheses.h"

int primary_expression_parentheses_callback(
	struct expression** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* inner)
{
	int error = 0;
	struct yylloc* loc = NULL;
	ENTER;
	
	error = 0
		?: new_yyloc(&loc, first_line, first_column, last_line, last_column)
		?: new_parentheses_expression((struct expression**) retval, loc, inner);
	
	tfree(inner);
	tfree(loc);
	
	EXIT;
	return error;
}

