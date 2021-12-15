
#include <debug.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

#include "struct.h"
#include "free.h"
#include "new.h"

int new_struct_declarator(
	struct struct_declarator** new,
	struct declarator* declarator,
	struct expression* bitfield_width)
{
	int error = 0;
	ENTER;
	
	struct struct_declarator* this = NULL;
	
	error = tmalloc(
		(void**) &this, sizeof(*this),
		(void (*)(void*)) free_struct_declarator);
	
	if (!error)
	{
		this->declarator = tinc(declarator);
		this->bitfield_width = tinc(bitfield_width);
		
		
		*new = this, this = NULL;
	}
	
	tfree(this);
	
	EXIT;
	return error;
}

