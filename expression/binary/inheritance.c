
#include "../inheritance.h"

#include "inheritance.h"
#include "write_rasm.h"
#include "print.h"
#include "free.h"

struct expression_inheritance binary_expression_inheritance = {
	.write_rasm = binary_expression_write_rasm,
	.print = binary_expression_print,
	.free = free_binary_expression
};

