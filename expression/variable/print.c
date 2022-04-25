
#include <assert.h>
#include <enums/error.h>

#include <scope/variable.h>

#include "../print.h"

#include "struct.h"
#include "print.h"

int variable_expression_print(
	struct expression* super,
	FILE* stream)
{
	int error = 0;
	struct variable_expression* const this = (typeof(this)) super;
	ENTER;
	
	dpvs(this->variable->name);
	
	if (fputs(this->variable->name, stream) < 0)
		error = e_syscall_failed;
	
	EXIT;
	return error;
}

