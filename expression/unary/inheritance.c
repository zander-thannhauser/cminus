
#include "../inheritance.h"

#include "inheritance.h"
#include "write_rasm.h"
#include "print.h"
#include "free.h"

struct expression_inheritance unary_expression_inheritance = {
	.write_rasm = unary_expression_write_rasm,
	.print = unary_expression_print,
	.free = free_unary_expression
};

