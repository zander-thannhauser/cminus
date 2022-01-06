
#include <debug.h>

#include <defines/argv0.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <types/struct.h>

#include <type/struct.h>
#include <type/function/struct.h>

#include <expression/cast/new.h>

#include <parser/parameter/struct.h>
#include <parser/parameter_ll/struct.h>

#include <parser/expression_ll/struct.h>
#include <parser/expression_ll/new.h>
#include <parser/expression_ll/append.h>


#include <expression/struct.h>
#include <expression/function_call/new.h>

#include "function_call.h"

int postfix_expression_function_call_callback(
	struct expression** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* fe,
	struct expression_ll* ae_ll,
	struct types* types)
{
	int error = 0;
	ENTER;
	
	if (fe->type->kind != tk_function)
	{
		TODO;
		error = 1;
	}
	
	// shortcuts:
	struct function_type* spef;
	struct parameter_ll* parameters;
	struct expression_ll* casted_args = NULL;
	
	if (!error)
	{
		spef = (typeof(spef)) fe->type;
		parameters = spef->parameters;
		
		error = new_expression_ll(&casted_args);
	}
	
	// type-check parameters
	struct parameter_link* plink;
	struct expression_link* alink;
	
	if (!error)
	{
		plink = spef->parameters->head, alink = ae_ll->head;
	}
	
	for (;!error && plink && alink; plink = plink->next, alink = alink->next)
	{
		struct expression* ce = NULL;
		
		error = 0
			?: new_cast_expression(&ce, 0, 0, 0, 0, plink->element->type, alink->element, types)
			?: expression_ll_append(casted_args, ce);
		
		tfree(ce);
	}
	
	if (!!plink > !!alink)
	{
		TODO; // "too few parameters!"
		error = 1;
	}
	else if (parameters->ellipsis)
	{
		// while loop appending the rest:
		for (; !error && alink; alink = alink->next)
		{
			// there's any floats: cast them to double:
			if (alink->element->type->kind == tk_float)
			{
				struct expression* ce = NULL;
				
				error = 0
					?: new_cast_expression(&ce, 0, 0, 0, 0,
						types->floats[fk_double], alink->element, types)
					?: expression_ll_append(casted_args, ce);
				
				tfree(ce);
			}
			else
				error = expression_ll_append(casted_args, alink->element);
		}
	}
	else if (!!plink < !!alink)
	{
		TODO; // "too many parameters!"
		error = 1;
	}
	
	
	error = new_function_call_expression(
		(struct function_call_expression**) retval,
		first_line, first_column,
		last_line, last_column,
		fe, casted_args);
	
	tfree(fe);
	tfree(ae_ll);
	tfree(casted_args);
	
	EXIT;
	return error;
}

