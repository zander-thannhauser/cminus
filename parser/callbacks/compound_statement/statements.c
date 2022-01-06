
#include <stddef.h>
#include <debug.h>

#include <memory/tfree.h>

#include <parser/statement_ll/new.h>
#include <parser/statement_ll/merge.h>

#include <statement/compound/new.h>

#include <parser/yylloc/new.h>

#include "statements.h"

int compound_statement_statements_callback(
	struct compound_statement** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct statement_ll* declarations,
	struct statement_ll* statements)
{
	int error = 0;
	struct yylloc* loc = NULL;
	ENTER;
	
	if (!declarations)
		error = new_statement_ll(&declarations);
	
	if (!error && !statements)
		error = new_statement_ll(&statements);
	
	if (!error)
	{
		error = 0
			?: statement_ll_merge(declarations, statements)
			?: new_yyloc(&loc, first_line, first_column, last_line, last_column)
			?: new_compound_statement(
				(struct compound_statement**) retval, loc, declarations);
	}
	
	tfree(loc);
	tfree(declarations);
	tfree(statements);
	
	EXIT;
	return error;
}













