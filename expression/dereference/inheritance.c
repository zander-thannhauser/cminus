
#include "../inheritance.h"

#include "inheritance.h"
#include "write_rasm.h"
#include "write_lasm.h"
#include "print.h"
#include "free.h"

struct expression_inheritance dereference_expression_inheritance = {
	.write_rasm = dereference_expression_write_rasm,
	.write_lasm = dereference_expression_write_lasm,
	.print = dereference_expression_print,
	.free = free_dereference_expression,
};

