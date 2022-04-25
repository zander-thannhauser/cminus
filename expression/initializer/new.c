
#include <stdio.h>

#include <assert.h>

#include <memory/tinc.h>
/*#include <memory/tfree.h>*/

#include <type/struct.h>
/*#include <type/array/struct.h>*/
/*#include <type/pointer/new.h>*/

/*#include "../kind.h"*/
#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_initializer_expression(
	struct expression** new,
	struct yylloc* loc,
	struct initializer* initializer,
	size_t stack_offset,
	struct type* type)
{
	int error = 0;
	struct initializer_expression* this = NULL;
	ENTER;
	
	error = new_expression(
		(struct expression**) &this,
		/* kind: */ ek_initializer,
		/* inheritance: */ &initializer_expression_inheritance,
		/* location: */ loc,
		/* type: */ type,
		sizeof(*this));
	
	if (!error)
	{
		this->initializer = tinc(initializer);
		this->stack_offset = stack_offset;
		
		*new = (struct expression*) this;
	}
	
	EXIT;
	return error;
}










