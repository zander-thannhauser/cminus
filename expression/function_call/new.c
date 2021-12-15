
#include <stdio.h>

#include <error.h>
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

#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_function_call_expression(
	struct function_call_expression** new,
	struct expression* fe,
	struct expression_ll* ae_ll,
	struct types* types)
{
	int error = 0;
	ENTER;
	
	assert(fe->type->kind == tk_function);
	
	// shortcuts:
	struct function_type* const spef = (typeof(spef)) fe->type;
	struct parameter_ll* const parameters = spef->parameters;
	
	struct expression_ll* casted_args = NULL;
	
	error = new_expression_ll(&casted_args);
	
	// type-check parameters
	struct parameter_link* plink;
	struct expression_link* alink;
	
	for (plink = spef->parameters->head, alink = ae_ll->head;
		!error && plink && alink; plink = plink->next, alink = alink->next)
	{
		struct expression* ce = NULL;
		
		error = 0
			?: new_cast_expression(&ce, plink->element->type, alink->element, types)
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
					?: new_cast_expression(&ce, types->floats[fk_double], alink->element, types)
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
	
	struct function_call_expression* this = NULL;
	
	if (!error)
		error = new_expression(
			(struct expression**) &this,
			/* kind: */ ek_function_call,
			/* inheritance: */ &function_call_expression_inheritance,
			/* type: */ spef->return_type,
			sizeof(*this));
	
	if (!error)
	{
		this->function = tinc(fe);
		this->arguments = tinc(casted_args);
		
		*new = this;
	}
	
	tfree(casted_args);
	
	EXIT;
	return error;
}










