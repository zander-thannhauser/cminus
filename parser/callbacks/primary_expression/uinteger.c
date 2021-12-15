
#include <debug.h>

#include <expression/literal/new.h>

#include <types/struct.h>

#include "uinteger.h"

int primary_expression_uinteger_callback(
	struct expression** retval,
	struct types* types,
	unsigned int uintegerlit)
{
	int error = 0;
	ENTER;
	
	TODO;
	#if 0
	error = new_literal_expression_as_unsigned_long(
		(struct expression**) retval,
		types->primitives[pk_unsigned_int],
		uintegerlit);
	#endif
	
	EXIT;
	return error;
}

