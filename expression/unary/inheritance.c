
#include "../inheritance.h"

#include "inheritance.h"
#include "write_rasm.h"

#include "free.h"

struct expression_inheritance unary_expression_inheritance = {
	.write_rasm = unary_expression_write_rasm,
	.free = free_unary_expression
};

