
#include <assert.h>

#include <macros/max.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

#include "../new.h"

#include "field/struct.h"
#include "field_ll/struct.h"
#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_struct_type(
	struct struct_type** new,
	bool struct_or_union,
	struct struct_field_ll* fields)
{
	int error = 0;
	struct struct_field_ll_link* link;
	ENTER;
	
	dpv(fields);
	dpv(fields->head);
	
	size_t size = 0;
	
	for (link = fields->head; link; link = link->next)
	{
		dpvs(link);
		
		if (!link->element->type->is_complete)
		{
			dpv(link->element->type->size);
			TODO;
			error = 1;
		}
		else if (struct_or_union)
		{
			// struct
			link->element->offset = size;
			size += link->element->type->size;
		}
		else
		{
			// union
			link->element->offset = 0;
			size = max(size, link->element->type->size);
		}
	}
	
	dpv(size);
	
	struct struct_type* this = NULL;
	
	if (!error)
		error = new_type(
			(struct type**) &this,
			tk_struct,
			/* inheritance: */ &struct_type_inheritance,
			/* is_complete: */ true,
			/* size: */ size,
			sizeof(*this));
	
	if (!error)
	{
		this->struct_or_union = struct_or_union;
		this->fields = tinc(fields);
		
		*new = this;
	}
	
	EXIT;
	return error;
}

int new_incomplete_struct_type(
	struct struct_type** new,
	bool struct_or_union)
{
	int error = 0;
	ENTER;
	
	struct struct_type* this = NULL;
	
	error = new_type(
		(struct type**) &this,
		/* kind: */ tk_struct,
		/* inheritance: */ &struct_type_inheritance,
		/* is_complete: */ false,
		/* size: */ -1,
		sizeof(*this));
	
	if (!error)
	{
		this->struct_or_union = struct_or_union;
		this->fields = NULL;
		
		*new = this;
	}
	
	EXIT;
	return error;
}








