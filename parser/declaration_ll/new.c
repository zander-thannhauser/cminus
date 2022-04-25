
#include <assert.h>

#include <memory/tmalloc.h>

#include "struct.h"
#include "free.h"
#include "new.h"

int new_declaration_ll(
	struct declaration_ll** new)
{
	int error = 0;
	ENTER;
	
	struct declaration_ll* this = NULL;
	
	error = tmalloc(
		(void*) &this, sizeof(*this),
		(void (*)(void*)) free_declaration_ll);
	
	if (!error)
	{
		this->head = this->tail = NULL;
		
		*new = this;
	}
	
	EXIT;
	return error;
}

