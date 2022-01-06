
#include "../inheritance.h"

#include "inheritance.h"
#include "write_rasm.h"
#include "write_lasm.h"
#include "print.h"
#include "free.h"

struct expression_inheritance ternary_expression_inheritance = {
	.write_rasm = ternary_expression_write_rasm,
	.write_lasm = ternary_expression_write_lasm,
	.print = ternary_expression_print,
	.free = free_ternary_expression,
};

