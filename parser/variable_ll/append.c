
#include <debug.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

#include "struct.h"
#include "free_link.h"
#include "append.h"

int variable_ll_append(
	struct variable_ll* this,
	struct variable* element)
{
	int error = 0;
	ENTER;
	
	struct variable_link* link = NULL;
	
	error = tmalloc(
		(void**) &link, sizeof(*link),
		(void (*)(void*)) free_variable_link);
	
	if (!error)
	{
		link->element = tinc(element);
		link->next = NULL;
		
		if (this->tail)
			this->tail->next = tinc(link);
		
		if (!this->head)
			this->head = tinc(link);
		
		tfree(this->tail), this->tail = tinc(link);
	}
	
	tfree(link);
	
	EXIT;
	return error;
}












