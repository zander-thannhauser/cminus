
#include <debug.h>

#include <memory/tinc.h>

#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_compound_statement(
	struct compound_statement** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct statement_ll* statements)
{
	int error = 0;
	ENTER;
	
	struct compound_statement* this = NULL;
	
	error = new_statement(
		(struct statement**) &this,
		sk_compound,
		&compound_statement_inheritance,
		first_line, first_column,
		last_line, last_column,
		sizeof(*this));
	
	if (!error)
	{
		this->statements = tinc(statements);
		
		*new = this;
	}
	
	EXIT;
	return error;
}

