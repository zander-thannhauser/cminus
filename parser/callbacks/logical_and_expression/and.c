
#include <debug.h>

#include <memory/tfree.h>

#include <type/struct.h>

#include <types/struct.h>

#include <expression/struct.h>
#include <expression/cast/new.h>
#include <expression/binary/new.h>

#include "and.h"

int logical_and_expression_and_callback(
	struct expression** retval,
	struct expression* left,
	struct expression* right,
	struct types* types)
{
	int error = 0;
	ENTER;
	
	TODO;
	#if 0
	struct expression* cast_left = NULL;
	struct expression* cast_right = NULL;
	
	struct type* const result_type = types->primitives[pk_bool];
	
	error = 0
		?: new_cast_expression(&cast_left, result_type, left, types)
		?: new_cast_expression(&cast_right, result_type, right, types)
		?: new_binary_expression(
			retval, bek_logical_and, cast_left, cast_right, types);
	
	tfree(cast_left), tfree(cast_right);
	
	tfree(left), tfree(right);
	#endif
	
	EXIT;
	return error;
}

