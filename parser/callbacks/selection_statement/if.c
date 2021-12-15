
#include <debug.h>

#include <memory/tfree.h>

#include <statement/if/new.h>

#include "if.h"

int selection_statement_if_callback(
	struct statement** out,
	struct expression* conditional,
	struct statement* true_case,
	struct statement* false_case,
	struct types* types)
{
	int error = 0;
	ENTER;
	
	error = new_if_statement(
		(struct if_statement**) out,
		conditional, true_case, false_case, types);
	
	tfree(conditional);
	tfree(true_case), tfree(false_case);
	
	EXIT;
	return error;
}

