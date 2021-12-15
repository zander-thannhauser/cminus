
#include <debug.h>

#include <expression/literal/new.h>

#include <types/struct.h>

#include "slong.h"

int primary_expression_slong_callback(
	struct expression** retval,
	struct types* types,
	signed long slonglit)
{
	int error = 0;
	ENTER;
	
	TODO;
	#if 0
	error = new_literal_expression_as_unsigned_long(
		(struct expression**) retval,
		types->primitives[pk_signed_long],
		slonglit);
	#endif
	
	EXIT;
	return error;
}

