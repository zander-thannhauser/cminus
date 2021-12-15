
#include <debug.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

#include "kind.h"
#include "struct.h"
#include "free.h"
#include "new.h"

int new_declarator(
	struct declarator** new,
	enum declarator_kind kind,
	struct declarator_inheritance* inheritance,
	size_t alloc_size)
{
	int error = 0;
	struct declarator* this = NULL;
	ENTER;
	
	error = tmalloc(
		(void**) &this, alloc_size,
		(void (*)(void*)) free_declarator);
	
	if (!error)
	{
		this->kind = kind;
		this->inheritance = inheritance;
		
		*new = this;
	}
	
	EXIT;
	return error;
}









