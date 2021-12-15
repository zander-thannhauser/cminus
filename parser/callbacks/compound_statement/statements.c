
#include <debug.h>

#include <memory/tfree.h>

#include <parser/statement_ll/new.h>
#include <parser/statement_ll/merge.h>

#include <statement/compound/new.h>

#include "statements.h"

int compound_statement_statements_callback(
	struct compound_statement** retval,
	unsigned line,
	struct statement_ll* declarations,
	struct statement_ll* statements)
{
	int error = 0;
	ENTER;
	
	if (!declarations)
		error = new_statement_ll(&declarations);
	
	if (!error && !statements)
		error = new_statement_ll(&statements);
	
	if (!error)
		error = statement_ll_merge(declarations, statements);
	
	if (!error)
		error = new_compound_statement(
			(struct compound_statement**) retval, line, declarations);
	
	tfree(declarations);
	tfree(statements);
	
	EXIT;
	return error;
}












