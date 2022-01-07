
#include "../inheritance.h"

#include "free.h"
#include "write_asm.h"
#include "inheritance.h"

struct statement_inheritance if_statement_inheritance = {
	.write_asm = if_statement_write_asm,
	.free = free_if_statement
};


