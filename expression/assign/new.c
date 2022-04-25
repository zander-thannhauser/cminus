
#include <stdlib.h>

#include <assert.h>

#include <memory/tinc.h>
/*#include <memory/tfree.h>*/

/*#include <type/struct.h>*/
/*#include <type/is_equal.h>*/

/*#include <types/struct.h>*/

#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_assign_expression(
	struct expression** new,
	struct yylloc* loc,
	enum assign_expression_kind kind,
	struct expression* left,
	struct expression* right,
	struct types* types)
{
	int error = 0;
	ENTER;
	
	struct assign_expression* this = NULL;
	
	error = new_expression(
		(struct expression**) &this,
		ek_assign, &assign_expression_inheritance,
		loc,
		left->type,
		sizeof(*this));
	
	if (!error)
	{
		this->kind = kind;
		
		this->left = tinc(left);
		this->right = tinc(right);
		
		*new = (struct expression*) this;
	}
	
	EXIT;
	return error;
}

















