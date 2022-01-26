
#include <debug.h>

/*#include <asm/writer/write.h>*/
#include <asm/writer/write/addi.h>
#include <asm/writer/write/movi.h>
#include <asm/writer/write/label.h>
#include <asm/writer/write/on_zjmp.h>
#include <asm/writer/write/jmp.h>

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

int while_statement_write_asm(struct statement* super, struct asm_writer* writer)
{
	int error = 0;
	struct while_statement* const this = (typeof(this)) super;
	ENTER;
	
	TODO;
	#if 0
	#ifdef VERBOSE_ASSEMBLY
	asm_writer_comment(writer, "lines %u-%u, col %u-%u: while (%E) { ... }",
		super->loc->first_line,
		super->loc->last_line,
		super->loc->first_column,
		super->loc->last_column,
		this->conditional);
	#endif
	
	char* label_prefix = NULL;
	char* conditional_label = NULL;
	char* done_label = NULL;
	
	if (false
		|| asprintf(&label_prefix, "%uto%u_%uto%u",
			super->loc->first_line, super->loc->last_line,
			super->loc->first_column, super->loc->last_column) < 0
		|| asprintf(&conditional_label, "%s_conditional", label_prefix) < 0
		|| asprintf(&done_label, "%s_done", label_prefix) < 0)
	{
		TODO;
		error = 1;
	}
	
	if (!error)
	{
		enum register_size rs = type_get_rs(this->conditional->type);
		
		error = 0
			?: asm_writer_write_label(writer, conditional_label)
			?: expression_write_rasm(this->conditional, writer)
			?: asm_writer_write_movi_to_v2(writer, 0, stackptr, working_1, rs)
			?: asm_writer_write_addi_const(writer, 8, stackptr, quadword)
			#ifdef VERBOSE_ASSEMBLY
			?: (asm_writer_unindent(writer), 0)
			#endif
			?: asm_writer_write_on_zjmp(writer, working_1, rs, done_label)
			?: statement_write_asm(this->body, writer)
			?: asm_writer_write_jmp(writer, conditional_label)
			?: asm_writer_write_label(writer, done_label);
	}
	
	free(label_prefix);
	free(conditional_label);
	free(done_label);
	#endif
	
	EXIT;
	return error;
}


















