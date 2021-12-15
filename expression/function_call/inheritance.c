
#include "../inheritance.h"

#include "inheritance.h"
#include "write_rasm.h"
#include "print.h"
#include "free.h"

struct expression_inheritance function_call_expression_inheritance = {
	.write_rasm = function_call_expression_write_rasm,
	.print = function_call_expression_print,
	.free = free_function_call_expression,
};

