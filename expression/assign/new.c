
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

int new_assign_expression(
	struct expression** new,
	enum assign_expression_kind kind,
	struct expression* left,
	struct expression* right,
	struct types* types)
{
	int error = 0;
	struct type* const rtype = right->type;
	struct type* const ltype = left->type;
	ENTER;
	
	struct assign_expression* this = NULL;
	
	if (!error)
		error = new_expression(
			(struct expression**) &this,
			kind, &assign_expression_inheritance,
			ltype, sizeof(*this));
	
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

















