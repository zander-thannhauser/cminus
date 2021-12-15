
#include <debug.h>

#include <macros/max.h>

#include <memory/tfree.h>

#include <type/integer/struct.h>

#include <type/float/struct.h>

#include <types/struct.h>

#include <expression/struct.h>
#include <expression/cast/new.h>
#include <expression/binary/new.h>

#include "add.h"

int additive_expression_add_callback(
	struct expression** retval,
	struct expression* left,
	struct expression* right,
	struct types* types)
{
	int error = 0;
	ENTER;
	
	struct type* const ltype = left->type;
	struct type* const rtype = right->type;
	
	if (ltype->kind == tk_integer && rtype->kind == tk_integer)
	{
		struct expression *cast_left = NULL, *cast_right = NULL;
		struct integer_type *lit = (typeof(lit)) ltype, *rit = (typeof(rit)) rtype;
		struct type* result_type = types->integers[max(lit->kind, rit->kind)];
		
		error = 0
			?: new_cast_expression(&cast_left, result_type, left, types)
			?: new_cast_expression(&cast_right, result_type, right, types)
			?: new_binary_expression(retval, bek_add, cast_left, cast_right, types);
		
		tfree(cast_left), tfree(cast_right);
	}
	else if (ltype->kind == tk_float && rtype->kind == tk_float)
	{
		struct expression *cast_left = NULL, *cast_right = NULL;
		struct float_type *lit = (typeof(lit)) ltype, *rit = (typeof(rit)) rtype;
		struct type* result_type = types->floats[max(lit->kind, rit->kind)];
		
		error = 0
			?: new_cast_expression(&cast_left, result_type, left, types)
			?: new_cast_expression(&cast_right, result_type, right, types)
			?: new_binary_expression(retval, bek_add, cast_left, cast_right, types);
		
		tfree(cast_left), tfree(cast_right);
	}
	else
	{
		TODO;
	}
	
	#if 0
	if (false
		|| ltype->kind != tk_primitive
		|| rtype->kind != tk_primitive)
	{
		TODO;
		error = 1;
	}
	else if (false
		|| (ltype->kind == tk_pointer && rtype->kind == tk_primitive)
		|| (ltype->kind == tk_primitive && rtype->kind == tk_pointer))
	{
		// regardless:
		// cast both to ulongs
		// add * sizeof()
		// cast to be pointer to whichever
		// return that instead
		TODO;
	}
	else
	{
		struct type* result_type;
		struct primitive_type *lt = (typeof(lt)) ltype, *rt = (typeof(rt)) rtype;
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
				retval, bek_add, cast_left, cast_right, types);
		
		tfree(cast_left), tfree(cast_right);
	}
	
	tfree(left), tfree(right);
	#endif
	
	EXIT;
	return error;
}











