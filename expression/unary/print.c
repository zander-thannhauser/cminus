
#include <debug.h>
#include <enums/error.h>

#include "../print.h"

#include "struct.h"
#include "print.h"

static const char* lookup[number_of_unary_expressions] = 
{
	[uek_address_of] = "&",
};

int unary_expression_print(
	struct expression* super,
	FILE* stream)
{
	int error = 0;
	struct unary_expression* const this = (typeof(this)) super;
	ENTER;
	
	const char* operator = lookup[this->kind];
	
	dpvs(operator);
	assert(operator);
	
	error = 0
		?: (fprintf(stream, "%s", operator) < 0 ? e_syscall_failed : 0)
		?: expression_print(this->inner, stream);
	
	EXIT;
	return error;
}














