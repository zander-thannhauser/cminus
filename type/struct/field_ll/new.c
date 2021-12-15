
#include <debug.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

#include "struct.h"
#include "free.h"
#include "new.h"

int new_struct_field_ll(
	struct struct_field_ll** new)
{
	int error = 0;
	ENTER;
	
	struct struct_field_ll* this = NULL;
	
	error = tmalloc(
		(void**) &this, sizeof(*this),
		(void (*)(void*)) free_struct_field_ll);
	
	if (!error)
	{
		this->head = this->tail = NULL;
		
		*new = tinc(this);
	}
	
	tfree(this);
	
	EXIT;
	return error;
}

