
#include <stdio.h>

/*#include <error.h>*/
#include <assert.h>

#include <enums/error.h>
#include <defines/argv0.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

/*#include <memory/tfree.h>*/

#include <type/struct.h>
#include <type/print.h>
#include <type/array/struct.h>
#include <type/pointer/struct.h>

#include <types/struct.h>

#include <expression/struct.h>
#include <expression/cast/new.h>
/*#include <expression/literal/new.h>*/
/*#include <expression/binary/new.h>*/
/*#include <expression/unary/new.h>*/

#include <parser/yylloc/new.h>

#include <expression/array_index/new.h>

#include "array_index.h"

int postfix_expression_array_index_callback(
	struct expression** out,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* array,
	struct expression* index,
	struct types* types)
{
	int error = 0;
	struct expression* casted_index = NULL;
	struct type* element_type = NULL;
	struct yylloc* loc = NULL;
	ENTER;
	
	if (index->type->kind != tk_integer)
	{
		TODO;
		error = 1;
	}
	else switch (array->type->kind)
	{
		case tk_array:
		{
			struct array_type* spef = (typeof(spef)) array->type;
			element_type = tinc(spef->element_type);
			break;
		}
		
		case tk_pointer:
		{
			struct pointer_type* spef = (typeof(spef)) array->type;
			element_type = tinc(spef->dereference);
			break;
		}
		
		default:
			fprintf(stderr, "%s: type `", argv0);
			type_print(array->type, NULL, stderr);
			fprintf(stderr, "` cannot be used as array in array index!\n");
			error = e_bad_input_file;
			break;
	}
	
	if (!error)
		error = 0
			?: new_yyloc(&loc, first_line, first_column, last_line, last_column)
			?: new_cast_expression(&casted_index, NULL,
				types->integers[ik_signed_long], index)
			?: new_array_index_expression(out,
				loc, array, casted_index, element_type);
	
	tfree(loc);
	tfree(element_type);
	tfree(casted_index);
	tfree(array);
	tfree(index);
	
	EXIT;
	return error;
}

































