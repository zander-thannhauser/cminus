
#include <stdio.h>

#include <debug.h>

#include <memory/tinc.h>
/*#include <memory/tfree.h>*/

/*#include <scope/variable.h>*/

#include <type/struct/field/struct.h>
/*#include <type/array/struct.h>*/
/*#include <type/pointer/new.h>*/

/*#include "../kind.h"*/
#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_field_access_expression(
	struct expression** new,
	struct yylloc* loc,
	struct expression* inner,
	struct struct_field* field)
{
	int error = 0;
	struct field_access_expression* this = NULL;
	ENTER;
	
	error = new_expression(
		(struct expression**) &this,
		/* kind: */ ek_field_access,
		/* inheritance: */ &field_access_expression_inheritance,
		/* location: */ loc,
		/* type: */ field->type,
		sizeof(*this));
	
	if (!error)
	{
		this->inner = tinc(inner);
		this->field = tinc(field);
		
		*new = (struct expression*) this;
	}
	
	EXIT;
	return error;
}










