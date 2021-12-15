
#include <string.h>
#include <stdlib.h>

#include <debug.h>

/*#include <char/printable.h>*/

#include <type/print.h>

/*#include <type/integer/struct.h>*/
/*#include <type/float/struct.h>*/

#include "../print.h"

#include "struct.h"
#include "print.h"

void cast_expression_print(
	struct expression* super,
	FILE* stream)
{
	struct cast_expression* const this = (typeof(this)) super;
	ENTER;
	
	putc('(', stream);
	
	type_print(this->type, stream);
	
	putc(')', stream);
	
	expression_print(this->inner, stream);
	
	EXIT;
}







