
#include "../inheritance.h"

#include "inheritance.h"
#include "write_rasm.h"
#include "print.h"
#include "free.h"

struct expression_inheritance bitshift_expression_inheritance = {
	.write_rasm = bitshift_expression_write_rasm,
	.print = bitshift_expression_print,
	.free = free_bitshift_expression
};

