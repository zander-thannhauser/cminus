
#include <debug.h>

/*#include <asm/tables/instrs.h>*/
/*#include <asm/tables/intregs.h>*/

#include <type/float/struct.h>
#include <type/integer/struct.h>

#include <asm/location/struct.h>

#ifdef VERBOSE_ASSEMBLY
#include <asm/writer/comment.h>
/*#include <asm/writer/indent.h>*/
#include <asm/writer/unindent.h>
#endif

#include <asm/writer/write.h>
#include <asm/writer/write/mov.h>
#include <asm/writer/write/movf.h>
#include <asm/writer/write/subi.h>
#include <asm/writer/write/addi.h>
#include <asm/writer/write/movi.h>

#include <expression/struct.h>
#include <expression/write_rasm.h>

#include "struct.h"
#include "write_asm.h"

int return_statement_write_asm(struct statement* super, struct asm_writer* writer)
{
	int error = 0;
	struct return_statement* const this = (typeof(this)) super;
	ENTER;
	
	if (this->return_value)
	{
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_comment(writer, "line %u: return %E;", super->line, this->return_value);
		#endif
		
		error = expression_write_rasm(this->return_value, writer);
		
		if (!error)
		{
			#ifdef VERBOSE_ASSEMBLY
			asm_writer_comment(writer, "pop return value into return register:");
			#endif
			
			if (this->is_float_result)
			{
				struct float_type* ftype = (typeof(ftype)) this->return_value->type;
				
				asm_writer_write_movf_to(writer, 0, stackptr, fretval, ftype->kind);
				
			}
			else
			{
				struct integer_type* itype = (typeof(itype)) this->return_value->type;
				
				asm_writer_write_movi_to(writer,
					0, stackptr,
					retval,
					itype->kind);
			}
			
			asm_writer_write_addi_const(writer, 8, stackptr, quadword);
			
			#ifdef VERBOSE_ASSEMBLY
			asm_writer_unindent(writer);
			#endif
		}
	}
	else
	{
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_comment(writer, "line %u: return;", super->line);
		#endif
	}
	
	asm_writer_write(writer, "jmp %s_return", this->funcname);
	
	EXIT;
	return error;
}















