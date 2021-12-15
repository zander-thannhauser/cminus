
#include <debug.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

#include "struct.h"
#include "free_link.h"
#include "append.h"

int expression_ll_append(
	struct expression_ll* this,
	struct expression* element)
{
	int error = 0;
	ENTER;
	
	struct expression_link* link = NULL;
	
	error = tmalloc(
		(void**) &link, sizeof(*link),
		(void (*)(void*)) free_expression_link);
	
	if (!error)
	{
		this->n++;
		
		link->element = tinc(element);
		
		link->prev = link->next = NULL;
		
		if (this->tail)
		{
			link->prev = this->tail;
			dpv(link->prev);
			this->tail->next = tinc(link);
		}
		
		if (!this->head)
			this->head = tinc(link);
		
		tfree(this->tail), this->tail = tinc(link);
	}
	
	tfree(link);
	
	EXIT;
	return error;
}









