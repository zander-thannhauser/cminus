
#include <debug.h>

#include "struct.h"
#include "inheritance.h"
#include "print.h"

int type_print(struct type* this, char* name, FILE* stream)
{
	int error = 0;
	ENTER;
	
	dpv(this);
	dpv(this->kind);
	
	dpv(this->inheritance->print);
	
	assert(this->inheritance->print);
	
	error = (this->inheritance->print)(this, name, stream);
	
	EXIT;
	return error;
}

