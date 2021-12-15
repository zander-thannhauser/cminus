
#include <string.h>
#include <stdlib.h>

#include <debug.h>

#include <char/printable.h>

#include <type/integer/struct.h>
#include <type/float/struct.h>

/*#include "../print.h"*/

#include "struct.h"
#include "print.h"

void literal_expression_print(
	struct expression* super,
	FILE* stream)
{
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
				fprintf(stream, index(printable, this->value._signed_char)
					? "'%c'" : "'%hhi'", this->value._signed_char);
				break;
			
			case ik_unsigned_char: fprintf(stream, "%hhu", this->value._unsigned_char); break;
			
			case ik_signed_short:   fprintf(stream, "%hi", this->value._signed_short); break;
			case ik_unsigned_short: fprintf(stream, "%hu", this->value._signed_short); break;
			
			case ik_signed_int:   fprintf(stream, "%i", this->value._signed_int); break;
			case ik_unsigned_int: fprintf(stream, "%u", this->value._signed_int); break;
			
			case ik_signed_long:   fprintf(stream, "%li", this->value._signed_long); break;
			case ik_unsigned_long: fprintf(stream, "%lu", this->value._signed_long); break;
			
			case number_of_integer_kinds: abort();
		}
	}
	else
	{
		struct float_type* ftype = (typeof(ftype)) type;
		
		switch (ftype->kind)
		{
			case fk_float: fprintf(stream, "%g", this->value._float); break;
			case fk_double: fprintf(stream, "%lg", this->value._double); break;
			
			case number_of_float_kinds: abort();
		}
	}
	
	EXIT;
}







