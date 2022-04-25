
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

/*#include <asm/writer/write.h>*/
#include <asm/writer/write/addi.h>
#include <asm/writer/write/movi.h>
#include <asm/writer/write/on_zjmp.h>
#include <asm/writer/write/jmp.h>
#include <asm/writer/write/label.h>

#include <type/get_rs.h>

#include <expression/struct.h>
#include <expression/write_rasm.h>

#include <parser/yylloc/struct.h>

#ifdef VERBOSE_ASSEMBLY
#include <asm/writer/comment.h>
/*#include <asm/writer/indent.h>*/
#include <asm/writer/unindent.h>
#endif

#include "../write_asm.h"

#include "struct.h"
#include "write_asm.h"

int if_statement_write_asm(struct statement* super, struct asm_writer* writer)
{
	int error = 0;
	struct if_statement* const this = (typeof(this)) super;
	ENTER;
	
	#ifdef VERBOSE_ASSEMBLY
	asm_writer_comment(writer, "lines %u-%u, col %u-%u: if (%E) { ... }",
		super->loc->first_line,
		super->loc->last_line,
		super->loc->first_column,
		super->loc->last_column,
		this->conditional);
	#endif

	enum register_size rs = type_get_rs(this->conditional->type);
	
	char* label_prefix = NULL;
	char* false_case_label = NULL;
	char* done_label = NULL;
	
	if (false
		|| asprintf(&label_prefix, "%uto%u_%uto%u",
			super->loc->first_line, super->loc->last_line,
			super->loc->first_column, super->loc->last_column) < 0
		|| asprintf(&false_case_label, "%s_false_case", label_prefix) < 0
		|| asprintf(&done_label, "%s_done", label_prefix) < 0)
	{
		TODO;
		error = 1;
	}
	
	if (!error)
	{
		error = 0
			?: expression_write_rasm(this->conditional, writer)
			?: asm_writer_write_movi_to_v2(writer, 0, stackptr, working_1, rs)
			?: asm_writer_write_addi_const(writer, 8, stackptr, quadword)
			#ifdef VERBOSE_ASSEMBLY
			?: (asm_writer_unindent(writer), 0)
			#endif
			?: asm_writer_write_on_zjmp(writer, working_1, rs, false_case_label)
			?: statement_write_asm(this->true_case, writer)
			?: asm_writer_write_jmp(writer, done_label)
			?: asm_writer_write_label(writer, false_case_label)
			?: (this->false_case
				? statement_write_asm(this->false_case, writer)
				: 0)
			?: asm_writer_write_label(writer, done_label);
	}
	
	free(label_prefix);
	free(false_case_label);
	free(done_label);
	
	EXIT;
	return error;
}


















