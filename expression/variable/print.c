
#include <debug.h>

#include <scope/variable.h>

#include "../print.h"

#include "struct.h"
#include "print.h"

void variable_expression_print(
	struct expression* super,
	FILE* stream)
{
	struct variable_expression* const this = (typeof(this)) super;
	ENTER;
	
	fputs(this->variable->name, stream);
	
	EXIT;
}

