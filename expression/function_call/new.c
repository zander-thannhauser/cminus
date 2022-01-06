
#include <stdio.h>

#include <error.h>
#include <debug.h>

/*#include <defines/argv0.h>*/

#include <memory/tinc.h>
/*#include <memory/tfree.h>*/

/*#include <types/struct.h>*/

/*#include <type/struct.h>*/
#include <type/function/struct.h>

/*#include <expression/cast/new.h>*/

/*#include <parser/parameter/struct.h>*/
/*#include <parser/parameter_ll/struct.h>*/

/*#include <parser/expression_ll/struct.h>*/
/*#include <parser/expression_ll/new.h>*/
/*#include <parser/expression_ll/append.h>*/

#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_function_call_expression(
	struct function_call_expression** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* fe,
	struct expression_ll* casted_args)
{
	int error = 0;
	ENTER;
	
	assert(fe->type->kind == tk_function);
	
	struct function_call_expression* this = NULL;
	
	struct function_type* spef = (typeof(spef)) fe->type;
	
	error = new_expression(
		(struct expression**) &this,
		/* kind:        */ ek_function_call,
		/* inheritance: */ &function_call_expression_inheritance,
		/* first:       */ first_line, first_column,
		/* last:        */ last_line, last_column,
		/* type:        */ spef->return_type,
		sizeof(*this));
	
	if (!error)
	{
		this->function = tinc(fe);
		this->arguments = tinc(casted_args);
		
		*new = this;
	}
	
	EXIT;
	return error;
}










