
#include <debug.h>

/*#include <asm/tables/instrs.h>*/
#include <asm/tables/floatregs.h>
#include <asm/tables/intregs.h>
#include <asm/tables/iktors.h>
#include <asm/tables/fktors.h>

#include <type/float/struct.h>
#include <type/integer/struct.h>

/*#include <asm/writer/comment.h>*/

#include <parser/yylloc/struct.h>

/*#include <asm/writer/write/push.h>*/
/*#include <asm/writer/write/pop.h>*/
#include <asm/writer/write/addi.h>
#include <asm/writer/write/subi.h>
/*#include <asm/writer/write/mov.h>*/
/*#include <asm/writer/write/addf.h>*/
/*#include <asm/writer/write/movf.h>*/
#include <asm/writer/write/movf.h>
#include <asm/writer/write/movi.h>
#include <asm/writer/write/jmp.h>
#include <asm/writer/write/label.h>

#include <asm/writer/write.h>
#include <asm/writer/unindent.h>

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

int relational_expression_write_rasm(struct expression* super, struct asm_writer* writer)
{
	int error = 0;
	struct relational_expression* const this = (typeof(this)) super;
	ENTER;
	
	char* label_prefix = NULL;
	char* true_case_label = NULL;
	char* done_label = NULL;
	
	if (false
		|| asprintf(&label_prefix, "%uto%u_%uto%u",
			super->loc->first_line, super->loc->last_line,
			super->loc->first_column, super->loc->last_column) < 0
		|| asprintf(&true_case_label, "%s_true_case", label_prefix) < 0
		|| asprintf(&done_label, "%s_done", label_prefix) < 0)
	{
		TODO;
		error = 1;
	}
	
	error = 0
		?: expression_write_rasm(this->left, writer)
		?: expression_write_rasm(this->right, writer);
	
	enum register_size rs;
	
	if (this->comparing_floats)
	{
		struct float_type *type = (typeof(type)) this->left->type;
		
		dpv(type->kind);
		
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
		
		switch (type->kind)
		{
			case fk_float:
				error = asm_writer_write(writer, "comiss %s, %s",
					floatregs[working_f2], floatregs[working_f1]);
					break;
			
			case fk_double:
				error = asm_writer_write(writer, "comisd %s, %s",
					floatregs[working_f2], floatregs[working_f1]);
					break;
			
			default:
				TODO;
				break;
		}
	}
	else
	{
		struct integer_type *type = (typeof(type)) this->left->type;
		
		rs = iktors[type->kind];
		
		asm_writer_write_movi_to_v2(writer, 0, stackptr, working_2, rs);
		asm_writer_write_addi_const(writer, 8, stackptr, quadword);
		
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_unindent(writer);
		#endif
		
		asm_writer_write_movi_to_v2(writer, 0, stackptr, working_1, rs);
		asm_writer_write_addi_const(writer, 8, stackptr, quadword);
		
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_unindent(writer);
		#endif
		
		error = asm_writer_write(writer, "cmp %s, %s",
			intregs[working_2][rs], intregs[working_1][rs]);
		
	}
	
	switch (this->kind)
	{
		case rek_less_than:
			error = asm_writer_write(writer, "jb .%s", true_case_label);
			break;
		
		case rek_less_than_equal_to:
			error = asm_writer_write(writer, "jbe .%s", true_case_label);
			break;
		
		case rek_greater_than:
			error = asm_writer_write(writer, "ja .%s", true_case_label);
			break;
		
		case rek_greater_than_equal_to:
			error = asm_writer_write(writer, "jae .%s", true_case_label);
			break;
		
		case rek_equal_to:
			error = asm_writer_write(writer, "je .%s", true_case_label);
			break;
		
		case rek_not_equal_to:
			error = asm_writer_write(writer, "jne .%s", true_case_label);
			break;
		
		default:
			TODO;
			break;
	}
	
	rs = iktors[ik_signed_int];
	
	asm_writer_write_movi_const_v2(writer, false, working_1, rs);
	asm_writer_write_jmp(writer, done_label);
	
	asm_writer_write_label(writer, true_case_label);
	asm_writer_write_movi_const_v2(writer, true, working_1, rs);
	
	asm_writer_write_label(writer, done_label);
	asm_writer_write_movi_from_v2(writer, working_1, -8, stackptr, rs);
	asm_writer_write_subi_const(writer, 8, stackptr, quadword);
	
	free(label_prefix);
	free(true_case_label);
	free(done_label);
	
	EXIT;
	return error;
}

























