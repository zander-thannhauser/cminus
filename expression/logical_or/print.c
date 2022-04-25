
#include <assert.h>

#include <enums/error.h>

#include "../print.h"

#include "struct.h"
#include "print.h"

int logical_or_expression_print(
	struct expression* super,
	FILE* stream)
{
	int error = 0;
	struct logical_or_expression* const this = (typeof(this)) super;
	ENTER;
	
	error = 0
		?: expression_print(this->left, stream)
		?: (fprintf(stream, " || ") < 0 ? e_syscall_failed : 0)
		?: expression_print(this->right, stream);
	
	EXIT;
	return error;
}














