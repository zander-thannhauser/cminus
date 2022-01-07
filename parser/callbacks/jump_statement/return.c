
#include <debug.h>

#include <memory/tfree.h>

#include <type/struct.h>

#include <expression/cast/new.h>

#include <statement/return/new.h>

#include <parser/yylloc/new.h>

#include "return.h"

int jump_statement_return_callback(
	struct statement** out,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct type* rettype,
	struct expression* expression,
	char* name)
{
	int error = 0;
	ENTER;
	
	dpvs(name);
	assert(name);
	
	bool is_float_result = (rettype->kind == tk_float);
	
	struct expression* casted = NULL;
	struct yylloc* loc = NULL;
	
	error = 0
		?: new_yyloc(&loc,
			first_line, first_column,
			last_line, last_column)
		?: new_cast_expression(&casted, NULL, rettype, expression)
		?: new_return_statement(
			(struct return_statement**) out, loc, is_float_result, name, casted);
	
	tfree(loc);
	tfree(casted);
	tfree(expression);
	
	EXIT;
	return error;
}















