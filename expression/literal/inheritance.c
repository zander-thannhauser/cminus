
#include "../inheritance.h"

#include "inheritance.h"
#include "write_rasm.h"
#include "print.h"
#include "free.h"

struct expression_inheritance literal_expression_inheritance = {
	.write_rasm = literal_expression_write_rasm,
	.print = literal_expression_print,
	.free = free_literal_expression
};

