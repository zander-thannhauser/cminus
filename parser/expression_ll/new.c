
#include <assert.h>

#include <memory/tmalloc.h>

#include "struct.h"
#include "free.h"
#include "new.h"

int new_expression_ll(
	struct expression_ll** new)
{
	int error = 0;
	ENTER;
	
	struct expression_ll* this = NULL;
	
	error = tmalloc(
		(void**) &this, sizeof(*this),
		(void (*)(void*)) free_expression_ll);
	
	if (!error)
	{
		this->n = 0;
		this->head = this->tail = NULL;
		
		*new = this;
	}
	
	EXIT;
	return error;
}

