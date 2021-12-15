
#include <debug.h>

#include <memory/tfree.h>

#include <statement/return/new.h>

#include "return.h"

int jump_statement_return_callback(
	struct statement** out,
	unsigned line,
	struct expression* expression)
{
	int error = 0;
	ENTER;
	
	error = new_return_statement(
		(struct return_statement**) out, line, expression);
	
	tfree(expression);
	
	EXIT;
	return error;
}

