
#include <assert.h>

#include <memory/tfree.h>

#include <type/struct.h>
#include <type/compare.h>

#include <expression/struct.h>
#include <expression/ternary/new.h>

#include <parser/yylloc/new.h>

#include "ternary.h"

int conditional_expression_ternary_callback(
	struct expression** out_expression,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* conditional_expression,
	struct expression* true_expression,
	struct expression* false_expression)
{
	int error = 0;
	enum type_kind true_kind = true_expression->type->kind;
	enum type_kind false_kind = false_expression->type->kind;
	ENTER;
	
	if (conditional_expression->kind == ek_literal)
	{
		// constant-fold either the true or false expression
		TODO;
	}
	else
	{
		struct expression* casted_true = NULL;
		struct expression* casted_false = NULL;
		
		if (true_kind == false_kind)
		{
			switch (true_kind)
			{
				case tk_integer:
					// check for integer to integer cast
					TODO;
					break;
				
				case tk_float:
					// check for float to float cast
					TODO;
					break;
				
				case tk_pointer:
					if (!!compare_types(true_expression->type, false_expression->type))
					{
						// cast them both to void*
						TODO;
					}
					break;
				
				default:
					TODO;
					break;
			}
		}
		else if (true_kind == tk_integer && false_kind == tk_float)
		{
			// that's fine, we just need to cast the int
			TODO;
		}
		else if (true_kind == tk_float && false_kind == tk_integer)
		{
			// that's fine, we just need to cast the int
			TODO;
		}
		else
		{
			TODO;
			error = 1;
		}
		
		struct yylloc* loc = NULL;
		
		if (!error)
		{
			error = 0
				?: new_yyloc(&loc,
					first_line, first_column,
					last_line, last_column)
				?: new_ternary_expression(
					(struct ternary_expression**) out_expression,
					loc,
					conditional_expression,
					casted_true ?: true_expression,
					casted_false ?: false_expression);
		}
		
		tfree(casted_true);
		tfree(casted_false);
		tfree(loc);
	}
	
	tfree(conditional_expression);
	tfree(true_expression);
	tfree(false_expression);
	
	EXIT;
	return error;
}
















