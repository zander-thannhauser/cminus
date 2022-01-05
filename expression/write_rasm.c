
#include <debug.h>

/*#include <asm/writer/write/subi.h>*/
#ifdef VERBOSE_ASSEMBLY
#include <asm/writer/indent.h>
#endif

#include <type/struct.h>

#include "struct.h"
#include "write_lasm.h"
#include "inheritance.h"
#include "write_rasm.h"

int expression_write_rasm(struct expression* this, struct asm_writer* writer)
{
	int error = 0;
	ENTER;
	
	switch (this->type->kind)
	{
		case tk_array:
		case tk_function:
		case tk_struct:
			error = expression_write_lasm(this, writer);
			break;
		
		default:
			dpv(this->kind);
			dpv(this->inheritance->write_rasm);
			assert(this->inheritance->write_rasm);
			error = (this->inheritance->write_rasm)(this, writer);
			#ifdef VERBOSE_ASSEMBLY
			asm_writer_indent2(writer, "%E", this);
			#endif
			break;
	}
	
	if (error)
	{
		CHECK;
	}
	
	EXIT;
	return error;
}

