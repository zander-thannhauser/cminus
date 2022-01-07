

#include <stddef.h>

#include <debug.h>

#include <memory/tfree.h>

/*#include <type/struct.h>*/

/*#include <types/struct.h>*/

/*#include <expression/struct.h>*/
/*#include <expression/cast/new.h>*/
#include <expression/logical_and/new.h>

#include <parser/yylloc/new.h>

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
	struct yylloc* loc = NULL;
	ENTER;
	
	error = 0
		?: new_yyloc(&loc, first_line, first_column, last_line, last_column)
		?: new_logical_and_expression(retval, loc, left, right, types);
		
	tfree(loc);
	tfree(left), tfree(right);
	
	EXIT;
	return error;
}











