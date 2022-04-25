
#include <assert.h>

#include <memory/tmalloc.h>

#include "struct.h"
#include "free.h"
#include "new.h"

int new_parameter_ll(
	struct parameter_ll** new)
{
	int error = 0;
	ENTER;
	
	struct parameter_ll* this = NULL;
	
	error = tmalloc(
		(void*) &this, sizeof(*this),
		(void (*)(void*)) free_parameter_ll);
	
	if (!error)
	{
		this->head = this->tail = NULL;
		this->ellipsis = false;
		
		*new = this;
	}
	
	EXIT;
	return error;
}

