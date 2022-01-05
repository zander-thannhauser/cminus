
#include <debug.h>

/*#include <asm/tables/instrs.h>*/
/*#include <asm/tables/intregs.h>*/
/*#include <asm/tables/pktors.h>*/

#include <type/float/struct.h>
#include <type/integer/struct.h>

#ifdef VERBOSE_ASSEMBLY
/*#include <asm/writer/indent.h>*/
#include <asm/writer/unindent.h>
/*#include <asm/writer/comment.h>*/
#endif

/*#include <asm/location/struct.h>*/

/*#include <asm/writer/write/push.h>*/
/*#include <asm/writer/write/pop.h>*/
#include <asm/writer/write/addi.h>
#include <asm/writer/write/subi.h>
/*#include <asm/writer/write/subi.h>*/
#include <asm/writer/write/movi.h>
/*#include <asm/writer/write/addf.h>*/
#include <asm/writer/write/movf.h>

/*#include <type/primitive/struct.h>*/

/*#include <expression/write_rasm.h>*/
/*#include <expression/write_lasm.h>*/

#include "../write_lasm.h"
#include "../write_rasm.h"

#include "struct.h"
#include "write_rasm.h"

int assign_expression_write_rasm(struct expression* super, struct asm_writer* writer)
{
	int error = 0;
	struct assign_expression* const this = (typeof(this)) super;
	ENTER;
	
	error = 0
		?: expression_write_lasm(this->left, writer)
		?: expression_write_rasm(this->right, writer);
	
	switch (super->type->kind)
	{
		case tk_float:
		{
			struct float_type* ftype = (typeof(ftype)) super->type;
			
			asm_writer_write_movf_to(writer, 0, stackptr, working_f2, ftype->kind);
			asm_writer_write_addi_const(writer, 8, stackptr, quadword);
			#ifdef VERBOSE_ASSEMBLY
			asm_writer_unindent(writer);
			#endif
			
			asm_writer_write_movi_to(writer, 0, stackptr, working_1, ik_unsigned_long);
			asm_writer_write_addi_const(writer, 8, stackptr, quadword);
			
			#ifdef VERBOSE_ASSEMBLY
			asm_writer_unindent(writer);
			#endif
			
			switch (this->kind)
			{
				case aek_regular_assign:
					break;
				
				default:
					TODO;
					break;
			}
			
			asm_writer_write_movf_from(writer, working_f2, 0, working_1, ftype->kind);
			asm_writer_write_movf_from(writer, working_f2, -8, stackptr, ftype->kind);
			asm_writer_write_subi_const(writer, 8, stackptr, quadword);
			
			break;
		}
		
		case tk_integer:
		{
			struct integer_type* itype = (typeof(itype)) super->type;
			
			asm_writer_write_movi_to(writer, 0, stackptr, working_2, itype->kind);
			asm_writer_write_addi_const(writer, 8, stackptr, quadword);
			#ifdef VERBOSE_ASSEMBLY
			asm_writer_unindent(writer);
			#endif
			
			asm_writer_write_movi_to(writer, 0, stackptr, working_1, ik_unsigned_long);
			asm_writer_write_addi_const(writer, 8, stackptr, quadword);
			
			#ifdef VERBOSE_ASSEMBLY
			asm_writer_unindent(writer);
			#endif
			
			switch (this->kind)
			{
				case aek_regular_assign:
					break;
				
				default:
					TODO;
					break;
			}
			
			asm_writer_write_movi_from(writer, working_2, 0, working_1, itype->kind);
			asm_writer_write_movi_from(writer, working_2, -8, stackptr, itype->kind);
			asm_writer_write_subi_const(writer, 8, stackptr, quadword);
			break;
		}
		
		default:
			TODO;
			break;
	}
	
	EXIT;
	return error;
}

























