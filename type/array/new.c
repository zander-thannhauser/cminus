
#include <debug.h>

#include <memory/tinc.h>

#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_array_type(
	struct array_type** new,
	struct type* element_type,
	size_t number_of_elements)
{
	int error = 0;
	ENTER;
	
	dpv(number_of_elements);
	
	dpv(element_type->size * number_of_elements);
	
	struct array_type* this = NULL;
	
	error = new_type(
		(struct type**) &this,
		/* kind: */ tk_array,
		/* inheritance: */ &array_type_inheritance,
		/* is_complete: */ true,
		/* size: */ element_type->size * number_of_elements,
		sizeof(*this));
	
	if (!error)
	{
		this->element_type = tinc(element_type);
		this->number_of_elements = number_of_elements;
		
		*new = this;
	}
	
	EXIT;
	return error;
}

int new_sizeless_array_type(
	struct array_type** new,
	struct type* element_type)
{
	int error = 0;
	ENTER;
	
	struct array_type* this = NULL;
	
	error = new_type(
		(struct type**) &this,
		/* kind: */ tk_array,
		/* inheritance: */ &array_type_inheritance,
		/* is_complete: */ false,
		/* size: */ -1,
		sizeof(*this));
	
	if (!error)
	{
		this->element_type = tinc(element_type);
		
		*new = this;
	}
	
	EXIT;
	return error;
}











