
#include <debug.h>

#include "../print.h"

#include "struct.h"
#include "print.h"

void pointer_type_print(
	const struct type* super,
	FILE* stream)
{
	const struct pointer_type* const this = (typeof(this)) super;
	ENTER;
	
	type_print(this->dereference, stream);
	
	putc('*', stream);
	
	if (super->qualifiers[tq_constant]) fputs(" const", stream);
	if (super->qualifiers[tq_volatile]) fputs(" volatile", stream);
	
	EXIT;
}
















