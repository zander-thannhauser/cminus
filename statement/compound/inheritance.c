
#include "../inheritance.h"

#include "inheritance.h"
#include "write_asm.h"
#include "free.h"

struct statement_inheritance compound_statement_inheritance = {
	.write_asm = inheritance_compound_statement_write_asm,
	.free = free_compound_statement
};


