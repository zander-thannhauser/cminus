
#include <assert.h>

#include <memory/tfree.h>

#include "inheritance.h"
#include "struct.h"
#include "free.h"

void free_statement(struct statement* this)
{
	ENTER;
	
	tfree(this->loc);
	
	assert(this->inheritance->free);
	
	(this->inheritance->free)(this);
	
	EXIT;
}

