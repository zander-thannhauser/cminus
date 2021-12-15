
#include <debug.h>

#include <memory/tinc.h>

#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_compound_statement(
	struct compound_statement** new,
	unsigned line,
	struct statement_ll* statements)
{
	int error = 0;
	ENTER;
	
	struct compound_statement* this = NULL;
	
	error = new_statement(
		(struct statement**) &this,
		sk_compound,
		&compound_statement_inheritance,
		line,
		sizeof(*this));
	
	if (!error)
	{
		this->statements = tinc(statements);
		
		*new = this;
	}
	
	EXIT;
	return error;
}

