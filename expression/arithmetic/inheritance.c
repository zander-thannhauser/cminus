
#include "../inheritance.h"

#include "inheritance.h"
#include "write_rasm.h"
#include "print.h"
#include "free.h"

struct expression_inheritance arithmetic_expression_inheritance = {
	.write_rasm = arithmetic_expression_write_rasm,
	.print = arithmetic_expression_print,
	.free = free_arithmetic_expression
};

