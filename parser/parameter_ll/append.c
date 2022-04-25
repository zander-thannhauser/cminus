
#include <assert.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

#include "struct.h"
#include "free_link.h"
#include "append.h"

int parameter_ll_append(
	struct parameter_ll* this,
	struct parameter* element)
{
	int error = 0;
	ENTER;
	
	struct parameter_link* link = NULL;
	
	error = tmalloc(
		(void**) &link, sizeof(*link),
		(void (*)(void*)) free_parameter_link);
	
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












