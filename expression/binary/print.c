
#include <debug.h>

#include "../print.h"

#include "struct.h"
#include "print.h"

static const char* lookup[number_of_binary_expressions] = 
{
	[bek_add] = "+",
	[bek_regular_assign] = "=",
};

void binary_expression_print(
	struct expression* super,
	FILE* stream)
{
	struct binary_expression* const this = (typeof(this)) super;
	ENTER;
	
	expression_print(this->left, stream);
	
	const char* operator = lookup[this->kind];
	
	dpvs(operator);
	
	assert(operator);
	
	putc(' ', stream), fputs(operator, stream), putc(' ', stream);
	
	expression_print(this->right, stream);
	
	EXIT;
}

