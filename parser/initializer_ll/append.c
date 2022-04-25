
#include <assert.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

#include "struct.h"
#include "free_link.h"
#include "append.h"

int initializer_ll_append(
	struct initializer_ll* this,
	struct initializer* element)
{
	int error = 0;
	ENTER;
	
	struct initializer_ll_link* link = NULL;
	
	error = tmalloc(
		(void**) &link, sizeof(*link),
		(void (*)(void*)) free_initializer_ll_link);
	
	if (!error)
	{
		// append to end of ll
		
		link->element = tinc(element);
		link->next = NULL;
		
		if (this->tail)
			this->tail->next = tinc(link);
		
		tfree(this->tail), this->tail = tinc(link);
		
		if (!this->head)
			this->head = tinc(link);
		
	}
	
	tfree(link);
	
	EXIT;
	return error;
}









