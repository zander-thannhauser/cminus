
#include <stdlib.h>
#include <debug.h>

#include <macros/min.h>

#include <type/struct.h>

/*#include <asm/tables/instrs.h>*/
#include <asm/enums/intregs.h>
#include <asm/enums/floatregs.h>

#include <asm/location/struct.h>

#include <asm/writer/comment.h>
/*#include <asm/writer/indent.h>*/
#include <asm/writer/write/pop.h>
#include <asm/writer/write/call.h>
#include <asm/writer/write/mov.h>
#include <asm/writer/write/add.h>
#include <asm/writer/write/sub.h>
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
	
	// first to last: when do we stop doing integers from behind?
	unsigned n_int_params = 0;
	struct expression_link* ilink = this->arguments->head;
	
	for (; ilink; ilink = ilink->next)
		if (ilink->element->type->kind != tk_float)
			if (++n_int_params == number_of_integer_parameters)
				break;
	
	dpv(n_int_params);
	
	// first to last: when do we stop doing floats from behind?
	unsigned n_float_params = 0;
	struct expression_link* flink = this->arguments->head;
	
	for (; flink; flink = flink->next)
		if (flink->element->type->kind == tk_float)
			if (++n_float_params == number_of_float_parameters)
				break;
	
	dpv(n_float_params);
	
	bool extra_push = false;
	if (((1 + this->arguments->n - n_int_params - n_float_params) % 2))
	{
		extra_push = true;
		asm_writer_comment(writer, "ensuring the stack frame is 16-byte aligned:");
		asm_writer_write_sub(writer,
			ASMLIT(8),
			ASMREG(stackptr),
			ik_unsigned_long);
	}
	
	// evaluate function pointer
	error = expression_write_rasm(this->function, writer);
	
	struct expression_link* elink;
	bool more_integers = ilink, more_floats = flink;
	unsigned n_overflow_params = 0;
	
	// push all arguments that don't get a register from tail to head:
	for (elink = this->arguments->tail;
		!error && (more_integers || more_floats);
		elink = elink->prev)
	{
		dpv(elink);
		dpv(ilink);
		dpv(flink);
		
		dpvb(more_integers);
		dpvb(more_floats);
		
		struct expression* const e = elink->element;
		
		if ((e->type->kind == tk_float))
		{
			if (more_floats)
			{
				if (flink == elink)
					more_floats = false;
				else
					n_overflow_params++, error = expression_write_rasm(e, writer);
			}
		}
		else if (more_integers)
		{
			if (ilink == elink)
				more_integers = false;
			else
				n_overflow_params++, error = expression_write_rasm(e, writer);
		}
	}
	
	dpv(n_int_params);
	dpv(n_float_params);
	dpv(n_overflow_params);
	assert(n_int_params + n_float_params + n_overflow_params == this->arguments->n);
	
	dpv(elink);
	
	assert(elink);
	
	dpv(ilink);
	
	// push all integer arguments that do get a register:
	if (n_int_params && !ilink)
		ilink = this->arguments->tail;
	
	for (i = 0, n = n_int_params; !error && i < n; ilink = ilink->prev)
		if (ilink->element->type->kind != tk_float)
			i++, error = expression_write_rasm(ilink->element, writer);
	
	// push all float arguments that do get a register:
	if (n_float_params && !flink)
		flink = this->arguments->tail;
	
	for (i = 0, n = n_float_params; !error && i < n; flink = flink->prev)
		if (flink->element->type->kind == tk_float)
			i++, error = expression_write_rasm(flink->element, writer);
	
	int reg;
	
	// pop floats off the stack, assigning them registers:
	for (i = 0, n = n_float_params, reg = first_fparameter; !error && i < n; i++)
	{
		asm_writer_write_pop(writer, working_1);
		
		asm_writer_write_mov(writer,
			ASMREG(working_1), ik_unsigned_long,
			ASMFREG(reg++), ik_unsigned_long);
	}
	
	// pop integer off the stack, assigning them registers:
	for (i = 0, n = n_int_params, reg = first_parameter; !error && i < n; i++)
		asm_writer_write_pop(writer, reg++);
	
	// reach for function pointer:
	asm_writer_write_mov(writer,
		ASMOFFS(8 * (n_overflow_params)), ik_unsigned_long,
		ASMREG(reg), ik_unsigned_long);
	
	// set rax indicating how many floats.
	asm_writer_write_mov(writer,
		ASMLIT(n_float_params), ik_unsigned_int,
		ASMREG(retval), ik_unsigned_int);
	
	asm_writer_write_call(writer, reg);
	
	// pop remaining parameters:
	for (i = 0; !error && i < n_overflow_params; i++)
		asm_writer_write_pop(writer, working_1);
	
	// pop function pointer:
	asm_writer_write_pop(writer, working_1);
	
	if (extra_push)
		asm_writer_write_add(writer,
			ASMLIT(8),
			ASMREG(stackptr),
			ik_unsigned_long);
	
	// push retval register
	if (super->type->kind == tk_float)
	{
		asm_writer_write_mov(writer,
			ASMFREG(fretval), ik_unsigned_long,
			ASMREG(working_1), ik_unsigned_long);
		
		asm_writer_write_push(writer, working_1);
	}
	else
	{
		asm_writer_write_push(writer, retval);
	}
	
	EXIT;
	return error;
}















