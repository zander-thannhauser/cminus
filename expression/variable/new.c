
#include <stdio.h>

#include <assert.h>

#include <memory/tinc.h>
/*#include <memory/tfree.h>*/

#include <scope/variable.h>

/*#include <type/struct.h>*/
/*#include <type/array/struct.h>*/
/*#include <type/pointer/new.h>*/

/*#include "../kind.h"*/
#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_variable_expression(
	struct variable_expression** new,
	struct yylloc* loc,
	struct variable* variable)
{
	int error = 0;
/*	struct type* type = NULL;*/
	struct variable_expression* this = NULL;
	ENTER;
	
	error = new_expression(
		(struct expression**) &this,
		/* kind: */ ek_variable,
		/* inheritance: */ &variable_expression_inheritance,
		/* location: */ loc,
		/* type: */ variable->type,
		sizeof(*this));
	
	if (!error)
	{
		this->variable = tinc(variable);
		
		*new = this;
	}
	
	EXIT;
	return error;
}










