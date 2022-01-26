
#include <stdio.h>

#include <debug.h>

#include <enums/error.h>

#include <defines/argv0.h>

#include <memory/tfree.h>

#include <expression/literal/struct.h>
#include <expression/cast/new.h>

#include <types/struct.h>

#include <parser/ptree/declarator/array/new.h>

#include "array.h"

int direct_declarator_array_callback(
	struct declarator** new,
	struct declarator* inner,
	struct expression* size_expression,
	struct types* types)
{
	int error = 0;
	struct expression* casted = NULL;
	ENTER;
	
	TODO;
	#if 0
	if (size_expression->kind != ek_literal)
		fprintf(stderr, "%s: array size not constant!\n", argv0),
		error = e_bad_input_file;
	
	if (!error)
		error = new_cast_expression(&casted, NULL,
			types->integers[ik_unsigned_long], size_expression);
	
	if (!error)
	{
		size_t size;
		struct literal_expression* lit = (typeof(lit)) casted;
		
		size = lit->value._unsigned_long;
		
		dpv(size);
		
		error = new_array_declarator(
			(struct array_declarator**) new, inner, size);
	}
	#endif
	
	tfree(inner);
	tfree(size_expression);
	tfree(casted);
	
	EXIT;
	return error;
}










