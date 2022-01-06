
#include "../inheritance.h"

#include "inheritance.h"
#include "write_rasm.h"
#include "print.h"
#include "free.h"

struct expression_inheritance comparision_expression_inheritance = {
	.write_rasm = comparision_expression_write_rasm,
	.print = comparision_expression_print,
	.free = free_comparision_expression
};

