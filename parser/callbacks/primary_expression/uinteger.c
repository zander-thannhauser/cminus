
#include <assert.h>

#include <memory/tfree.h>

#include <types/struct.h>

#include <expression/literal/new.h>

#include <parser/yylloc/new.h>

#include "uinteger.h"

int primary_expression_uinteger_callback(
	struct expression** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct types* types,
	unsigned int uintegerlit)
{
	int error = 0;
	struct yylloc* loc = NULL;
	ENTER;
	
	error = 0
		?: new_yyloc(&loc, first_line, first_column, last_line, last_column)
		?: new_literal_expression_as_unsigned_long(
			(struct expression**) retval, loc,
			types->integers[ik_unsigned_int],
			uintegerlit);
	
	tfree(loc);
	
	EXIT;
	return error;
}

