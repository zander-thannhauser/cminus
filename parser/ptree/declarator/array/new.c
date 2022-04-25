
#include <assert.h>

#include <memory/tinc.h>

#include "../kind.h"
#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_array_declarator(
	struct array_declarator** new,
	struct declarator* inner,
	size_t array_size)
{
	int error = 0;
	ENTER;
	
	struct array_declarator* this = NULL;
	
	error = new_declarator(
		(struct declarator**) &this,
		pdk_array,
		&array_declarator_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->inner = tinc(inner);
		this->sizeless = false;
		this->array_size = array_size;
		
		*new = this;
	}
	
	EXIT;
	return error;
}

int new_sizeless_array_declarator(
	struct array_declarator** new,
	struct declarator* inner)
{
	int error = 0;
	ENTER;
	
	struct array_declarator* this = NULL;
	
	error = new_declarator(
		(struct declarator**) &this,
		pdk_array,
		&array_declarator_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->inner = tinc(inner);
		this->sizeless = true;
		
		*new = this;
	}
	
	
	EXIT;
	return error;
}










