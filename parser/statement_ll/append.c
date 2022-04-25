
#include <assert.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

#include "struct.h"
#include "free_link.h"
#include "append.h"

int statement_ll_append(
	struct statement_ll* this,
	struct statement* element)
{
	int error = 0;
	ENTER;
	
	dpv(element);
	
	struct statement_link* link = NULL;
	
	error = tmalloc(
		(void**) &link, sizeof(*link),
		(void (*)(void*)) free_statement_link);
	
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












