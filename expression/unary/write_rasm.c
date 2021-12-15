
#include <debug.h>

/*#include <asm/tables/pktors.h>*/
/*#include <asm/tables/instrs.h>*/
/*#include <asm/tables/intregs.h>*/

#include <asm/writer/indent.h>
#include <asm/writer/unindent.h>
#include <asm/writer/comment.h>
#include <asm/writer/write.h>

/*#include <type/primitive/struct.h>*/

#include <expression/write_rasm.h>

#include "struct.h"
#include "write_rasm.h"

int unary_expression_write_rasm(struct expression* super, struct asm_writer* writer)
{
	int error = 0;
	struct unary_expression* const this = (typeof(this)) super;
	ENTER;
	
	TODO;
	#if 0
	asm_writer_indent(writer);
	
	error = expression_write_rasm(this->inner, writer);
	
	asm_writer_unindent(writer);
	
	switch (this->kind)
	{
		case uek_address_of:
			TODO;
			break;
			
		case uek_dereference:
		{
			asm_writer_comment(writer, "dereference:");
			
			enum register_size rs;
			assert(this->inner->type->kind == tk_pointer);
			
			dpv(super->type->kind);
			
			if (super->type->kind == tk_array)
			{
				TODO;
			}
			else if (super->type->kind == tk_pointer)
			{
				rs = quad;
				goto primitive_dereference;
			}
			else if (super->type->kind == tk_primitive)
			{
				rs = pktors[((struct primitive_type*) super->type)->kind];
				
				primitive_dereference:
				asm_writer_write(writer,
					"%s %s",
					instrs1rs[pop][quad],
					intregs[0][quad]);
				
				asm_writer_write(writer,
					"%s (%s), %s",
					instrs1rs[mov][rs],
					intregs[0][quad],
					intregs[1][rs]);
					
				asm_writer_write(writer,
					"%s %s",
					instrs1rs[push][quad],
					intregs[1][quad]);
			}
			else
			{
				// dereference struct/union
				TODO;
			}
			break;
		}
		case uek_numeric_plus:
			TODO;
			break;
			
		case uek_numeric_negate:
			TODO;
			break;
			
		case uek_bitwise_negate:
			TODO;
			break;
			
		case uek_logical_negate:
			TODO;
			break;
	}
	#endif
	
	EXIT;
	return error;
}







