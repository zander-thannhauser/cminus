
#include <stdint.h>
#include <stdio.h>

#include <error.h>
#include <debug.h>

/*#include <defines/argv0.h>*/

#include <memory/tinc.h>

#include <type/integer/struct.h>
#include <type/compare.h>

#include <expression/literal/struct.h>
#include <expression/literal/new.h>

#include "../new.h"

/*#include "constfolders.h"*/
#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_cast_expression(
	struct expression** new,
	struct yylloc* loc,
	struct type* after,
	struct expression* inner)
{
	int error = 0;
	ENTER;
	
	struct type* const before = inner->type;
	
	if (!compare_types(after, before))
	{
		// no cast necessary
		*new = tinc(inner);
	}
	else if (true
		&& inner->kind == ek_literal
		&& after->kind == tk_integer
		&& before->kind == tk_integer)
	{
		uintmax_t val;
		struct literal_expression* spef = (typeof(spef)) inner;
		struct integer_type* bspef = (typeof(bspef)) before;
		struct integer_type* aspef = (typeof(aspef)) after;
		
		switch (bspef->kind)
		{
			case ik_signed_int:
				val = (uintmax_t) spef->value._signed_int;
				break;
			
			default:
				// fill out the rest
				TODO;
				break;
		}
		
		dpv(val);
		
		switch (aspef->kind)
		{
			case ik_signed_long:
				error = new_literal_expression_as_signed_long(new,
					inner->loc, after, val);
				break;
			
			case ik_unsigned_long:
				error = new_literal_expression_as_unsigned_long(new,
					inner->loc, after, val);
				break;
			
			default:
				// fill out the rest
				TODO;
				break;
		}
	}
	else if (
		false
		|| (before->kind == tk_integer && after->kind == tk_integer)
		|| (before->kind == tk_integer && after->kind == tk_float)
		|| (before->kind == tk_float && after->kind == tk_integer)
		|| (before->kind == tk_float && after->kind == tk_float))
	{
		struct cast_expression* this = NULL;
		
		error = new_expression(
			(struct expression**) &this,
			ek_cast,
			&cast_expression_inheritance,
			loc,
			after,
			sizeof(*this));
		
		if (!error)
		{
			this->type = tinc(after);
			this->inner = tinc(inner);
			
			*new = (struct expression*) this;
		}
	}
	else
	{
		error = 1;
		TODO;
	}
	
	EXIT;
	return error;
}












