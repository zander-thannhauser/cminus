
#include <debug.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>

#include "struct.h"
#include "free.h"
#include "new.h"

int new_expression(
	struct expression** new,
	enum expression_kind kind,
	struct expression_inheritance* inheritance,
	unsigned first_line, unsigned first_column,
	unsigned last_line,  unsigned last_column,
	struct type* type,
	size_t alloc_size)
{
	int error = 0;
	ENTER;
	
	dpv(first_line);
	dpv(first_column);
	dpv(last_line);
	dpv(last_column);
	
	struct expression* this = NULL;
	
	error = tmalloc(
		(void**) &this, alloc_size,
		(void (*)(void*)) free_expression);
	
	if (!error)
	{
		this->kind = kind;
		
		this->inheritance = inheritance;
		
		this->first_line = first_line;
		this->first_column = first_column;
		this->last_line = last_line;
		this->last_column = last_column;
		
		this->type = tinc(type);
		
		dpv(inheritance);
		
		*new = this;
	}
	
	EXIT;
	return error;
}





