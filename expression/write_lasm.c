
#include <debug.h>

#include <enums/error.h>

#include <defines/argv0.h>

#ifdef VERBOSE_ASSEMBLY
#include <asm/writer/indent.h>
#endif

#include "print.h"
#include "struct.h"
#include "inheritance.h"
#include "write_rasm.h"

int expression_write_lasm(struct expression* this, struct asm_writer* writer)
{
	int error = 0;
	ENTER;
	
	dpv(this->kind);
	dpv(this->inheritance->write_lasm);
	
	if (this->inheritance->write_lasm)
	{
		error = (this->inheritance->write_lasm)(this, writer);
		
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_indent2(writer, "&(%E)", this);
		#endif
	}
	else
	{
		fprintf(stderr, "%s: `", argv0);
		expression_print(this, stderr);
		fprintf(stderr, "` is not an lvalue!");
		error = e_bad_input_file;
	}
	
	EXIT;
	return error;
}

