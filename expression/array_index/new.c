
#include <stdio.h>

#include <assert.h>

#include <memory/tinc.h>
/*#include <memory/tfree.h>*/

/*#include <scope/variable.h>*/

/*#include <type/struct/field/struct.h>*/
/*#include <type/array/struct.h>*/
/*#include <type/pointer/new.h>*/

/*#include "../kind.h"*/
#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_array_index_expression(
	struct expression** new,
	struct yylloc* loc,
	struct expression* array,
	struct expression* index,
	struct type* type)
{
	int error = 0;
	struct array_index_expression* this = NULL;
	ENTER;
	
	error = new_expression(
		(struct expression**) &this,
		/* kind: */ ek_array_index,
		/* inheritance: */ &array_index_expression_inheritance,
		/* location: */ loc,
		/* type: */ type,
		sizeof(*this));
	
	if (!error)
	{
		this->array = tinc(array);
		this->index = tinc(index);
		
		*new = (struct expression*) this;
	}
	
	EXIT;
	return error;
}










