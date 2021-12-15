
#include "../inheritance.h"

#include "free.h"
#include "write_asm.h"
#include "inheritance.h"

struct statement_inheritance return_statement_inheritance = {
	.write_asm = return_statement_write_asm,
	.free = free_return_statement
};


