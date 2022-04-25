
#include <stddef.h>
#include <assert.h>

#include <memory/tfree.h>

#include <statement/if/new.h>

#include <parser/yylloc/new.h>

#include "if.h"

int selection_statement_if_callback(
	struct statement** out,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* conditional,
	struct statement* true_case,
	struct statement* false_case)
{
	int error = 0;
	struct yylloc* loc = NULL;
	ENTER;
	
	error = 0
		?: new_yyloc(&loc, first_line, first_column, last_line, last_column)
		?: new_if_statement(
			(struct if_statement**) out,
			loc, conditional, true_case, false_case);
	
	tfree(loc);
	tfree(conditional);
	tfree(true_case), tfree(false_case);
	
	EXIT;
	return error;
}

