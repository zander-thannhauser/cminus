
#include <debug.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>

#include "struct.h"
#include "free.h"
#include "new.h"

int new_statement(
	struct statement** new,
	enum statement_kind kind,
	struct statement_inheritance* inheritance,
	struct yylloc* loc,
	size_t alloc_size)
{
	int error = 0;
	ENTER;
	
	struct statement* this = NULL;
	
	error = tmalloc(
		(void**) &this, alloc_size,
		(void (*)(void*)) free_statement);
	
	if (!error)
	{
		this->kind = kind;
		
		this->inheritance = inheritance;
		
		this->loc = tinc(loc);
		
		*new = this;
	}
	
	EXIT;
	return error;
}













