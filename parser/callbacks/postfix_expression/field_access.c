
#include <debug.h>

#include <type/struct.h>
#include <type/struct/get_field.h>

#include <expression/struct.h>
#include <expression/field_access/new.h>

#include <parser/yylloc/new.h>

#include "field_access.h"

int postfix_expression_field_access_callback(
	struct expression** out,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* inner,
	char* field_name)
{
	int error = 0;
	struct yylloc* loc = NULL;
	ENTER;
	
	struct type* const t = inner->type;
	
	if (t->kind != tk_struct)
	{
		TODO;
		error = 1;
	}
	
	struct struct_type* st;
	
	struct struct_field* field = NULL;
	
	if (!error)
	{
		st = (typeof(st)) t;
		error = 0
			?: new_yyloc(&loc, first_line, first_column, last_line, last_column)
			?: struct_type_get_field(&field, st, field_name)
			?: new_field_access_expression(out, loc, inner, field);
	}
	
	tfree(loc);
	tfree(field);
	tfree(inner);
	tfree(field_name);
	
	EXIT;
	return error;
}
















