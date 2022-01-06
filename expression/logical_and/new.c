
#include <stdlib.h>

#include <debug.h>

#include <memory/tinc.h>
/*#include <memory/tfree.h>*/

#include <type/struct.h>
/*#include <type/is_equal.h>*/

#include <types/struct.h>

#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_logical_and_expression(
	struct expression** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* left,
	struct expression* right,
	struct types* types)
{
	int error = 0;
/*	enum primitive_kind params_kind;*/
/*	struct type* const rtype = right->type;*/
/*	struct type* const ltype = left->type;*/
	ENTER;
	
	TODO;
	#if 0
	if (!left->type->is_complete || !right->type->is_complete)
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
		struct logical_and_expression* this = NULL;
		
			error = new_expression(
				(struct expression**) &this,
				ek_logical_and,
				&logical_and_expression_inheritance,
				first_line, first_column,
				last_line, last_column,
				types->integers[ik_bool], sizeof(*this));
		
		if (!error)
		{
			this->left = tinc(left);
			this->right = tinc(right);
			
			*new = (struct expression*) this;
		}
	}
	#endif
	
	EXIT;
	return error;
}












