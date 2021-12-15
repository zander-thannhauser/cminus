
#include "../inheritance.h"

#include "inheritance.h"
#include "write_rasm.h"
#include "free.h"

struct expression_inheritance cast_expression_inheritance = {
	.write_rasm = cast_expression_write_rasm,
	.free = free_cast_expression
};

