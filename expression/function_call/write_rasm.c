
#include <stdlib.h>
#include <debug.h>

#include <macros/min.h>

/*#include <asm/tables/instrs.h>*/
#include <asm/enums/intregs.h>

#include <asm/location/struct.h>
/*#include <asm/writer/comment.h>*/
/*#include <asm/writer/indent.h>*/
#include <asm/writer/write/pop.h>
#include <asm/writer/write/call.h>
#include <asm/writer/write/mov.h>
/*#include <asm/writer/write/add.h>*/
#include <asm/writer/write/push.h>
/*#include <asm/writer/unindent.h>*/

#include <expression/write_rasm.h>

#include <parser/expression_ll/struct.h>

#include "struct.h"
#include "write_rasm.h"

int function_call_expression_write_rasm(
	struct expression* super, struct asm_writer* writer)
{
	int error = 0;
	size_t i, n, m;
	struct function_call_expression* const this = (typeof(this)) super;
	ENTER;
	
	// evaluate function pointer
	error = expression_write_rasm(this->function, writer);
	
	// evaluate *last to first* parameter
	struct expression_link* alink;
	for (alink = this->arguments->tail, m = 0; !error && alink; alink = alink->prev, m++)
	{
		struct expression* const expression = alink->element;
		
		error = expression_write_rasm(expression, writer);
	}
	
	// for (int i = 0; i < min(6, n); i++):
	int reg = first_parameter;
	for (i = 0, n = min(m, 6); !error && i < n; i++)
	{
		// pop (argument register)
		asm_writer_write_pop(writer, reg++);
	}
	
	// call function pointer
	asm_writer_write_mov(writer,
		ASMOFFS(8 * (m - n)), ik_unsigned_long,
		ASMREG(reg), ik_unsigned_long);
	
	asm_writer_write_mov(writer,
		ASMLIT(0), ik_signed_int,
		ASMREG(retval), ik_signed_int);
	
	asm_writer_write_call(writer, reg);
	
	// pop remaining parameters:
	for (; !error && i < m; i++)
		asm_writer_write_pop(writer, working_1);
	
	// pop function pointer:
	asm_writer_write_pop(writer, working_1);
	
	// push retval register
	asm_writer_write_push(writer, retval);
	
	EXIT;
	return error;
}















