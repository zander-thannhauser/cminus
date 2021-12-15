
#include <debug.h>

#include "struct.h"
#include "inheritance.h"
#include "print.h"

void expression_print(struct expression* this, FILE* stream)
{
	ENTER;
	
	dpv(this);
	dpv(this->kind);
	
	dpv(this->inheritance->print);
	
	assert(this->inheritance->print);
	
	(this->inheritance->print)(this, stream);
	
	EXIT;
}

