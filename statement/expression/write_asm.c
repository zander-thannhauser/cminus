
#include <debug.h>

/*#include <asm/writer/write.h>*/
#include <asm/writer/write/pop.h>
#include <asm/writer/comment.h>
#include <asm/writer/indent.h>
#include <asm/writer/unindent.h>

#include <expression/write_rasm.h>

#include "struct.h"
#include "write_asm.h"

int expression_statement_write_asm(struct statement* super, struct asm_writer* writer)
{
	int error = 0;
	struct expression_statement* const this = (typeof(this)) super;
	ENTER;
	
	dpv(super->line);
	
	asm_writer_comment(writer, "line %lu: %E;\n", super->line, this->expression);
	
	asm_writer_indent(writer);
	
	error = expression_write_rasm(this->expression, writer);
	
	asm_writer_unindent(writer);
	
	asm_writer_write_pop(writer, working_1);
	
	EXIT;
	return error;
}

