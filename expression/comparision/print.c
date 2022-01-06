
#include <debug.h>
#include <enums/error.h>

#include "../print.h"

#include "struct.h"
#include "print.h"

#if 0
static const char* lookup[number_of_comparision_expressions] = 
{
	[bek_add] = "+",
};
#endif

int comparision_expression_print(
	struct expression* super,
	FILE* stream)
{
	int error = 0;
	struct comparision_expression* const this = (typeof(this)) super;
	ENTER;
	
	TODO;
	#if 0
	const char* operator = lookup[this->kind];
	
	dpvs(operator);
	assert(operator);
	
	error = 0
		?: expression_print(this->left, stream)
		?: (fprintf(stream, " %s ", operator) < 0 ? e_syscall_failed : 0)
		?: expression_print(this->right, stream);
	#endif
	
	EXIT;
	return error;
}














