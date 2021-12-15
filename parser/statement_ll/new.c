
#include <debug.h>

#include <memory/tmalloc.h>

#include "struct.h"
#include "free.h"
#include "new.h"

int new_statement_ll(
	struct statement_ll** new)
{
	int error = 0;
	struct statement_ll* this = NULL;
	ENTER;
	
	error = tmalloc(
		(void**) &this, sizeof(*this),
		(void (*)(void*)) free_statement_ll);
	
	if (!error)
	{
		this->head = this->tail = NULL;
		
		*new = this;
	}
	
	EXIT;
	return error;
}

