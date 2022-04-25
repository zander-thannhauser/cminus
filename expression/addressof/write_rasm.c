
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include <expression/write_lasm.h>

#ifdef VERBOSE_ASSEMBLY
#include <asm/writer/unindent.h>
#endif

#include "struct.h"
#include "write_rasm.h"

int addressof_expression_write_rasm(
	struct expression* super, struct asm_writer* writer)
{
	int error = 0;
	ENTER;
	
	struct addressof_expression* const this = (typeof(this)) super;
	
	error = expression_write_lasm(this->inner, writer);
	
	#ifdef VERBOSE_ASSEMBLY
	asm_writer_unindent(writer);
	#endif
	
	EXIT;
	return error;
}

















