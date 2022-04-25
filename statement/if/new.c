
#include <assert.h>

#include <memory/tinc.h>

#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_if_statement(
	struct if_statement** new,
	struct yylloc* loc,
	struct expression* conditional,
	struct statement* true_case,
	struct statement* false_case)
{
	int error = 0;
	ENTER;
	
	struct if_statement* this = NULL;
	
	error = new_statement(
		(struct statement**) &this,
		sk_if,
		&if_statement_inheritance,
		loc,
		sizeof(*this));
	
	if (!error)
	{
		this->conditional = tinc(conditional);
		this->true_case = tinc(true_case);
		this->false_case = tinc(false_case);
		
		*new = this;
	}
	
	EXIT;
	return error;
}













