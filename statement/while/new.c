
#include <assert.h>

#include <memory/tinc.h>
/*#include <memory/tfree.h>*/

/*#include <types/struct.h>*/

/*#include <expression/cast/new.h>*/

#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_while_statement(
	struct while_statement** new,
	struct yylloc* loc,
	struct expression* conditional,
	struct statement* body)
{
	int error = 0;
	ENTER;
	
	struct while_statement* this = NULL;
	
	error = new_statement(
		(struct statement**) &this,
		sk_while,
		&while_statement_inheritance,
		loc,
		sizeof(*this));
	
	if (!error)
	{
		this->conditional = tinc(conditional);
		this->body = tinc(body);
		
		*new = this;
	}
	
	EXIT;
	return error;
}

