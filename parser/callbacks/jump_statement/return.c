
#include <debug.h>

#include <memory/tfree.h>

#include <type/struct.h>

#include <expression/cast/new.h>

#include <statement/return/new.h>

#include "return.h"

int jump_statement_return_callback(
	struct statement** out,
	unsigned line,
	struct type* rettype,
	struct expression* expression,
	struct types* types,
	char* name)
{
	int error = 0;
	ENTER;
	
	dpvs(name);
	
	assert(name);
	
	bool is_float_result = (rettype->kind == tk_float);
	
	struct expression* casted = NULL;
	
	error = 0
		?: new_cast_expression(&casted, rettype, expression, types)
		?: new_return_statement(
			(struct return_statement**) out, line, is_float_result, name, casted);
	
	tfree(casted);
	tfree(expression);
	
	EXIT;
	return error;
}






