
#include <stdio.h>

#include <enums/error.h>
#include <debug.h>

#include <defines/argv0.h>

#include <memory/tfree.h>

#include <type/struct.h>

#include <expression/struct.h>
#include <expression/unary/new.h>
#include <expression/assign/new.h>
#include <expression/cast/new.h>

#include "assignment.h"

int assignment_expression_assignment_callback(
	struct expression** retval,
	struct expression* left,
	enum assign_expression_kind kind,
	struct expression* right,
	struct types* types)
{
	int error = 0;
	ENTER;
	
	struct type const* type = left->type;
	
	assert(type->kind != tk_array);
	
	if (!type->is_complete)
	{
		fprintf(stderr, "%s: assignment to incomplete type!\n", argv0),
		error = e_bad_input_file;
	}
	else if (type->qualifiers[tq_constant])
	{
		fprintf(stderr, "%s: assignment to constant value!\n", argv0),
		error = e_bad_input_file;
	}
	else 
	{
		struct expression* cast_right = NULL;
	
		error = 0
			?: new_cast_expression(&cast_right, left->type, right, types)
			?: new_assign_expression(retval, kind, left, cast_right, types);
		
		tfree(cast_right);
	}
	
	tfree(left), tfree(right);
	
	EXIT;
	return error;
}








