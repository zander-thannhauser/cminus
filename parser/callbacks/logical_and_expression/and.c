
#include <debug.h>

#include <memory/tfree.h>

/*#include <type/struct.h>*/

/*#include <types/struct.h>*/

/*#include <expression/struct.h>*/
/*#include <expression/cast/new.h>*/
#include <expression/logical_and/new.h>

#include "and.h"

int logical_and_expression_and_callback(
	struct expression** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* left,
	struct expression* right,
	struct types* types)
{
	int error = 0;
	ENTER;
	
	error = new_logical_and_expression(retval,
		first_line, first_column,
		last_line, last_column,
		left, right, types);
	
	tfree(left), tfree(right);
	
	EXIT;
	return error;
}











