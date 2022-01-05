
#include "../inheritance.h"

#include "inheritance.h"
#include "write_rasm.h"
#include "print.h"
#include "free.h"

struct expression_inheritance parentheses_expression_inheritance = {
	.write_rasm = parentheses_expression_write_rasm,
	.print = parentheses_expression_print,
	.free = free_parentheses_expression
};

