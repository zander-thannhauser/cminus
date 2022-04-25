
#include <assert.h>

#include "struct.h"
#include "inheritance.h"
#include "print.h"

int expression_print(struct expression* this, FILE* stream)
{
	int error = 0;
	ENTER;
	
	dpv(this);
	dpv(this->kind);
	
	dpv(this->inheritance->print);
	
	assert(this->inheritance->print);
	
	error = (this->inheritance->print)(this, stream);
	
	EXIT;
	return error;
}

