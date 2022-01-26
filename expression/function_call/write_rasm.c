
#include <stdlib.h>
#include <debug.h>

/*#include <macros/min.h>*/

#include <type/get_rs.h>
#include <type/float/struct.h>

/*#include <asm/tables/instrs.h>*/
#include <asm/enums/intregs.h>
#include <asm/enums/floatregs.h>

/*#include <asm/location/struct.h>*/

#ifdef VERBOSE_ASSEMBLY
#include <asm/writer/comment.h>
#include <asm/writer/indent.h>
#include <asm/writer/unindent.h>
#endif

/*#include <asm/writer/write/pop.h>*/
/*#include <asm/writer/write/push.h>*/
#include <asm/writer/write/call.h>
#include <asm/writer/write/mov.h>
#include <asm/writer/write/movi.h>
#include <asm/writer/write/movf.h>
#include <asm/writer/write/integer.h>
#include <asm/writer/write/addi.h>
#include <asm/writer/write/subi.h>
/*#include <asm/writer/write/push.h>*/

#include <expression/write_rasm.h>

#include <parser/expression_ll/struct.h>

#include "struct.h"
#include "write_rasm.h"

int function_call_expression_write_rasm(
	struct expression* super, struct asm_writer* writer)
{
	int error = 0;
	size_t i, n; // , m;
	struct function_call_expression* const this = (typeof(this)) super;
	ENTER;
	
	TODO;
	#if 0
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
	
	#ifdef X64_TARGET
	bool extra_push = false;
	
	if (((1 + this->arguments->n - n_int_params - n_float_params) % 2))
	{
		extra_push = true;
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_comment(writer, "ensuring the stack frame is 16-byte aligned:");
		#endif
		
		asm_writer_write_subi_const(writer, 8, stackptr, quadword);
		
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_indent2(writer, "<stack-align>");
		#endif
	}
	#endif
	
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
		asm_writer_write_movf_to(writer,
			0, stackptr,
			reg++,
			fk_double);
		
		asm_writer_write_addi_const(writer, 8, stackptr, quadword);
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_unindent(writer);
		#endif
	}
	
	// pop integer off the stack, assigning them registers:
	for (i = 0, n = n_int_params, reg = first_parameter; !error && i < n; i++)
	{
		asm_writer_write_movi_to_v2(writer, 0, stackptr, reg++, quadword);
		asm_writer_write_addi_const(writer, 8, stackptr, quadword);
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_unindent(writer);
		#endif
	}
	
	// reach for function pointer:
	asm_writer_write_movi_to_v2(writer,
		8 * n_overflow_params, stackptr, reg, quadword);
	
	// set rax indicating how many floats.
	asm_writer_write_integer(writer,
		n_float_params,
		retval,
		quadword);
	
	asm_writer_write_call(writer, reg);
	
	// pop remaining parameters:
	for (i = 0; !error && i < n_overflow_params; i++)
	{
		asm_writer_write_addi_const(writer, 8, stackptr, quadword);
		
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_unindent(writer);
		#endif
	}
	
	// pop function pointer:
	asm_writer_write_addi_const(writer, 8, stackptr, quadword);
	#ifdef VERBOSE_ASSEMBLY
	asm_writer_unindent(writer);
	#endif
	
	#ifdef X64_TARGET
	if (extra_push)
	{
		asm_writer_write_addi_const(writer, 8, stackptr, quadword);
		
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_unindent(writer);
		#endif
	}
	#endif
	
	// push retval register
	if (super->type->kind == tk_void)
	{
		// do nothing
	}
	else if (super->type->kind == tk_float)
	{
		struct float_type *type = (typeof(type)) super->type;
		
		asm_writer_write_movf_from(writer, fretval, -8, stackptr, type->kind);
	}
	else
	{
		dpv(super->type->kind);
		
		asm_writer_write_movi_from_v2(writer, retval, -8, stackptr,
			type_get_rs(super->type));
	}
	
	asm_writer_write_subi_const(writer, 8, stackptr, quadword);
	#endif
	
	EXIT;
	return error;
}















