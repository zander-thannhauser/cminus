
#include <stdlib.h>

#include <debug.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <type/struct.h>
#include <type/is_equal.h>

#include <types/struct.h>

#include "../new.h"

#include "inheritance.h"
#include "constfolders.h"
#include "struct.h"
#include "new.h"

int new_binary_expression(
	struct expression** new,
	enum binary_expression_kind kind,
	struct expression* left,
	struct expression* right,
	struct types* types)
{
	int error = 0;
/*	enum primitive_kind params_kind;*/
	struct type* const ltype = left->type;
	ENTER;
	
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
			case bek_add_assign:
			case bek_bitwise_and_assign:
			case bek_bitwise_or_assign:
			case bek_bitwise_xor_assign:
			case bek_divide:
			case bek_divide_assign:
			case bek_leftshift:
			case bek_leftshift_assign:
			case bek_multiply:
			case bek_multiply_assign:
			case bek_rdivide:
			case bek_rdivide_assign:
			case bek_rightshift:
			case bek_rightshift_assign:
			case bek_regular_assign:
			case bek_subtract:
			case bek_subtract_assign:
				type = tinc(ltype);
				break;
			
			case number_of_binary_expressions:
				abort();
		}
		
		struct binary_expression* this = NULL;
		
		if (!error)
			error = new_expression(
				(struct expression**) &this,
				ek_binary, &binary_expression_inheritance,
				type, sizeof(*this));
		
		if (!error)
		{
			this->kind = kind;
			
			this->is_integer_result = type->kind == tk_integer;
			
			this->left = tinc(left);
			this->right = tinc(right);
			
			*new = (struct expression*) this;
		}
		
		tfree(type);
	}
	
	EXIT;
	return error;
}











