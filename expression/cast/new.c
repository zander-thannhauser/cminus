
#include <stdio.h>

#include <error.h>
#include <debug.h>

#include <defines/argv0.h>

#include <memory/tinc.h>

/*#include <type/primitive/struct.h>*/
#include <type/is_equal.h>

#include "../new.h"

#include "constfolders.h"
#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_cast_expression(
	struct expression** new,
	struct type* after,
	struct expression* inner,
	struct types* types)
{
	int error = 0;
	ENTER;
	
	// support floats:
	
	struct type* const before = inner->type;
	
	if (type_is_equal(after, before))
	{
		// no cast necessary
		*new = tinc(inner);
	}
	else
	{
		TODO;
	}
	
	#if 0
	else if (false
		|| (after->kind != tk_primitive && after->kind != tk_pointer)
		|| (before->kind != tk_primitive && before->kind != tk_pointer))
	{
		TODO;
		error = 1;
	}
	else if (true
		&& inner->kind == ek_literal
		&& after->kind == tk_primitive
		&& before->kind == tk_primitive)
	{
		struct primitive_type const* pt = (typeof(pt)) after;
		
		dpv(pt->kind);
		
		assert(cast_constfolders[pt->kind]);
		
		error = cast_constfolders[pt->kind](
			(struct literal_expression**) new,
			(struct literal_expression*) inner,
			types);
	}
	else
	{
		// gareenteed to be primitive or pointer?
		
		struct cast_expression* this = NULL;
		
		error = new_expression(
			(struct expression**) &this,
			ek_cast,
			&cast_expression_inheritance,
			after,
			sizeof(*this));
		
		if (!error)
		{
			this->type = tinc(after);
			this->inner = tinc(inner);
			
			*new = (struct expression*) this;
		}
	}
	#endif
	
	EXIT;
	return error;
}












