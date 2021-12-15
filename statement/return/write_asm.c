
#include <debug.h>

/*#include <asm/tables/instrs.h>*/
/*#include <asm/tables/intregs.h>*/

#include <asm/location/struct.h>

#include <asm/writer/comment.h>
#include <asm/writer/indent.h>
#include <asm/writer/unindent.h>
#include <asm/writer/write.h>

#include <asm/writer/write/mov.h>
#include <asm/writer/write/pop.h>

#include <expression/write_rasm.h>

#include "struct.h"
#include "write_asm.h"

int return_statement_write_asm(struct statement* super, struct asm_writer* writer)
{
	int error = 0;
	struct return_statement* const this = (typeof(this)) super;
	ENTER;
	
	if (this->return_value)
		asm_writer_comment(writer, "line %u: return %E;", super->line, this->return_value);
	else
		asm_writer_comment(writer, "line %u: return;", super->line);
	
	if (this->return_value)
	{
		asm_writer_indent(writer);
		
		error = expression_write_rasm(this->return_value, writer);
		
		asm_writer_unindent(writer);
		
		if (!error)
		{
			asm_writer_comment(writer, "pop return value into return register:");
			if (this->is_integer_result)
				asm_writer_write_pop(writer, retval);
			else
			{
				asm_writer_write_pop(writer, working_1);
				
				asm_writer_write_mov(writer,
					ASMREG(working_1), ik_unsigned_long,
					ASMFREG(fretval), ik_unsigned_long);
			}
		}
	}
	
	asm_writer_write(writer, "jmp %s_return", this->funcname);
	
	EXIT;
	return error;
}















