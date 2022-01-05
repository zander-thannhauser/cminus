
#include "../inheritance.h"

#include "inheritance.h"
#include "write_rasm.h"
#include "print.h"
#include "free.h"

struct expression_inheritance assign_expression_inheritance = {
	.write_rasm = assign_expression_write_rasm,
	.print = assign_expression_print,
	.free = free_assign_expression
};

