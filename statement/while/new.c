
#include <debug.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <types/struct.h>

#include <expression/cast/new.h>

#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_while_statement(
	struct while_statement** new,
	struct expression* conditional,
	struct statement* body,
	struct types* types)
{
	int error = 0;
/*	struct expression* casted_conditional = NULL;*/
	ENTER;
	
	TODO;
	#if 0
	struct while_statement* this = NULL;
	
	error = 0
		?: new_cast_expression(
			&casted_conditional,
			types->primitives[pk_bool],
			conditional, types)
		?: new_statement(
			(struct statement**) &this,
			sk_while,
			&while_statement_inheritance,
			sizeof(*this));
	
	if (!error)
	{
		this->conditional = tinc(casted_conditional);
		this->body = tinc(body);
		
		*new = this;
	}
	
	tfree(casted_conditional);
	#endif
	
	EXIT;
	return error;
}

