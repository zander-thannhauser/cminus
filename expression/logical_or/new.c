
#include <stdlib.h>

#include <debug.h>

/*#include <memory/tinc.h>*/
/*#include <memory/tfree.h>*/

/*#include <type/struct.h>*/
/*#include <type/is_equal.h>*/

/*#include <types/struct.h>*/

#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_logical_or_expression(
	struct expression** new,
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
	if (true
		&& left->kind == ek_literal
		&& right->kind == ek_literal
		&& ltype->kind == tk_integer)
	{
		error = binary_constfolders[kind](
			(struct literal_expression**) new,
			(struct literal_expression*) left,
			(struct literal_expression*) right,
			types);
	}
	else
	{
		struct type* type = NULL;
		
		switch (kind)
		{
			case bek_less_than:
			case bek_greater_than:
			case bek_less_than_equal_to:
			case bek_greater_than_equal_to:
			case bek_logical_and:
			case bek_logical_or:
			case bek_equal_to:
			case bek_not_equal_to:
			{
				type = tinc(types->integers[ik_bool]);
				break;
			}
			
			case bek_add:
			case bek_divide:
			case bek_leftshift:
			case bek_multiply:
			case bek_rdivide:
			case bek_rightshift:
			case bek_subtract:
				type = tinc(ltype);
				break;
			
			case number_of_logical_or_expressions:
				abort();
		}
		
		struct logical_or_expression* this = NULL;
		
		if (!error)
			error = new_expression(
				(struct expression**) &this,
				ek_binary, &logical_or_expression_inheritance,
				type, sizeof(*this));
		
		if (!error)
		{
			this->kind = kind;
			
			this->is_float_result = (type->kind == tk_float);
			
			this->left = tinc(left);
			this->right = tinc(right);
			
			*new = (struct expression*) this;
		}
		
		tfree(type);
	}
	#endif
	
	EXIT;
	return error;
}












