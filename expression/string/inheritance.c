
#include "../inheritance.h"

#include "inheritance.h"
#include "write_rasm.h"
#include "print.h"
#include "free.h"

struct expression_inheritance string_expression_inheritance = {
	.write_rasm = string_expression_write_rasm,
	.print = string_expression_print,
	.free = free_string_expression
};

