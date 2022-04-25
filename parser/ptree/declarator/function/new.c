
#include <assert.h>

#include <memory/tinc.h>

#include "../kind.h"
#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_function_declarator(
	struct function_declarator** new,
	struct declarator* inner,
	struct parameter_ll* parameters)
{
	int error = 0;
	ENTER;
	
	struct function_declarator* this = NULL;
	
	error = new_declarator(
		(struct declarator**) &this,
		pdk_function,
		&function_declarator_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->inner = tinc(inner);
		this->parameters = tinc(parameters);
		
		*new = this;
	}
	
	EXIT;
	return error;
}

