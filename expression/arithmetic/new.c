
#include <stdlib.h>

#include <assert.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <type/struct.h>
#include <type/compare.h>

#include <types/struct.h>

#include "../new.h"

#include "inheritance.h"
#include "constfolders.h"
#include "struct.h"
#include "new.h"

int new_arithmetic_expression(
	struct expression** new,
	struct yylloc* loc,
	enum arithmetic_expression_kind kind,
	struct expression* left,
	struct expression* right,
	struct types* types)
{
	int error = 0;
/*	enum primitive_kind params_kind;*/
	struct arithmetic_expression* this;
	struct type* const ltype = left->type;
	struct type* const rtype = right->type;
	ENTER;
	
	// it's assumed that at this point left and right have the same types.
	assert(!compare_types(ltype, rtype));
	
	if (true
		&& left->kind == ek_literal
		&& right->kind == ek_literal
		&& ltype->kind == tk_integer)
	{
		error = arithmetic_constfolders[kind](
			(struct literal_expression**) new,
			(struct literal_expression*) left,
			(struct literal_expression*) right,
			loc,
			types);
	}
	else
	{
		error = new_expression(
			(struct expression**) &this,
			ek_arithmetic,
			&arithmetic_expression_inheritance,
			loc,
			ltype, sizeof(*this));
		
		if (!error)
		{
			this->kind = kind;
			
			this->is_float_result = (ltype->kind == tk_float);
			
			this->left = tinc(left);
			this->right = tinc(right);
			
			*new = (struct expression*) this;
		}
	}
	
	EXIT;
	return error;
}












