
#include <debug.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_compound_statement(struct statement* super)
{
	struct compound_statement* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->statements);
	
	EXIT;
}

