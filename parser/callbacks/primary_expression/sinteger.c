
#include <debug.h>

#include <memory/tfree.h>

#include <types/struct.h>

#include <expression/literal/new.h>

#include <parser/yylloc/new.h>

#include "sinteger.h"

int primary_expression_sinteger_callback(
	struct expression** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct types* types,
	signed int sintegerlit)
{
	int error = 0;
	struct yylloc* location = NULL;
	ENTER;
	
	error = 0
		?: new_yyloc(&location,
			first_line, first_column,
			last_line, last_column)
		?: new_literal_expression_as_signed_int(
			(struct expression**) retval,
			location,
			types->integers[ik_signed_int],
			sintegerlit);
	
	tfree(location);
	
	EXIT;
	return error;
}

