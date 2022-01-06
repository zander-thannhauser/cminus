
#include <stdio.h>

#include <error.h>
#include <debug.h>

/*#include <defines/argv0.h>*/

#include <memory/tinc.h>

#include <type/struct.h>
/*#include <type/primitive/struct.h>*/
#include <type/compare.h>

#include "../new.h"

/*#include "constfolders.h"*/
#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_cast_expression(
	struct expression** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct type* after,
	struct expression* inner,
	struct types* types)
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
		TODO;
		#if 0
		if (before->kind == tk_integer && after->kind == tk_integer)
		{
			TODO;
		}
		else if (before->kind == tk_integer && after->kind == tk_float)
		{
			struct integer_type* ibt = (typeof(ibt)) before;
			struct float_type* fat = (typeof(fat)) after;
			
			TODO;
		}
		else if (before->kind == tk_float && after->kind == tk_integer)
		{
			TODO;
		}
		else if (before->kind == tk_float && after->kind == tk_float)
		{
			TODO;
		}
		else
		{
			TODO;
			error = 1;
		}
		#endif
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
			first_line, first_column,
			last_line, last_column,
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












