
#include <debug.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

#include "struct.h"
#include "free.h"
#include "new.h"

int new_init_declarator_ll(
	struct init_declarator_ll** new)
{
	int error = 0;
	ENTER;
	
	struct init_declarator_ll* this = NULL;
	
	error = tmalloc(
		(void**) &this, sizeof(*this),
		(void (*)(void*)) free_init_declarator_ll);
	
	if (!error)
	{
		this->head = this->tail = NULL;
		
		*new = this;
	}
	
	EXIT;
	return error;
}

