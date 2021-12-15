
#include "../inheritance.h"

#include "free.h"
#include "write_asm.h"
#include "inheritance.h"

struct statement_inheritance expression_statement_inheritance = {
	.write_asm = expression_statement_write_asm,
	.free = free_expression_statement
};


