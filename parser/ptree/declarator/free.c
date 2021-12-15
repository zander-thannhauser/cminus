
#include <debug.h>

#include "inheritance.h"
#include "struct.h"
#include "free.h"

void free_declarator(struct declarator* this)
{
	ENTER;
	
	dpv(this->inheritance->free);
	
	if (this->inheritance->free)
		(this->inheritance->free)(this);
	
	EXIT;
}

