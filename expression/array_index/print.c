
#include <debug.h>

#include <enums/error.h>

#include <misc/sfprintf.h>

#include "../print.h"

#include "struct.h"
#include "print.h"

int array_index_expression_print(
	struct expression* super,
	FILE* stream)
{
	int error = 0;
	struct array_index_expression* const this = (typeof(this)) super;
	ENTER;
	
	error = 0
		?: expression_print(this->array, stream)
		?: sfprintf(stream, "[")
		?: expression_print(this->index, stream)
		?: sfprintf(stream, "]");
	
	EXIT;
	return error;
}

