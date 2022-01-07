
#include <string.h>
#include <stdlib.h>

#include <debug.h>

#include <char/printable.h>

#include <misc/sfprintf.h>

#include <type/integer/struct.h>
#include <type/float/struct.h>

/*#include "../print.h"*/

#include "struct.h"
#include "print.h"

int literal_expression_print(
	struct expression* super,
	FILE* stream)
{
	int error = 0;
	struct literal_expression* const this = (typeof(this)) super;
	ENTER;
	
	struct type* type = super->type;
	
	assert(type->kind == tk_integer || type->kind == tk_float);
	
	if (type->kind == tk_integer)
	{
		struct integer_type* itype = (typeof(itype)) type;
		
		switch (itype->kind)
		{
			case ik_signed_char:
				error = sfprintf(stream,
					index(printable, this->value._signed_char)
					? "'%c'" : "'%hhi'", this->value._signed_char);
				break;
			
			case ik_unsigned_char:
				error = sfprintf(stream, "%hhu", this->value._unsigned_char);
				break;
			
			case ik_signed_short:
				error = sfprintf(stream, "%hi", this->value._signed_short);
				break;
			case ik_unsigned_short:
				error = sfprintf(stream, "%hu", this->value._signed_short);
				break;
			
			case ik_signed_int:
				error = sfprintf(stream, "%i", this->value._signed_int);
				break;
			case ik_unsigned_int:
				error = sfprintf(stream, "%u", this->value._signed_int);
				break;
			
			case ik_signed_long:
				error = sfprintf(stream, "%liL", this->value._signed_long);
				break;
			case ik_unsigned_long:
				error = sfprintf(stream, "%luUL", this->value._signed_long);
				break;
			
			case number_of_integer_kinds: abort();
		}
	}
	else
	{
		struct float_type* ftype = (typeof(ftype)) type;
		
		switch (ftype->kind)
		{
			case fk_float:
				error = sfprintf(stream, "%gf", this->value._float);
				break;
				
			case fk_double:
				error = sfprintf(stream, "%lglf", this->value._double);
				break;
			
			case number_of_float_kinds: abort();
		}
	}
	
	EXIT;
	return error;
}















