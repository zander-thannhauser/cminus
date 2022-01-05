
#include <debug.h>

#include <memory/tinc.h>
/*#include <memory/tfree.h>*/

/*#include <type/pointer/struct.h>*/
/*#include <type/pointer/new.h>*/

/*#include <types/struct.h>*/

#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_parentheses_expression(
	struct expression** new,
	struct expression* inner)
{
	int error = 0;
	ENTER;
	
	struct parentheses_expression* this = NULL;
	
	if (!error)
		error = new_expression(
			(struct expression**) &this,
			ek_parentheses, &parentheses_expression_inheritance,
			inner->type, sizeof(*this));
	
	if (!error)
	{
		this->inner = tinc(inner);
		
		*new = (struct expression*) this;
	}
	
	
	EXIT;
	return error;
}












