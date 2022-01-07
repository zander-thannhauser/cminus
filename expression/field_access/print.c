
#include <debug.h>
#include <enums/error.h>

#include <type/struct/field/struct.h>

#include <misc/sfprintf.h>

#include "../print.h"

#include "struct.h"
#include "print.h"

int field_access_expression_print(
	struct expression* super,
	FILE* stream)
{
	int error = 0;
	struct field_access_expression* const this = (typeof(this)) super;
	ENTER;
	
	error = 0
		?: expression_print(this->inner, stream)
		?: sfprintf(stream, ".%s", this->field->name);
	
	EXIT;
	return error;
}

