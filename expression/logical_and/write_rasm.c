
#include <stdio.h>
#include <stdbool.h>

#include <enums/error.h>

#include <debug.h>

#include <defines/argv0.h>

/*#include <asm/tables/instrs.h>*/
/*#include <asm/tables/intregs.h>*/
#include <asm/tables/iktors.h>
#include <asm/enums/register_size.h>

#include <type/get_rs.h>
/*#include <type/float/struct.h>*/
/*#include <type/integer/struct.h>*/

/*#include <asm/writer/comment.h>*/

/*#include <asm/location/struct.h>*/

/*#include <asm/writer/write/push.h>*/
/*#include <asm/writer/write/pop.h>*/
#include <asm/writer/write/addi.h>
#include <asm/writer/write/subi.h>
#include <asm/writer/write/jmp.h>
#include <asm/writer/write/label.h>
/*#include <asm/writer/write/mov.h>*/
/*#include <asm/writer/write/addf.h>*/
/*#include <asm/writer/write/movf.h>*/
#include <asm/writer/write/movi.h>
#include <asm/writer/write/on_zjmp.h>

/*#include <type/primitive/struct.h>*/

/*#include <expression/write_rasm.h>*/
/*#include <expression/write_lasm.h>*/

#ifdef VERBOSE_ASSEMBLY
/*#include <asm/writer/indent.h>*/
#include <asm/writer/unindent.h>
#endif

#include "../write_rasm.h"

#include "struct.h"
#include "write_rasm.h"

int logical_and_expression_write_rasm(struct expression* super, struct asm_writer* writer)
{
	int error = 0;
/*	char* prefix_label = NULL;*/
/*	char* false_label = NULL;*/
/*	char* after_label = NULL;*/
	struct logical_and_expression* const this = (typeof(this)) super;
/*	enum register_size rs;*/
	ENTER;
	
	TODO;
	#if 0
	if (false
		|| asprintf(&prefix_label, "%uto%u_%uto%u",
			super->first_line, super->last_line,
			super->first_column, super->last_column) < 0
		|| asprintf(&false_label, "%s_false", prefix_label) < 0
		|| asprintf(&after_label, "%s_after", prefix_label) < 0)
	{
		fprintf(stderr, "%s: asprintf(): %m\n", argv0);
		error = e_syscall_failed;
	}
	
	dpvs(prefix_label);
	dpvs(false_label);
	dpvs(after_label);
	
	error = expression_write_rasm(this->left, writer);
	
		rs = type_get_rs(this->left->type);
		asm_writer_write_movi_to_v2(writer, 0, stackptr, working_1, rs);
		asm_writer_write_addi_const(writer, 8, stackptr, quadword);
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_unindent(writer);
		#endif
	
	asm_writer_write_on_zjmp(writer, working_1, rs, false_label);
	
	error = expression_write_rasm(this->right, writer);
		
		rs = type_get_rs(this->left->type);
		asm_writer_write_movi_to_v2(writer, 0, stackptr, working_1, rs);
		asm_writer_write_addi_const(writer, 8, stackptr, quadword);
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_unindent(writer);
		#endif
	
	asm_writer_write_on_zjmp(writer, working_1, rs, false_label);
	
	asm_writer_write_movi_const_v2(writer, true, working_1, iktors[ik_bool]);
	asm_writer_write_jmp(writer, after_label);
	
	asm_writer_write_label(writer, false_label);
	asm_writer_write_movi_const_v2(writer, false, working_1, iktors[ik_bool]);
	
	asm_writer_write_label(writer, after_label);
	TODO;
	#if 0
	asm_writer_write_movi_from(writer, working_1, -8, stackptr, ik_bool);
	#endif
	asm_writer_write_subi_const(writer, 8, stackptr, quadword);
	
	free(prefix_label);
	free(false_label);
	free(after_label);
	#endif
	
	EXIT;
	return error;
}

































