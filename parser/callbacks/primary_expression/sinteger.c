
#include <debug.h>

#include <expression/literal/new.h>

#include <types/struct.h>

#include "sinteger.h"

int primary_expression_sinteger_callback(
	struct expression** retval,
	struct types* types,
	signed int sintegerlit)
{
	int error = 0;
	ENTER;
	
	error = new_literal_expression_as_signed_int(
		(struct expression**) retval,
		types->integers[ik_signed_int],
		sintegerlit);
	
	EXIT;
	return error;
}

