
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "pop.h"

int scope_pop(struct scope* this)
{
	int error = 0;
	ENTER;
	
	struct layer* head = this->stackhead;
	
	assert(head);
	
	this->stackhead = head->prev;
	
	tfree(head);
/*	CHECK;*/
	
	EXIT;
	return error;
}








