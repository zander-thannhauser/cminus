
#include <string.h>

#include <debug.h>

#include <misc/sfprintf.h>

#include "struct.h"
#include "print.h"

static const char* lookup[number_of_integer_kinds] = 
{
	[ik_signed_char] = "signed char",
	[ik_unsigned_char] = "unsigned char",
	
	[ik_signed_short] = "signed short",
	[ik_unsigned_short] = "unsigned short",
	
	[ik_signed_int] = "signed int",
	[ik_unsigned_int] = "unsigned int",
	
	[ik_signed_long] = "signed long",
	[ik_unsigned_long] = "unsigned long",
};

int integer_type_print(
	const struct type* super,
	char* name,
	FILE* stream)
{
	int error = 0;
	const struct integer_type* const this = (typeof(this)) super;
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
















