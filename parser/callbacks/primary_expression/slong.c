
#include <debug.h>

#include <expression/literal/new.h>

#include <types/struct.h>

#include <parser/yylloc/new.h>

#include "slong.h"

int primary_expression_slong_callback(
	struct expression** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct types* types,
	signed long slonglit)
{
	int error = 0;
	struct yylloc* loc = NULL;
	ENTER;
	
	error = 0
		?: new_yyloc(&loc, first_line, first_column, last_line, last_column)
		?: new_literal_expression_as_unsigned_long(
			(struct expression**) retval, loc,
			types->integers[ik_signed_long],
			slonglit);
	
	tfree(loc);
	
	EXIT;
	return error;
}

