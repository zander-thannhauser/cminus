
#include <assert.h>

#ifdef VERBOSE_ASSEMBLY
#include <asm/writer/unindent.h>
#endif

#include <expression/write_rasm.h>

#include "struct.h"
#include "write_rasm.h"

int parentheses_expression_write_rasm(struct expression* super, struct asm_writer* writer)
{
	int error = 0;
	struct parentheses_expression* const this = (typeof(this)) super;
	ENTER;
	
	error = expression_write_rasm(this->inner, writer);
	
	#ifdef VERBOSE_ASSEMBLY
	asm_writer_unindent(writer);
	#endif
	
	EXIT;
	return error;
}







