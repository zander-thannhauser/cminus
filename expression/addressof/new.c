
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

int new_addressof_expression(
	struct expression** new,
	struct yylloc* loc,
	struct expression* inner,
	struct type* type)
{
	int error = 0;
	struct addressof_expression* this = NULL;
	ENTER;
	
	error = new_expression(
		(struct expression**) &this,
		/* kind: */ ek_addressof,
		/* inheritance: */ &addressof_expression_inheritance,
		/* location: */ loc,
		/* type: */ type,
		sizeof(*this));
	
	if (!error)
	{
		this->inner = tinc(inner);
		
		*new = (struct expression*) this;
	}
	
	EXIT;
	return error;
}










