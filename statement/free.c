
#include <debug.h>

#include "inheritance.h"
#include "struct.h"
#include "free.h"

void free_statement(struct statement* this)
{
	ENTER;
	
	assert(this->inheritance->free);
	
	(this->inheritance->free)(this);
	
	EXIT;
}

