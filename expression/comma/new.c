
#include <stdlib.h>

#include <debug.h>

#include <memory/tinc.h>
/*#include <memory/tfree.h>*/

/*#include <type/struct.h>*/
/*#include <type/is_equal.h>*/

/*#include <types/struct.h>*/

#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_comma_expression(
	struct expression** new,
	struct yylloc* loc,
	struct expression* left,
	struct expression* right,
	struct types* types)
{
	int error = 0;
	ENTER;
	
	struct comma_expression* this = NULL;
		
	error = new_expression(
		(struct expression**) &this,
		ek_comma, &comma_expression_inheritance,
		loc, right->type, sizeof(*this));
	
	if (!error)
	{
		this->left = tinc(left);
		this->right = tinc(right);
		
		*new = (struct expression*) this;
	}
	
	EXIT;
	return error;
}












