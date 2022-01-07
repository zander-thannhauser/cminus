
#include "../inheritance.h"

#include "inheritance.h"
#include "write_rasm.h"
#include "print.h"
#include "free.h"

struct expression_inheritance relational_expression_inheritance = {
	.write_rasm = relational_expression_write_rasm,
	.print = relational_expression_print,
	.free = free_relational_expression
};

