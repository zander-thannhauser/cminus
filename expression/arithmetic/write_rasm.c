
#include <debug.h>

/*#include <asm/tables/instrs.h>*/
/*#include <asm/tables/intregs.h>*/
#include <asm/tables/iktors.h>

#include <type/float/struct.h>
#include <type/integer/struct.h>

/*#include <asm/writer/comment.h>*/

/*#include <asm/location/struct.h>*/

/*#include <asm/writer/write/push.h>*/
/*#include <asm/writer/write/pop.h>*/
#include <asm/writer/write/addi.h>
#include <asm/writer/write/subi.h>
#include <asm/writer/write/multi.h>
#include <asm/writer/write/divi.h>
#include <asm/writer/write/rdivi.h>
/*#include <asm/writer/write/mov.h>*/
#include <asm/writer/write/addf.h>
#include <asm/writer/write/movf.h>
#include <asm/writer/write/movi.h>

/*#include <type/primitive/struct.h>*/

/*#include <expression/write_rasm.h>*/
/*#include <expression/write_lasm.h>*/

#ifdef VERBOSE_ASSEMBLY
#include <asm/writer/indent.h>
#include <asm/writer/unindent.h>
#endif

#include "../write_rasm.h"

#include "struct.h"
#include "write_rasm.h"

int arithmetic_expression_write_rasm(struct expression* super, struct asm_writer* writer)
{
	int error = 0;
	struct arithmetic_expression* const this = (typeof(this)) super;
	ENTER;
	
	if (this->is_float_result)
	{
		TODO;
		#if 0
		struct float_type *type = (typeof(type)) super->type;
		
		error = 0
			?: expression_write_rasm(this->left, writer)
			?: expression_write_rasm(this->right, writer);
		
		asm_writer_write_movf_to(writer, 0, stackptr, working_f2, type->kind);
		asm_writer_write_addi_const(writer, 8, stackptr, quadword);
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_unindent(writer);
		#endif
		
		asm_writer_write_movf_to(writer, 0, stackptr, working_f1, type->kind);
		asm_writer_write_addi_const(writer, 8, stackptr, quadword);
		
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_unindent(writer);
		#endif
		
		switch (this->kind)
		{
			case bek_add:
				asm_writer_write_addf(writer, working_f1, working_f2, type->kind);
				break;
			
			default:
				TODO;
				break;
		}
		
		asm_writer_write_movf_from(writer, working_f2, -8, stackptr, type->kind);
		#endif
	}
	else
	{
		struct integer_type *type = (typeof(type)) super->type;
		
		error = 0
			?: expression_write_rasm(this->left, writer)
			?: expression_write_rasm(this->right, writer);
		
		asm_writer_write_movi_to_v2(writer, 0, stackptr, working_2, iktors[type->kind]);
		asm_writer_write_addi_const(writer, 8, stackptr, quadword);
		
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_unindent(writer);
		#endif
		
		asm_writer_write_movi_to_v2(writer, 0, stackptr, working_1, iktors[type->kind]);
		asm_writer_write_addi_const(writer, 8, stackptr, quadword);
		
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_unindent(writer);
		#endif
		
		enum integer_register_id result_location;
		switch (this->kind)
		{
			case aek_add:
				asm_writer_write_addi(writer, working_1, working_2, iktors[type->kind]);
				result_location = working_2;
				break;
			
			case aek_subtract:
				asm_writer_write_subi(writer, working_2, working_1, iktors[type->kind]);
				result_location = working_1;
				break;
			
			case aek_multiply:
				asm_writer_write_multi_v2(writer, working_1, working_2, type->kind);
				result_location = working_2;
				break;
			
			case aek_divide:
				asm_writer_write_divi(writer, working_1, working_2, type->kind);
				result_location = divq_reg;
				break;
			
			case aek_rdivide:
				asm_writer_write_rdivi(writer, working_1, working_2, type->kind);
				result_location = divr_reg;
				break;
			
			default:
				TODO;
				break;
		}
		
		asm_writer_write_movi_from_v2(writer, result_location, -8, stackptr, iktors[type->kind]);
	}
	
	asm_writer_write_subi_const(writer, 8, stackptr, quadword);
	
	EXIT;
	return error;
}

























