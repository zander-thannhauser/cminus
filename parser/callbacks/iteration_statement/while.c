
#include <stddef.h>
#include <assert.h>

#include <memory/tfree.h>

#include <statement/while/new.h>

#include <parser/yylloc/new.h>

#include "while.h"

int iteration_statement_while_callback(
	struct statement** out,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* conditional,
	struct statement* body)
{
	int error = 0;
	struct yylloc* loc = NULL;
	ENTER;
	
	error = 0
		?: new_yyloc(&loc, first_line, first_column, last_line, last_column)
		?: new_while_statement(
			(struct while_statement**) out,
			loc, conditional, body);
	
	tfree(loc);
	tfree(conditional), tfree(body);
	
	EXIT;
	return error;
}

