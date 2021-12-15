
#include <string.h>

#include <debug.h>

#include "struct.h"
#include "print.h"

static const char* lookup[number_of_float_kinds] = 
{
	[fk_float] = "float",
	[fk_double] = "double",
};

void float_type_print(
	const struct type* super,
	FILE* stream)
{
	const struct float_type* const this = (typeof(this)) super;
	ENTER;
	
	if (super->qualifiers[tq_constant]) fputs("const ", stream);
	if (super->qualifiers[tq_volatile]) fputs("volatile ", stream);
	
	const char* name = lookup[this->kind];
	
	dpvs(name);
	
	assert(name);
	
	fwrite(name, strlen(name), 1, stream);
	
	EXIT;
}
















