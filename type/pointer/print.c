
#include <assert.h>

#include <misc/sfprintf.h>

#include "../print.h"

#include "struct.h"
#include "print.h"

int pointer_type_print(
	const struct type* super,
	char* name,
	FILE* stream)
{
	int error = 0;
	const struct pointer_type* const this = (typeof(this)) super;
	ENTER;
	
	error = type_print(this->dereference, NULL, stream);
	
	if (!error)
		error = sfprintf(stream, "*");
	
	if (!error && super->qualifiers[tq_constant])
		error = sfprintf(stream, " const");
	
	if (!error && super->qualifiers[tq_volatile])
		error = sfprintf(stream, " volatile");
	
	if (!error && name)
		error = sfprintf(stream, " %s", name);
	
	EXIT;
	return error;
}
















