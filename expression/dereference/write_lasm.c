
#include <stdlib.h>

#include <assert.h>

#include "../write_rasm.h"

#ifdef VERBOSE_ASSEMBLY
#include <asm/writer/comment.h>
#include <asm/writer/unindent.h>
#endif

#include "struct.h"
#include "write_lasm.h"

int dereference_expression_write_lasm(
	struct expression* super, struct asm_writer* writer)
{
	int error = 0;
	ENTER;
	
	struct dereference_expression* const this = (typeof(this)) super;
	
	error = expression_write_rasm(this->inner, writer);
	
	#ifdef VERBOSE_ASSEMBLY
	asm_writer_comment(writer, "// are you confused yet?");
	asm_writer_unindent(writer);
	#endif
	
	EXIT;
	return error;
}

















