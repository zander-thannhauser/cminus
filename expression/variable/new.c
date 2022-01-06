
#include <stdio.h>

#include <debug.h>

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
	unsigned first_line, unsigned first_column,
	unsigned last_line,  unsigned last_column,
	struct variable* variable)
{
	int error = 0;
	struct type* type = NULL;
	struct variable_expression* this = NULL;
	ENTER;
	
	error = new_expression(
		(struct expression**) &this,
		/* kind: */ ek_variable,
		/* inheritance: */ &variable_expression_inheritance,
		/* first location: */ first_line, first_column,
		/* last location: */ last_line, last_column,
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










