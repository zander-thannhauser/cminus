
#include <assert.h>

/*#include <asm/writer/write.h>*/
#include <asm/writer/write/addi.h>
/*#include <asm/writer/write/pop.h>*/

#ifdef VERBOSE_ASSEMBLY
#include <asm/writer/comment.h>
/*#include <asm/writer/indent.h>*/
#include <asm/writer/unindent.h>
#endif

#include <expression/write_rasm.h>

#include <parser/yylloc/struct.h>

#include "struct.h"
#include "write_asm.h"

int expression_statement_write_asm(struct statement* super, struct asm_writer* writer)
{
	int error = 0;
	struct expression_statement* const this = (typeof(this)) super;
	ENTER;
	
	if (this->expression)
	{
		#ifdef VERBOSE_ASSEMBLY
		if (!super->loc);
		else if (super->loc->first_line == super->loc->last_line)
			asm_writer_comment(writer, "line %u, col %u-%u: %E;",
				super->loc->first_line,
				super->loc->first_column,
				super->loc->last_column,
				this->expression);
		else
			asm_writer_comment(writer, "lines %u-%u, col %u-%u: %E;",
				super->loc->first_line,
				super->loc->last_line,
				super->loc->first_column,
				super->loc->last_column,
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


















