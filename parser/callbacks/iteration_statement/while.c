
#include <debug.h>

#include <memory/tfree.h>

#include <statement/while/new.h>

#include "while.h"

int iteration_statement_while_callback(
	struct statement** out,
	struct expression* conditional,
	struct statement* body,
	struct types* types)
{
	int error = 0;
	ENTER;
	
	error = new_while_statement(
		(struct while_statement**) out,
		conditional, body, types);
	
	tfree(conditional), tfree(body);
	
	EXIT;
	return error;
}

