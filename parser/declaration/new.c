
#include <debug.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

#include "free.h"
#include "struct.h"
#include "new.h"

int new_declaration(
	struct declaration** new,
	enum storage_class storage_class,
	struct type* type,
	char* identifier)
{
	int error = 0;
	ENTER;
	
	struct declaration* this = NULL;
	
	error = tmalloc(
		(void**) &this, sizeof(*this),
		(void (*)(void*)) free_declaration);
	
	if (!error)
	{
		this->storage_class = storage_class;
		this->type = tinc(type);
		this->identifier = tinc(identifier);
		
		*new = tinc(this);
	}
	
	tfree(this);
	
	EXIT;
	return error;
}








