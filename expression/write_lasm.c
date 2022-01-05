
#include <debug.h>

#ifdef VERBOSE_ASSEMBLY
#include <asm/writer/indent.h>
#endif

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
	
	#ifdef VERBOSE_ASSEMBLY
	asm_writer_indent2(writer, "&(%E)", this);
	#endif
	
	EXIT;
	return error;
}

