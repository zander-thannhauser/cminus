
#include <debug.h>

#include <memory/tinc.h>

#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_expression_statement(
	struct expression_statement** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* expression)
{
	int error = 0;
	ENTER;
	
	struct expression_statement* this = NULL;
	
	error = new_statement(
		(struct statement**) &this,
		sk_expression,
		&expression_statement_inheritance,
		first_line, first_column,
		last_line, last_column,
		sizeof(*this));
	
	if (!error)
	{
		this->expression = tinc(expression);
		
		*new = this;
	}
	
	EXIT;
	return error;
}

