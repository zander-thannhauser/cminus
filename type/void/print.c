
/*#include <string.h>*/

#include <debug.h>

#include <misc/sfprintf.h>

#include "struct.h"
#include "print.h"

int void_type_print(
	const struct type* super,
	char* name,
	FILE* stream)
{
	int error = 0;
	const struct void_type* const this = (typeof(this)) super;
	ENTER;
	
	error = sfprintf(stream, "void");
	
	EXIT;
	return error;
}

















