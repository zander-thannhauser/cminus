
#include <stdlib.h>

#include <assert.h>

#include <memory/tinc.h>
/*#include <memory/tfree.h>*/

#include <type/struct.h>
/*#include <type/is_equal.h>*/

#include <types/struct.h>

#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_logical_or_expression(
	struct expression** new,
	struct yylloc* loc,
	struct expression* left,
	struct expression* right,
	struct types* types)
{
	int error = 0;
/*	enum primitive_kind params_kind;*/
/*	struct type* const rtype = right->type;*/
/*	struct type* const ltype = left->type;*/
	ENTER;
	
	if (!left->type->is_complete || !right->type->is_complete)
	{
		TODO;
		error = 1;
	}
	else if (left->type->kind == tk_array || right->type->kind == tk_array)
	{
		TODO;
		error = 1;
	}
	else if (left->type->kind == tk_struct || right->type->kind == tk_struct)
	{
		TODO;
		error = 1;
	}
	else if (left->kind == ek_literal)
	{
		TODO;
	}
	else if (right->kind == ek_literal)
	{
		TODO;
	}
	else
	{
		struct logical_or_expression* this = NULL;
		
		error = new_expression(
			(struct expression**) &this,
			ek_logical_or,
			&logical_or_expression_inheritance,
			loc,
			types->integers[ik_signed_int],
			sizeof(*this));
		
		if (!error)
		{
			this->left = tinc(left);
			this->right = tinc(right);
			
			*new = (struct expression*) this;
		}
	}
	
	EXIT;
	return error;
}












