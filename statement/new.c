
#include <debug.h>

#include <memory/tmalloc.h>

#include "struct.h"
#include "free.h"
#include "new.h"

int new_statement(
	struct statement** new,
	enum statement_kind kind,
	struct statement_inheritance* inheritance,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
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
		
		this->first_line = first_line;
		this->first_column = first_column;
		this->last_line = last_line;
		this->last_column = last_column;
		
		*new = this;
	}
	
	EXIT;
	return error;
}













