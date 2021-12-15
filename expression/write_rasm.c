
#include <debug.h>

#include <asm/writer/comment.h>

#include "struct.h"
#include "inheritance.h"
#include "write_rasm.h"

int expression_write_rasm(struct expression* this, struct asm_writer* writer)
{
	int error = 0;
	ENTER;
	
	dpv(this->kind);
	dpv(this->inheritance->write_rasm);
	
	assert(this->inheritance->write_rasm);
	
	error = (this->inheritance->write_rasm)(this, writer);
	
	asm_writer_comment(writer, "%E\n", this);
	
	EXIT;
	return error;
}

