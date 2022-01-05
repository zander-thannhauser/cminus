
#include "../inheritance.h"

#include "inheritance.h"
#include "write_rasm.h"
#include "print.h"
#include "free.h"

struct expression_inheritance comma_expression_inheritance = {
	.write_rasm = comma_expression_write_rasm,
	.print = comma_expression_print,
	.free = free_comma_expression
};

