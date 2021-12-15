
#include <string.h>

#include <debug.h>

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

void integer_type_print(
	const struct type* super,
	FILE* stream)
{
	const struct integer_type* const this = (typeof(this)) super;
	ENTER;
	
	if (super->qualifiers[tq_constant]) fputs("const ", stream);
	if (super->qualifiers[tq_volatile]) fputs("volatile ", stream);
	
	const char* name = lookup[this->kind];
	
	dpvs(name);
	
	assert(name);
	
	fwrite(name, strlen(name), 1, stream);
	
	EXIT;
}
















