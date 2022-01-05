
#include <debug.h>

#include "struct.h"
#include "inheritance.h"
#include "write_asm.h"

int statement_write_asm(struct statement* this, struct asm_writer* writer)
{
	int error = 0;
	ENTER;
	
	dpv(this->kind);
	
	dpv(this->inheritance->write_asm);
	
	assert(this->inheritance->write_asm);
	
	error = (this->inheritance->write_asm)(this, writer);
	
	if (error)
	{
		CHECK;
	}
	
	EXIT;
	return error;
}

