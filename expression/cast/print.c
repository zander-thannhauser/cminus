
#include <string.h>
#include <stdlib.h>

#include <assert.h>
#include <enums/error.h>

/*#include <char/printable.h>*/

#include <type/print.h>

/*#include <type/integer/struct.h>*/
/*#include <type/float/struct.h>*/

#include "../print.h"

#include "struct.h"
#include "print.h"

int cast_expression_print(
	struct expression* super,
	FILE* stream)
{
	int error = 0;
	struct cast_expression* const this = (typeof(this)) super;
	ENTER;
	
	error = 0
		?: (fprintf(stream, "(") < 0 ? e_syscall_failed : 0)
		?: type_print(this->type, NULL, stream)
		?: (fprintf(stream, ") ") < 0 ? e_syscall_failed : 0)
		?: expression_print(this->inner, stream);
	
	EXIT;
	return error;
}






















