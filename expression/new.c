
#include <assert.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>

#include "struct.h"
#include "free.h"
#include "new.h"

int new_expression(
	struct expression** new,
	enum expression_kind kind,
	struct expression_inheritance* inheritance,
	struct yylloc* loc,
	struct type* type,
	size_t alloc_size)
{
	int error = 0;
	ENTER;
	
	struct expression* this = NULL;
	
	error = tmalloc(
		(void**) &this, alloc_size,
		(void (*)(void*)) free_expression);
	
	if (!error)
	{
		this->kind = kind;
		
		this->inheritance = inheritance;
		
		this->loc = tinc(loc);
		
		this->type = tinc(type);
		
		dpv(inheritance);
		
		*new = this;
	}
	
	EXIT;
	return error;
}





