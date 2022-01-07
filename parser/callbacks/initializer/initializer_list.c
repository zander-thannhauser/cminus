
#include <debug.h>

#include <parser/yylloc/new.h>

#include <parser/initializer/new.h>

#include "initializer_list.h"

int initializer_initializer_list_callback(
	struct initializer** out,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct initializer_ll* list)
{
	int error = 0;
	struct yylloc* loc = NULL;
	ENTER;
	
	error = 0
		?: new_yyloc(&loc, first_line, first_column, last_line, last_column)
		?: new_initializer_as_initializer_ll(out, loc, list);
	
	tfree(list);
	tfree(loc);
	
	EXIT;
	return error;
}

