
#include <debug.h>

#include <memory/tinc.h>

#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_return_statement(
	struct return_statement** new,
	unsigned line,
	struct expression* return_value)
{
	int error = 0;
	ENTER;
	
	struct return_statement* this = NULL;
	
	error = new_statement(
		(struct statement**) &this,
		sk_return,
		&return_statement_inheritance,
		line,
		sizeof(*this));
	
	if (!error)
	{
		this->return_value = tinc(return_value);
		
		*new = this;
	}
	
	EXIT;
	return error;
}

