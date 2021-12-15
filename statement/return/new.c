
#include <debug.h>

#include <memory/tinc.h>

#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_return_statement(
	struct return_statement** new,
	unsigned line,
	bool is_integer_result,
	char* funcname,
	struct expression* return_value)
{
	int error = 0;
	ENTER;
	
	dpvb(is_integer_result);
	
	struct return_statement* this = NULL;
	
	error = new_statement(
		(struct statement**) &this,
		sk_return,
		&return_statement_inheritance,
		line,
		sizeof(*this));
	
	if (!error)
	{
		this->is_integer_result = is_integer_result;
		
		this->funcname = funcname;
		this->return_value = tinc(return_value);
		
		*new = this;
	}
	
	EXIT;
	return error;
}

