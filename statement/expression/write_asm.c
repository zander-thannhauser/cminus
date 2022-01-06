
#include <debug.h>

/*#include <asm/writer/write.h>*/
#include <asm/writer/write/addi.h>
/*#include <asm/writer/write/pop.h>*/

#ifdef VERBOSE_ASSEMBLY
#include <asm/writer/comment.h>
/*#include <asm/writer/indent.h>*/
#include <asm/writer/unindent.h>
#endif

#include <expression/write_rasm.h>

#include "struct.h"
#include "write_asm.h"

int expression_statement_write_asm(struct statement* super, struct asm_writer* writer)
{
	int error = 0;
	struct expression_statement* const this = (typeof(this)) super;
	ENTER;
	
	if (this->expression)
	{
		dpv(super->first_line);
		dpv(super->last_line);
		dpv(super->first_column);
		dpv(super->last_column);
		
		#ifdef VERBOSE_ASSEMBLY
		if (super->first_line == super->last_line)
			asm_writer_comment(writer, "line %u, col %u-%u: %E;",
				super->first_line,
				super->first_column, super->last_column,
				this->expression);
		else
			asm_writer_comment(writer, "lines %u-%u, col %u-%u: %E;",
				super->first_line,
				super->first_column, super->last_column,
				this->expression);
		#endif
		
		error = expression_write_rasm(this->expression, writer);
		
		asm_writer_write_addi_const(writer, 8, stackptr, quadword);
		
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_unindent(writer);
		#endif
	}
	
	EXIT;
	return error;
}


















