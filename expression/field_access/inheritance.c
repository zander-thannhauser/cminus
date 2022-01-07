
#include "../inheritance.h"

#include "inheritance.h"
#include "write_rasm.h"
#include "write_lasm.h"
#include "print.h"
#include "free.h"

struct expression_inheritance field_access_expression_inheritance = {
	.write_rasm = field_access_expression_write_rasm,
	.write_lasm = field_access_expression_write_lasm,
	.print = field_access_expression_print,
	.free = free_field_access_expression,
};

