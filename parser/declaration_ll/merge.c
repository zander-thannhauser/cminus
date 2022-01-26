
#include <assert.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include "struct.h"
#include "merge.h"

void declaration_ll_merge(
	struct declaration_ll* this,
	struct declaration_ll* that)
{
	ENTER;
	
	dpv(this);
	dpv(that);
	
	if (this->tail)
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
}

