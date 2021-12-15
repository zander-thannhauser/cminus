
#include <debug.h>

#include <memory/tfree.h>

#include <type/struct.h>
#include <types/struct.h>

#include <expression/literal/new.h>

#include "sizeof_type.h"

int unary_expression_sizeof_type_callback(
	struct expression** retval,
	struct type* type,
	struct types* types)
{
	int error = 0;
	ENTER;
	
	dpv(type->size);
	
	TODO;
	#if 0
	if (!type->is_complete)
	{
		TODO;
		error = 1;
	}
	else
		error = new_literal_expression_as_unsigned_long(
			(struct expression**) retval,
			/* type: */ types->primitives[pk_unsigned_long],
			/* value: */ type->size);
	
	tfree(type);
	#endif
	TODO;
	
	EXIT;
	return error;
}



















