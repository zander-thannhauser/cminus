
#include <assert.h>

#include <memory/tfree.h>

#include <parser/statement_ll/new.h>

#include "just_specifiers.h"

int declaration_just_specifiers_callback(
	struct statement_ll** retval,
	struct declaration_specifiers* ds)
{
	int error = 0;
	ENTER;
	
	// what do we need to do here?
	// there's no variables, no assignments
	// just a struct/union type, which has already been scope.declared()
	
	error = new_statement_ll(retval);
	
	tfree(ds);
	
	EXIT;
	return error;
}

