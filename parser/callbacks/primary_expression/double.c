
#include <debug.h>

#include <memory/tfree.h>

#include <types/struct.h>

#include <expression/literal/new.h>

#include <parser/yylloc/new.h>

#include "double.h"

int primary_expression_double_callback(
	struct expression** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct types* types,
	double doublelit)
{
	int error = 0;
	struct yylloc* loc = NULL;
	ENTER;
	
	dpv(doublelit);
	
	error = 0
		?: new_yyloc(&loc,
			first_line, first_column,
			last_line, last_column)
		?: new_literal_expression_as_double(
			(struct expression**) retval,
			loc, types->floats[fk_double], doublelit);
	
	tfree(loc);
	
	EXIT;
	return error;
}

