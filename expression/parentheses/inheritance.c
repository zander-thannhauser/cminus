
#include "../inheritance.h"

#include "inheritance.h"
#include "write_rasm.h"

#include "free.h"

struct expression_inheritance parentheses_expression_inheritance = {
	.write_rasm = parentheses_expression_write_rasm,
	.free = free_parentheses_expression
};

