
#include <debug.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include "struct.h"
#include "merge.h"

void struct_field_ll_merge(
	struct struct_field_ll* this,
	struct struct_field_ll* that)
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
