
#include <string.h>

#include <debug.h>

#include <misc/sfprintf.h>

#include "struct.h"
#include "print.h"

static const char* lookup[number_of_float_kinds] = 
{
	[fk_float] = "float",
	[fk_double] = "double",
};

int float_type_print(
	const struct type* super,
	char* name,
	FILE* stream)
{
	int error = 0;
	const struct float_type* const this = (typeof(this)) super;
	ENTER;
	
	if (!error && super->qualifiers[tq_constant])
		error = sfprintf(stream, "const ");
	
	if (!error && super->qualifiers[tq_volatile])
		error = sfprintf(stream, "volatile ");
	
	const char* tname = lookup[this->kind];
	
	dpvs(tname);
	assert(tname);
	
	if (!error)
		error = sfprintf(stream, "%s", tname);
	
	if (!error && name)
		error = sfprintf(stream, " %s", name);
	
	EXIT;
	return error;
}

















