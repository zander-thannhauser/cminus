
#include <stdlib.h>

#include <debug.h>

/*#include <memory/tinc.h>*/
/*#include <memory/tfree.h>*/

#include <type/struct.h>
/*#include <type/is_equal.h>*/

#include <types/struct.h>

#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_relational_expression(
	struct expression** new,
	struct yylloc* loc,
	enum relational_expression_kind kind,
	struct expression* left,
	struct expression* right,
	struct types* types)
{
	int error = 0;
	ENTER;
	
	struct relational_expression* this = NULL;
	
	error = new_expression(
		(struct expression**) &this,
		ek_relational,
		&relational_expression_inheritance,
		loc,
		types->integers[ik_signed_int],
		sizeof(*this));
	
	if (!error)
	{
		this->kind = kind;
		
		this->comparing_floats = left->type->kind == tk_float;
		
		this->left = tinc(left);
		this->right = tinc(right);
		
		*new = (struct expression*) this;
	}
	
	EXIT;
	return error;
}












