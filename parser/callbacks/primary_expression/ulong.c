
#include <debug.h>

#include <expression/literal/new.h>

#include <types/struct.h>

#include "ulong.h"

int primary_expression_ulong_callback(
	struct expression** retval,
	struct types* types,
	unsigned long int ulonglit)
{
	int error = 0;
	ENTER;
	
	TODO;
	#if 0
	error = new_literal_expression_as_unsigned_long(
		(struct expression**) retval,
		types->primitives[pk_unsigned_long],
		ulonglit);
	#endif
	
	EXIT;
	return error;
}

