
#include <assert.h>

/*#include <macros/max.h>*/

/*#include <memory/tinc.h>*/
#include <memory/tfree.h>

#include <type/struct.h>
#include <type/compare.h>

/*#include <types/struct.h>*/

#include <expression/struct.h>
#include <expression/relational/new.h>
#include <expression/cast/new.h>

#include <parser/yylloc/new.h>

#include "equal_to.h"

int equality_expression_equal_to_callback(
	struct expression** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* left,
	struct expression* right,
	struct types* types)
{
	int error = 0;
	ENTER;
	
	if (true
		&& ( left->type->kind == tk_integer ||  left->type->kind == tk_float)
		&& (right->type->kind == tk_integer || right->type->kind == tk_float))
	{
		struct yylloc* loc = NULL;
		struct type* lt = left->type, *rt = right->type, *ht;
		struct expression *cast_left = NULL, *cast_right = NULL;
		
		ht = compare_types(lt, rt) > 0 ? lt : rt;
		
		error = 0
			?: new_yyloc(&loc, first_line, first_column, last_line, last_column)
			?: new_cast_expression(&cast_left, NULL, ht, left)
			?: new_cast_expression(&cast_right, NULL, ht, right)
			?: new_relational_expression(retval,
				loc, rek_equal_to, cast_left, cast_right, types);
		
		tfree(cast_left), tfree(cast_right);
		tfree(loc);
	}
	else
	{
		TODO;
		error = 1;
	}
	
	tfree(left);
	tfree(right);
	
	EXIT;
	return error;
}












