
#include <assert.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>

#include "struct.h"
#include "free.h"
#include "new.h"

int new_parameter(
	struct parameter** new,
	char* identifier,
	struct type* type)
{
	int error = 0;
	ENTER;
	
	// identifier is optional:
	// assert(identifier);
	assert(type);
	
	struct parameter* this = NULL;
	
	error = tmalloc((void**) &this, sizeof(*this),
		(void (*)(void*)) free_parameter);
	
	if (!error)
	{
		this->identifier = tinc(identifier);
		this->type = tinc(type);
		
		*new = this;
	}
	
	EXIT;
	return error;
}

