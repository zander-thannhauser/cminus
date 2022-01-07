
#include "../inheritance.h"

#include "inheritance.h"
#include "write_rasm.h"
#include "write_lasm.h"
#include "print.h"
#include "free.h"

struct expression_inheritance array_index_expression_inheritance = {
	.write_rasm = array_index_expression_write_rasm,
	.write_lasm = array_index_expression_write_lasm,
	.print = array_index_expression_print,
	.free = free_array_index_expression,
};

