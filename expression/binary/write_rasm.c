
#include <debug.h>

/*#include <asm/tables/instrs.h>*/
/*#include <asm/tables/intregs.h>*/
/*#include <asm/tables/pktors.h>*/

#include <type/float/struct.h>
#include <type/integer/struct.h>

#include <asm/writer/indent.h>
#include <asm/writer/unindent.h>
#include <asm/writer/comment.h>

#include <asm/location/struct.h>

#include <asm/writer/write/push.h>
#include <asm/writer/write/pop.h>
#include <asm/writer/write/add.h>
#include <asm/writer/write/mov.h>
#include <asm/writer/write/addf.h>
#include <asm/writer/write/movf.h>

/*#include <type/primitive/struct.h>*/

#include <expression/write_rasm.h>
#include <expression/write_lasm.h>

#include "struct.h"
#include "write_rasm.h"

static int both_as_rvalues(
	struct binary_expression* const this,
	struct asm_writer* writer)
{
	int error = 0;
	ENTER;
	
	asm_writer_indent(writer);
	
	error = 0
		?: expression_write_rasm(this->left, writer)
		?: expression_write_rasm(this->right, writer);
	
	asm_writer_unindent(writer);
	
	if (!error)
	{
		asm_writer_write_pop(writer, working_2);
		asm_writer_write_pop(writer, working_1);
	}
	
	EXIT;
	return error;
}

static int as_lvalue_and_rvalue(struct binary_expression* const this, struct asm_writer* writer)
{
	int error = 0;
	ENTER;
	
	asm_writer_indent(writer);
	
	error = 0
		?: expression_write_lasm(this->left, writer)
		?: expression_write_rasm(this->right, writer);
	
	asm_writer_unindent(writer);
	
	if (!error)
	{
		asm_writer_write_pop(writer, working_2);
		asm_writer_write_pop(writer, working_1);
	}
	
	EXIT;
	return error;
}

int binary_expression_write_rasm(struct expression* super, struct asm_writer* writer)
{
	int error = 0;
	struct binary_expression* const this = (typeof(this)) super;
	ENTER;
	
	dpv(this->kind);
	
/*	enum register_size rs = pktors[((struct primitive_type*) this->left->type)->kind];*/
	
	switch (this->kind)
	{
		case bek_add:
		{
			error = both_as_rvalues(this, writer);
			
			if (this->is_integer_result)
			{
				struct integer_type* itype = (typeof(itype)) super->type;
				
				asm_writer_write_add(writer,
					ASMREG(working_1),
					ASMREG(working_2),
					itype->kind);
			}
			else
			{
				struct float_type* ftype = (typeof(ftype)) super->type;
				
				asm_writer_write_movf(writer,
					ASMREG(working_1), ftype->kind,
					ASMFREG(working_f1), ftype->kind);
				
				asm_writer_write_movf(writer,
					ASMREG(working_2), ftype->kind,
					ASMFREG(working_f2), ftype->kind);
				
				asm_writer_write_addf(writer,
					ASMFREG(working_f1),
					ASMFREG(working_f2),
					ftype->kind);
				
				asm_writer_write_movf(writer,
					ASMFREG(working_f2), ftype->kind,
					ASMREG(working_2), ftype->kind);
			}
			
			asm_writer_write_push(writer, working_2);
			
			break;
		}
		
		case bek_regular_assign:
		{
			error = as_lvalue_and_rvalue(this, writer);
			
			// working_1 contains a memory address
			// working_2 contains the new value
			
			if (this->is_integer_result)
			{
				struct integer_type* itype = (typeof(itype)) super->type;
				
				asm_writer_write_mov(writer,
					ASMREG(working_2), itype->kind,
					ASMDEF(working_1), itype->kind);
				
				asm_writer_write_push(writer, working_2);
			}
			else
			{
				struct float_type* ftype = (typeof(ftype)) super->type;
				
				asm_writer_write_movf(writer,
					ASMREG(working_2), ftype->kind,
					ASMDEF(working_1), ftype->kind);
				
				asm_writer_write_push(writer, working_2);
			}
			
			break;
		}
		
		default:
			TODO;
			break;
	}
	
	EXIT;
	return error;
}

























