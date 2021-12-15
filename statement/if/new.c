
#include <debug.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <types/struct.h>

#include <expression/cast/new.h>

#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_if_statement(
	struct if_statement** new,
	struct expression* conditional,
	struct statement* true_case,
	struct statement* false_case,
	struct types* types)
{
	int error = 0;
	struct expression* casted_conditional = NULL;
	ENTER;
	
	TODO;
	#if 0
	struct if_statement* this = NULL;
	
	error = 0
		?: new_cast_expression(
			&casted_conditional,
			types->primitives[pk_bool],
			conditional, types)
		?: new_statement(
			(struct statement**) &this,
			sk_if, &if_statement_inheritance,
			sizeof(*this));
	
	if (!error)
	{
		this->conditional = tinc(casted_conditional);
		this->true_case = tinc(true_case);
		this->false_case = tinc(false_case);
		
		*new = this;
	}
	
	tfree(casted_conditional);
	#endif
	
	EXIT;
	return error;
}

