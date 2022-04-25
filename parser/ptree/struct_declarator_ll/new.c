
#include <assert.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

#include "struct.h"
#include "free.h"
#include "new.h"

int new_struct_declarator_ll(
	struct struct_declarator_ll** new)
{
	int error = 0;
	ENTER;
	
	struct struct_declarator_ll* this = NULL;
	
	error = tmalloc(
		(void**) &this, sizeof(*this),
		(void (*)(void*)) free_struct_declarator_ll);
	
	if (!error)
	{
		this->head = this->tail = NULL;
		
		*new = tinc(this);
	}
	
	tfree(this);
	
	EXIT;
	return error;
}

