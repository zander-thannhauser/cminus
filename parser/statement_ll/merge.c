
#include <debug.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include "struct.h"
#include "merge.h"

int statement_ll_merge(
	struct statement_ll* this,
	struct statement_ll* that)
{
	int error = 0;
	ENTER;
	
	dpv(this);
	dpv(that);
	
	dpv(this->head);
	dpv(that->head);
	
	if (!that->head)
	{
		// empty 'that'
		HERE;
	}
	else if (this->tail)
	{
		this->tail->next = tinc(that->head);
		tfree(this->tail), this->tail = tinc(that->tail);
	}
	else
	{
		this->head = tinc(that->head),
		this->tail = tinc(that->tail);
	}
	
	EXIT;
	return error;
}
