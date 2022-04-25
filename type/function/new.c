
#include <assert.h>

#include <memory/tinc.h>

#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_function_type(
	struct function_type** new,
	struct type* return_type,
	struct parameter_ll* parameters)
{
	int error = 0;
	ENTER;
	
	struct function_type* this = NULL;
	
	error = new_type(
		/* new: */ (struct type**) &this,
		/* kind: */ tk_function,
		/* inheritance: */ &function_type_inheritance,
		/* is_complete: */ false,
		/* size: */ -1,
		sizeof(*this));
	
	if (!error)
	{
		this->return_type = tinc(return_type);
		this->parameters = tinc(parameters);
		
		*new = this;
	}
	
	EXIT;
	return error;
}

