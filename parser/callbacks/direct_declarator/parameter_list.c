
#include <assert.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <type/struct.h>
#include <type/array/struct.h>
#include <type/pointer/new.h>

#include <parser/ptree/declarator/function/new.h>

#include <parser/parameter/struct.h>
#include <parser/parameter/new.h>
#include <parser/parameter_ll/struct.h>
#include <parser/parameter_ll/new.h>
#include <parser/parameter_ll/append.h>

#include "parameter_list.h"

int direct_declarator_parameter_list_callback(
	struct declarator** new,
	struct declarator* inner,
	struct parameter_ll* parameters)
{
	int error = 0;
	struct parameter_ll* newparams = NULL;
	ENTER;
	
	// any parameter with a type of array
	// should be replaced with a pointer type instead
	error = new_parameter_ll(&newparams);
	
	struct parameter_link* plink;
	for (plink = parameters->head; !error && plink; plink = plink->next)
	{
		struct parameter* p = plink->element;
		struct parameter* np = NULL;
		
		dpvs(p->identifier);
		
		if (p->type->kind == tk_array)
		{
			struct array_type* const at = (typeof(at)) p->type;
			struct type* pt = NULL;
			
			error = 0
				?: new_pointer_type(
					(struct pointer_type**) &pt,
					(bool[number_of_type_qualifiers]) {[tq_constant] = true},
					at->element_type)
				?: new_parameter(&np, p->identifier, pt);
			
			tfree(pt);
		}
		else
			np = tinc(p);
		
		if (!error)
			error = parameter_ll_append(newparams, np);
		
		tfree(np);
	}
	
	if (!error)
		newparams->ellipsis = parameters->ellipsis;
	
	if (!error)
		error = new_function_declarator(
			(struct function_declarator**) new, inner, newparams);
	
	tfree(inner);
	tfree(parameters);
	tfree(newparams);
	
	EXIT;
	return error;
}











