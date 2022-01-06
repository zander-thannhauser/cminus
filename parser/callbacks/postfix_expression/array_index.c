
#include <stdio.h>

/*#include <error.h>*/
#include <debug.h>

/*#include <defines/argv0.h>*/

/*#include <memory/tfree.h>*/

/*#include <type/struct.h>*/

/*#include <types/struct.h>*/

/*#include <expression/struct.h>*/
/*#include <expression/cast/new.h>*/
/*#include <expression/literal/new.h>*/
/*#include <expression/binary/new.h>*/
/*#include <expression/unary/new.h>*/

#include "array_index.h"

int postfix_expression_array_index_callback(
	struct expression** out,
	struct expression* array,
	struct expression* index,
	struct types* types)
{
	int error = 0;
	struct expression* casted_array = NULL;
	struct expression* casted_index = NULL;
	struct expression* sizeof_literal = NULL;
	struct expression* product = NULL;
	struct expression* sum = NULL;
	struct expression* casted_sum = NULL;
	ENTER;
	
	// needs to use array_index_expression instead,
	
	TODO;
	#if 0
	struct type* const type = array->type;
	
	if (type->kind != tk_pointer)
	{
		fprintf(stderr, "%s: cannot array-index a non-array non-pointer "
			"type!\n", argv0);
		error = e_bad_input_file;
	}
	else error = 0
		?: new_cast_expression(
			(struct expression**) &casted_array,
			types->primitives[pk_unsigned_long], array, types)
		?: new_cast_expression(
			(struct expression**) &casted_index,
			types->primitives[pk_unsigned_long], index, types)
		?: new_literal_expression_as_unsigned_long(
			(struct expression**) &sizeof_literal,
			types->primitives[pk_unsigned_long], type->size)
		?: new_binary_expression(
			(struct expression**) &product, bek_multiply,
			casted_index, sizeof_literal, types)
		?: new_binary_expression(
			(struct expression**) &sum, bek_add,
			casted_array, product, types)
		?: new_cast_expression(
			(struct expression**) &casted_sum,
			type, sum, types)
		?: new_unary_expression(
			(struct expression**) out, uek_dereference, casted_sum, types);
	
	tfree(casted_array);
	tfree(casted_index);
	tfree(sizeof_literal);
	tfree(product);
	tfree(sum);
	tfree(casted_sum);
	
	tfree(array);
	tfree(index);
	#endif
	
	EXIT;
	return error;
}


















