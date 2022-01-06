
#include <debug.h>

#include <enums/error.h>

/*#include <scope/variable.h>*/

#include "../print.h"

#include "struct.h"
#include "print.h"

int ternary_expression_print(
	struct expression* super,
	FILE* stream)
{
	int error = 0;
	struct ternary_expression* const this = (typeof(this)) super;
	ENTER;
	
	error = 0
		?: expression_print(this->conditional, stream)
		?: ((fputs(" ? ", stream) < 0) ? e_syscall_failed : 0)
		?: expression_print(this->true_expression, stream)
		?: ((fputs(" : ", stream) < 0) ? e_syscall_failed : 0)
		?: expression_print(this->false_expression, stream);
	
	EXIT;
	return error;
}

