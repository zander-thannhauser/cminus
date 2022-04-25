
#include <assert.h>

#include <memory/tmalloc.h>

#include "struct.h"
#include "free.h"
#include "new.h"

int new_variable_ll(
	struct variable_ll** new)
{
	int error = 0;
	struct variable_ll* this = NULL;
	ENTER;
	
	error = tmalloc(
		(void**) &this, sizeof(*this),
		(void (*)(void*)) free_variable_ll);
	
	if (!error)
	{
		this->head = this->tail = NULL;
		
		*new = this;
	}
	
	EXIT;
	return error;
}

