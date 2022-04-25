
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include <enums/error.h>

#include <assert.h>

#include <defines/argv0.h>

/*#include <asm/enums/intregs.h>*/
/*#include <asm/tables/instrs.h>*/
/*#include <asm/tables/intregs.h>*/
/*#include <asm/tables/fktors.h>*/
/*#include <asm/tables/iktors.h>*/

/*#include <asm/location/struct.h>*/

/*#include <asm/writer/comment.h>*/
/*#include <asm/writer/indent.h>*/
#include <asm/writer/write/movi.h>
#include <asm/writer/write/addi.h>
#include <asm/writer/write/subi.h>
/*#include <asm/writer/write/pushg.h>*/
/*#include <asm/writer/write/movf.h>*/
#include <asm/writer/write/on_zjmp.h>
#include <asm/writer/write/jmp.h>
#include <asm/writer/write/label.h>

#include <type/get_rs.h>
/*#include <type/integer/struct.h>*/
/*#include <type/float/struct.h>*/

/*#include <scope/variable.h>*/

/*#include <expression/write_rasm.h>*/

#ifdef VERBOSE_ASSEMBLY
#include <asm/writer/unindent.h>
#endif

#include <parser/yylloc/struct.h>

#include "../write_rasm.h"

#include "struct.h"
#include "write_rasm.h"

int ternary_expression_write_rasm(
	struct expression* super, struct asm_writer* writer)
{
	struct ternary_expression* const this = (typeof(this)) super;
	int error = 0;
	enum register_size rs;
	ENTER;
	
	char* prefix_label = NULL;
	char* false_label = NULL;
	char* after_label = NULL;
	
	if (false
		|| asprintf(&prefix_label, "%uto%u_%uto%u",
			super->loc->first_line, super->loc->last_line,
			super->loc->first_column, super->loc->last_column) < 0
		|| asprintf(&false_label, "%s_false", prefix_label) < 0
		|| asprintf(&after_label, "%s_after", prefix_label) < 0)
	{
		fprintf(stderr, "%s: asprintf(): %m\n", argv0);
		error = e_syscall_failed;
	}
	
	dpvs(prefix_label);
	dpvs(false_label);
	dpvs(after_label);
	
	error = expression_write_rasm(this->conditional, writer);
	
		rs = type_get_rs(this->conditional->type);
		asm_writer_write_movi_to_v2(writer, 0, stackptr, working_1, rs);
		asm_writer_write_addi_const(writer, 8, stackptr, quadword);
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_unindent(writer);
		#endif
	
	asm_writer_write_on_zjmp(writer, working_1, rs, false_label);
	
	error = expression_write_rasm(this->true_expression, writer);
	#ifdef VERBOSE_ASSEMBLY
	asm_writer_unindent(writer);
	#endif
	
	asm_writer_write_jmp(writer, after_label);
	
	asm_writer_write_label(writer, false_label);
	
	error = expression_write_rasm(this->false_expression, writer);
	#ifdef VERBOSE_ASSEMBLY
	asm_writer_unindent(writer);
	#endif
	
	asm_writer_write_label(writer, after_label);

	free(prefix_label);
	free(false_label);
	free(after_label);
	
	EXIT;
	return error;
}

















