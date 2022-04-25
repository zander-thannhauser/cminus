
#include <assert.h>

#include <scope/pop.h>

#include "close.h"

int compound_statement_close_callback(
	struct scope* scope)
{
	int error = 0;
	ENTER;
	
	scope_pop(scope);
	
	EXIT;
	return error;
}

