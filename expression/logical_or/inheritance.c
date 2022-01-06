
#include "../inheritance.h"

#include "inheritance.h"
#include "write_rasm.h"
#include "print.h"
#include "free.h"

struct expression_inheritance logical_or_expression_inheritance = {
	.write_rasm = logical_or_expression_write_rasm,
	.print = logical_or_expression_print,
	.free = free_logical_or_expression
};

