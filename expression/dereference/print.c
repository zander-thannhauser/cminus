
#include <assert.h>

/*#include <enums/error.h>*/

#include <misc/sfprintf.h>

#include "../print.h"

#include "struct.h"
#include "print.h"

int dereference_expression_print(
	struct expression* super,
	FILE* stream)
{
	int error = 0;
	struct dereference_expression* const this = (typeof(this)) super;
	ENTER;
	
	error = 0
		?: sfprintf(stream, "*(")
		?: expression_print(this->inner, stream)
		?: sfprintf(stream, ")");
	
	EXIT;
	return error;
}

