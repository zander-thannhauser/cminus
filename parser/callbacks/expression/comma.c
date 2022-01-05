
#include <debug.h>

#include <memory/tfree.h>

#include <expression/comma/new.h>

#include "comma.h"

int expression_comma_callback(
	struct expression** retval,
	struct expression* left,
	struct expression* right,
	struct types* types)
{
	int error = 0;
	ENTER;
	
	error = new_comma_expression(retval, left, right, types);
	
	tfree(left), tfree(right);
	
	EXIT;
	return error;
}

