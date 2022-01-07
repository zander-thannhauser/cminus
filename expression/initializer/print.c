
#include <debug.h>
#include <enums/error.h>

#include <misc/sfprintf.h>

#include <parser/initializer/print.h>

#include <type/print.h>

#include "struct.h"
#include "print.h"

int initializer_expression_print(
	struct expression* super,
	FILE* stream)
{
	int error = 0;
	struct initializer_expression* const this = (typeof(this)) super;
	ENTER;
	
	error = 0
		?: sfprintf(stream, "(")
		?: type_print(super->type, NULL, stream)
		?: sfprintf(stream, ") ")
		?: initializer_print(this->initializer, stream);
	
	EXIT;
	return error;
}


















