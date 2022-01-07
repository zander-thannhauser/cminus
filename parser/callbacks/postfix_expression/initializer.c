
#include <debug.h>

#include <memory/tfree.h>

#include <type/struct.h>

#include <scope/declare/initializer.h>

#include <expression/initializer/new.h>

#include <parser/yylloc/new.h>
#include <parser/initializer/new.h>

#include "initializer.h"

int postfix_expression_initializer_callback(
	struct expression** out,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct scope* scope,
	struct type* type,
	struct initializer_ll* initializer_ll)
{
	int error = 0;
	struct initializer* initializer = NULL;
	struct yylloc* loc = NULL;
	size_t offset;
	ENTER;
	
	dpv(type);
	
	error = 0
		?: new_yyloc(&loc, first_line, first_column, last_line, last_column)
		?: scope_declare_initializer(&offset, scope, type->size)
		?: new_initializer_as_initializer_ll(&initializer, NULL, initializer_ll)
		?: new_initializer_expression(out, loc, initializer, offset, type);
	
	tfree(initializer);
	tfree(initializer_ll);
	tfree(type);
	tfree(loc);
	
	EXIT;
	return error;
}

