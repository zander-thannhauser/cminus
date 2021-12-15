
#include <debug.h>

#include <asm/writer/comment.h>

#include "struct.h"
#include "inheritance.h"
#include "write_rasm.h"

int expression_write_lasm(struct expression* this, struct asm_writer* writer)
{
	int error = 0;
	ENTER;
	
	dpv(this->kind);
	dpv(this->inheritance->write_lasm);
	
	assert(this->inheritance->write_lasm);
	
	error = (this->inheritance->write_lasm)(this, writer);
	
	asm_writer_comment(writer, "&(%E)", this);
	
	EXIT;
	return error;
}

