
#include <assert.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>

#include "struct.h"
#include "free.h"
#include "new.h"

int new_function_definition(
	struct function_definition** new,
	char* name,
	struct function_type* ftype,
	enum storage_class storage_class,
	struct variable_ll* parameters)
{
	int error = 0;
	ENTER;
	
	struct function_definition* this = NULL;
	
	error = tmalloc(
		(void*) &this, sizeof(*this),
		(void (*)(void*)) free_function_definition);
	
	if (!error)
	{
		this->name = tinc(name);
		this->ftype = tinc(ftype);
		this->storage_class = storage_class;
		this->parameters = tinc(parameters);
		this->frame_size = 0;
		this->body = NULL;
		
		*new = this;
	}
	
	EXIT;
	return error;
}

