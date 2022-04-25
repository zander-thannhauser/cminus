
#include <string.h>

#include <assert.h>

#include <misc/sfprintf.h>

#include "../print.h"

#include "struct.h"
#include "print.h"

int array_type_print(
	const struct type* super,
	char* name,
	FILE* stream)
{
	int error = 0;
	const struct array_type* const this = (typeof(this)) super;
	ENTER;
	
	error = 0
		?: type_print(this->element_type, NULL, stream)
		?: (name ? sfprintf(stream, " %s", name) : 0)
		?: sfprintf(stream, "[%lu]", this->number_of_elements);
	
	EXIT;
	return error;
}

















