
#include <debug.h>

#include <enums/error.h>

#include <defines/argv0.h>

/*#include <asm/tables/instrs.h>*/
#include <asm/tables/iktors.h>

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
#include <asm/writer/write/jmp.h>
#include <asm/writer/write/movf.h>
#include <asm/writer/write/subi.h>
#include <asm/writer/write/addi.h>
#include <asm/writer/write/movi.h>

#include <expression/struct.h>
#include <expression/write_rasm.h>

#include <parser/yylloc/struct.h>

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
		if (!super->loc);
		else if (super->loc->first_line == super->loc->last_line)
			asm_writer_comment(writer, "line %u: return %E;",
			super->loc->first_line, this->return_value);
		else
			asm_writer_comment(writer, "line %u-%u: return %E;",
				super->loc->first_line, super->loc->last_line,
				this->return_value);
		#endif
		
		error = expression_write_rasm(this->return_value, writer);
		
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_comment(writer, "pop return value into return register:");
		#endif
		
		if (this->is_float_result)
		{
			TODO;
			#if 0
			struct float_type* ftype = (typeof(ftype)) this->return_value->type;
			
			asm_writer_write_movf_to(writer, 0, stackptr, fretval, ftype->kind);
			#endif
		}
		else
		{
			struct integer_type* itype = (typeof(itype)) this->return_value->type;
			
			asm_writer_write_movi_to_v2(writer, 0, stackptr, retval, iktors[itype->kind]);
		}
		
		asm_writer_write_addi_const(writer, 8, stackptr, quadword);
		
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_unindent(writer);
		#endif
	}
	else
	{
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_comment(writer, "line %u: return;", super->loc->first_line);
		#endif
	}
	
	char* return_label = NULL;
	
	if (!error)
	{
		asprintf(&return_label, "%s_return", this->funcname);
		
		if (!return_label)
		{
			fprintf(stderr, "%s: asprintf(): %m\n", argv0);
			error = e_out_of_memory;
		}
	}
	
	if (!error)
		asm_writer_write_jmp(writer, return_label);
	
	free(return_label);
	
	EXIT;
	return error;
}















