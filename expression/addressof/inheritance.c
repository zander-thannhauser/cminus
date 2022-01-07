
#include "../inheritance.h"

#include "inheritance.h"
#include "write_rasm.h"
#include "print.h"
#include "free.h"

struct expression_inheritance addressof_expression_inheritance = {
	.write_rasm = addressof_expression_write_rasm,
	.print = addressof_expression_print,
	.free = free_addressof_expression,
};

