
#include <debug.h>
#include <enums/error.h>

#include "../print.h"

#include "struct.h"
#include "print.h"

static const char* lookup[number_of_arithmetic_expressions] = 
{
	[aek_add]      = "+",
	[aek_subtract] = "-",
	[aek_multiply] = "*",
	[aek_divide]   = "/",
	[aek_rdivide]  = "%",
};

int arithmetic_expression_print(
	struct expression* super,
	FILE* stream)
{
	int error = 0;
	struct arithmetic_expression* const this = (typeof(this)) super;
	ENTER;
	
	const char* operator = lookup[this->kind];
	
	dpvs(operator);
	assert(operator);
	
	error = 0
		?: expression_print(this->left, stream)
		?: (fprintf(stream, " %s ", operator) < 0 ? e_syscall_failed : 0)
		?: expression_print(this->right, stream);
	
	EXIT;
	return error;
}














