
#include <assert.h>

#include <memory/tfree.h>

#include <type/struct.h>
#include <types/struct.h>

#include <expression/literal/new.h>

#include <parser/yylloc/new.h>

#include "sizeof_type.h"

int unary_expression_sizeof_type_callback(
	struct expression** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct type* type,
	struct types* types)
{
	int error = 0;
	struct yylloc* loc = NULL;
	ENTER;
	
	dpv(type->size);
	
	if (!type->is_complete)
	{
		TODO;
		error = 1;
	}
	
	if (!error)
		error = 0
			?: new_yyloc(&loc,
				first_line, first_column,
				last_line, last_column)
			?: new_literal_expression_as_unsigned_long(
				(struct expression**) retval,
				/* location: */ loc,
				/* type: */ types->integers[ik_unsigned_long],
				/* value: */ type->size);
	
	tfree(loc);
	tfree(type);
	
	EXIT;
	return error;
}



















