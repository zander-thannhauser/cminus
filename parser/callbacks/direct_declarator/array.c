
#include <stdio.h>

#include <debug.h>
#include <error.h>

#include <defines/argv0.h>

#include <memory/tfree.h>

#include <expression/struct.h>
#include <expression/literal/struct.h>

#include <parser/ptree/declarator/array/new.h>

#include "array.h"

int direct_declarator_array_callback(
	struct declarator** new,
	struct declarator* inner,
	struct expression* size_expression)
{
	int error = 0;
	ENTER;
	
	TODO;
	#if 0
	if (size_expression->kind != ek_literal)
		fprintf(stderr, "%s: array size not constant!\n", argv0),
		error = e_bad_input_file;
	else
	{
		size_t size;
		struct literal_expression* lit = (typeof(lit)) size_expression;
		
		switch (lit->kind)
		{
			case pk_unsigned_long: size = lit->value._unsigned_long; break;
			
			default:
				TODO;
				break;
		}
		
		if (!error)
			error = new_array_declarator(
				(struct array_declarator**) new, inner, size);
	}
	
	tfree(inner);
	tfree(size_expression);
	#endif
	
	EXIT;
	return error;
}










