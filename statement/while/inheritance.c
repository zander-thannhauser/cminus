
#include "../inheritance.h"

#include "free.h"
#include "write_asm.h"
#include "inheritance.h"

struct statement_inheritance while_statement_inheritance = {
	.write_asm = while_statement_write_asm,
	.free = free_while_statement
};


