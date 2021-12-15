
#include <debug.h>

#include <macros/max.h>

#include <memory/tfree.h>

/*#include <type/primitive/struct.h>*/

#include <types/struct.h>

#include <expression/struct.h>
#include <expression/binary/new.h>
#include <expression/cast/new.h>

#include "equal_to.h"

int equality_expression_equal_to_callback(
	struct expression** retval,
	struct expression* left,
	struct expression* right,
	struct types* types)
{
	int error = 0;
	ENTER;
	
	TODO;
	#if 0
	if (false
		|| left->type->kind != tk_primitive
		|| right->type->kind != tk_primitive)
	{
		TODO;
		error = 1;
	}
	else
	{
		struct type* result_type;
		struct primitive_type *lt = (typeof(lt)) left->type, *rt = (typeof(rt)) right->type;
		struct expression* cast_left = NULL;
		struct expression* cast_right = NULL;
		
		dpv(lt->kind);
		dpv(rt->kind);
		dpv(max(lt->kind, rt->kind));
		
		result_type = types->primitives[max(lt->kind, rt->kind)];
		
		error = 0
			?: new_cast_expression(&cast_left, result_type, left, types)
			?: new_cast_expression(&cast_right, result_type, right, types)
			?: new_binary_expression(
				retval, bek_equal_to, cast_left, cast_right, types);
		
		tfree(cast_left), tfree(cast_right);
	}
	
	tfree(left), tfree(right);
	#endif
	
	EXIT;
	return error;
}












