
#include <debug.h>

#include "inheritance.h"
#include "struct.h"
#include "free.h"

void free_type(struct type* this)
{
	ENTER;
	
	dpv(this);
	dpv(this->inheritance);
	dpv(this->inheritance->free);
	
	if (!this->inheritance->free)
	{
		TODO;
	}
	
	assert(this->inheritance->free);
	
	(this->inheritance->free)(this);
	
	EXIT;
}

