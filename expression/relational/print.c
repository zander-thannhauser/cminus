
#include <debug.h>
#include <enums/error.h>

#include "../print.h"

#include "struct.h"
#include "print.h"

static const char* lookup[number_of_relational_expressions] = 
{
	[rek_less_than] = "<",
	[rek_greater_than] = ">",
	[rek_less_than_equal_to] = "<=",
	[rek_greater_than_equal_to] = ">=",
	[rek_equal_to] = "==",
	[rek_not_equal_to] = "!=",
};

int relational_expression_print(
	struct expression* super,
	FILE* stream)
{
	int error = 0;
	struct relational_expression* const this = (typeof(this)) super;
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














