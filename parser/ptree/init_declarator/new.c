
#include <assert.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

#include "struct.h"
#include "free.h"
#include "new.h"

int new_init_declarator(
	struct init_declarator** new,
	struct declarator* declarator,
	struct initializer* initializer)
{
	int error;
	ENTER;
	
	struct init_declarator* this = NULL;
	
	error = tmalloc(
		(void**) &this, sizeof(*this),
		(void (*)(void*)) free_init_declarator);
	
	if (!error)
	{
		this->declarator = tinc(declarator);
		this->initializer = tinc(initializer);
		
		*new = this;
	}
	
	EXIT;
	return error;
}

