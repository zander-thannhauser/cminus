
#include <debug.h>

#include <memory/tfree.h>

#include "inheritance.h"
#include "struct.h"
#include "free.h"

void free_expression(struct expression* this)
{
	ENTER;
	
	dpv(this->inheritance);
	dpv(this->inheritance->free);
	assert(this->inheritance->free);
	
	tfree(this->type);
	
	(this->inheritance->free)(this);
	
	EXIT;
}

