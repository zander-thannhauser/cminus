
#include <debug.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

#include "struct.h"
#include "free.h"
#include "new.h"

int new_struct_field(
	struct struct_field** new,
	char* name,
	struct type* type)
{
	int error = 0;
	ENTER;
	
	struct struct_field* this = NULL;
	
	error = tmalloc(
		(void**) &this, sizeof(*this),
		(void (*)(void*)) free_struct_field);
	
	if (!error)
	{
		this->name = tinc(name);
		this->type = tinc(type);
		this->offset = 0;
		
		*new = this, this = NULL;
	}
	
	tfree(this);
	
	EXIT;
	return error;
}

