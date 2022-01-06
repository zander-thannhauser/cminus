
#include <debug.h>

/*#include <asm/tables/instrs.h>*/
/*#include <asm/tables/intregs.h>*/
/*#include <asm/tables/iktors.h>*/

/*#include <type/float/struct.h>*/
/*#include <type/integer/struct.h>*/

/*#include <asm/writer/comment.h>*/

/*#include <asm/location/struct.h>*/

/*#include <asm/writer/write/push.h>*/
/*#include <asm/writer/write/pop.h>*/
/*#include <asm/writer/write/addi.h>*/
/*#include <asm/writer/write/subi.h>*/
/*#include <asm/writer/write/mov.h>*/
/*#include <asm/writer/write/addf.h>*/
/*#include <asm/writer/write/movf.h>*/
/*#include <asm/writer/write/movi.h>*/

/*#include <type/primitive/struct.h>*/

/*#include <expression/write_rasm.h>*/
/*#include <expression/write_lasm.h>*/

#ifdef VERBOSE_ASSEMBLY
/*#include <asm/writer/indent.h>*/
/*#include <asm/writer/unindent.h>*/
#endif

#include "../write_rasm.h"

#include "struct.h"
#include "write_rasm.h"

int comparision_expression_write_rasm(struct expression* super, struct asm_writer* writer)
{
	int error = 0;
	struct comparision_expression* const this = (typeof(this)) super;
	ENTER;
	
	TODO;
	#if 0
	if (this->kind == bek_logical_and)
	{
		TODO;
	}
	else if (this->kind == bek_logical_or)
	{
		TODO;
	}
	else if (this->is_float_result)
	{
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
	}
	else
	{
		struct integer_type *type = (typeof(type)) super->type;
		
		error = 0
			?: expression_write_rasm(this->left, writer)
			?: expression_write_rasm(this->right, writer);
		
		asm_writer_write_movi_to(writer, 0, stackptr, working_2, type->kind);
		asm_writer_write_addi_const(writer, 8, stackptr, quadword);
		
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_unindent(writer);
		#endif
		
		asm_writer_write_movi_to(writer, 0, stackptr, working_1, type->kind);
		asm_writer_write_addi_const(writer, 8, stackptr, quadword);
		
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_unindent(writer);
		#endif
		
		switch (this->kind)
		{
			case bek_add:
				asm_writer_write_addi(writer, working_1, working_2, iktors[type->kind]);
				break;
			
			default:
				TODO;
				break;
		}
		
		asm_writer_write_movi_from(writer, working_2, -8, stackptr, type->kind);
	}
	
	asm_writer_write_subi_const(writer, 8, stackptr, quadword);
	#endif
	
	EXIT;
	return error;
}

























