
#include "../inheritance.h"

#include "inheritance.h"
#include "write_lasm.h"
#include "print.h"
#include "free.h"

struct expression_inheritance initializer_expression_inheritance = {
	.write_rasm = initializer_expression_write_lasm,
	.write_lasm = initializer_expression_write_lasm,
	.print = initializer_expression_print,
	.free = free_initializer_expression,
};

