
#include <debug.h>

/*#include <asm/tables/instrs.h>*/
/*#include <asm/tables/intregs.h>*/
#include <asm/tables/iktors.h>

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
#include <asm/writer/write/addf.h>
#include <asm/writer/write/memcpy.h>
#include <asm/writer/write.h>

#include <type/get_rs.h>

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
	
	if (this->kind == aek_regular_assign)
	{
		enum register_size rs = type_get_rs(super->type);
		
		asm_writer_write_movi_to_v2(writer, 0, stackptr, working_2, rs);
		asm_writer_write_addi_const(writer, 8, stackptr, quadword);
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_unindent(writer);
		#endif
		
		asm_writer_write_movi_to_v2(writer, 0, stackptr, working_1, quadword);
		asm_writer_write_addi_const(writer, 8, stackptr, quadword);
		
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_unindent(writer);
		#endif
		
		switch (super->type->kind)
		{
			case tk_float:
			case tk_integer:
			case tk_pointer:
			{
				asm_writer_write_movi_from_v2(writer, working_2,  0, working_1, rs);
				asm_writer_write_movi_from_v2(writer, working_2, -8, stackptr, rs);
				break;
			}
			
			case tk_struct:
			{
				// memcpy call
				
				asm_writer_write_memcpy(writer,
					working_2,
					working_1,
					super->type->size);
				
				asm_writer_write_movi_from_v2(writer, working_1, -8, stackptr, rs);
				break;
			}
			
			default:
				TODO;
				break;
		}
		
		asm_writer_write_subi_const(writer, 8, stackptr, quadword);
	}
	else switch (super->type->kind)
	{
		case tk_float:
		{
			struct float_type* ftype = (typeof(ftype)) super->type;
			
			asm_writer_write_movf_to(writer, 0, stackptr, working_f2, ftype->kind);
			asm_writer_write_addi_const(writer, 8, stackptr, quadword);
			#ifdef VERBOSE_ASSEMBLY
			asm_writer_unindent(writer);
			#endif
			
			asm_writer_write_movi_to_v2(writer, 0, stackptr, working_1, quadword);
			asm_writer_write_addi_const(writer, 8, stackptr, quadword);
			
			#ifdef VERBOSE_ASSEMBLY
			asm_writer_unindent(writer);
			#endif
			
			asm_writer_write_movf_to(writer, 0, working_1, working_f1, ftype->kind);
			
			switch (this->kind)
			{
				case aek_add_assign:
					asm_writer_write_addf(writer, working_f1, working_f2, ftype->kind);
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
			
			asm_writer_write_movi_to_v2(writer, 0, stackptr, working_2, iktors[itype->kind]);
			asm_writer_write_addi_const(writer, 8, stackptr, quadword);
			#ifdef VERBOSE_ASSEMBLY
			asm_writer_unindent(writer);
			#endif
			
			asm_writer_write_movi_to_v2(writer, 0, stackptr, working_1, quadword);
			asm_writer_write_addi_const(writer, 8, stackptr, quadword);
			
			#ifdef VERBOSE_ASSEMBLY
			asm_writer_unindent(writer);
			#endif
			
			switch (this->kind)
			{
				default:
					TODO;
					break;
			}
			
			asm_writer_write_movi_from_v2(writer, working_2, 0, working_1, iktors[itype->kind]);
			asm_writer_write_movi_from_v2(writer, working_2, -8, stackptr, iktors[itype->kind]);
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

























