
#include <debug.h>

#include <scope/push.h>

#include "open.h"

int compound_statement_open_callback(
	struct scope* scope)
{
	int error = 0;
	ENTER;
	
	error = scope_push(scope);
	
	EXIT;
	return error;
}

