
#include "../inheritance.h"

#include "inheritance.h"
#include "write_rasm.h"
#include "write_lasm.h"
#include "print.h"
#include "free.h"

struct expression_inheritance variable_expression_inheritance = {
	.write_rasm = variable_expression_write_rasm,
	.write_lasm = variable_expression_write_lasm,
	.print = variable_expression_print,
	.free = free_variable_expression,
};

