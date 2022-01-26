
#include <debug.h>

#include <expression/literal/new.h>

#include <types/struct.h>

#include <parser/yylloc/new.h>

#include "ulong.h"

int primary_expression_ulong_callback(
	struct expression** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct types* types,
	unsigned long int ulonglit)
{
	int error = 0;
	struct yylloc* loc = NULL;
	ENTER;
	
	TODO;
	#if 0
	error = 0
		?: new_yyloc(&loc, first_line, first_column, last_line, last_column)
		?: new_literal_expression_as_unsigned_long(
			(struct expression**) retval, loc,
			types->integers[ik_unsigned_long],
			ulonglit);
	#endif
	
	tfree(loc);
	
	EXIT;
	return error;
}

