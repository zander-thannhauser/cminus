
#include <stdio.h>

#include <assert.h>

#include <memory/tinc.h>
/*#include <memory/tfree.h>*/

/*#include <scope/variable.h>*/

/*#include <type/struct.h>*/
/*#include <type/array/struct.h>*/
/*#include <type/pointer/new.h>*/

/*#include "../kind.h"*/
#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_ternary_expression(
	struct ternary_expression** new,
	struct yylloc* loc,
	struct expression* conditional,
	struct expression* true_expression,
	struct expression* false_expression)
{
	int error = 0;
/*	struct type* type = NULL;*/
	struct ternary_expression* this = NULL;
	ENTER;
	
	// at this point true_expression and false_expression
	// are assumed to produce the same type
	
	error = new_expression(
		(struct expression**) &this,
		/* kind: */ ek_variable,
		/* inheritance: */ &ternary_expression_inheritance,
		/* location: */ loc,
		/* type: */ true_expression->type,
		sizeof(*this));
	
	if (!error)
	{
		this->conditional = tinc(conditional);
		this->true_expression = tinc(true_expression);
		this->false_expression = tinc(false_expression);
		
		*new = this;
	}
	
	EXIT;
	return error;
}










