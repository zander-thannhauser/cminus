
#include <stdio.h>

#include <debug.h>

/*#include <asm/tables/instrs.h>*/
/*#include <asm/tables/pktors.h>*/
/*#include <asm/tables/intregs.h>*/

#include <asm/writer/comment.h>
#include <asm/writer/indent.h>
#include <asm/writer/unindent.h>

#include <asm/location/struct.h>

#include <asm/writer/write.h>

#include <asm/writer/write/mov.h>
#include <asm/writer/write/sub.h>
#include <asm/writer/write/push.h>
#include <asm/writer/write/pop.h>

#include <type/integer/struct.h>

#include <scope/variable.h>

#include <parser/variable_ll/struct.h>

#include <statement/compound/write_asm.h>

#include "struct.h"
#include "write_asm.h"

int function_definition_write_asm(
	struct function_definition* this,
	struct asm_writer* writer)
{
	int error = 0;
	struct function_type *const ftype = this->ftype;
	ENTER;
	
	asm_writer_comment(writer, "definition for function %s():", this->name);
	
	if (this->storage_class != sc_static)
	{
		asm_writer_write(writer, ".global %s", this->name);
	}
	
	asm_writer_write(writer, ".type %s @function", this->name);
	
	asm_writer_write(writer, "%s:", this->name);
	
	asm_writer_indent(writer);
	
	asm_writer_comment(writer, "reset branch-prediction:");
	asm_writer_write(writer, "endbr64");
	
	asm_writer_comment(writer, "save old stack info:");
	asm_writer_write_push(writer, baseptr);
	asm_writer_write_mov(writer,
		/* src: */ ASMREG(stackptr), ik_unsigned_long,
		/* dst: */ ASMREG(baseptr), ik_unsigned_long);
	
	asm_writer_comment(writer, "allocate new stack space:");
	asm_writer_write_sub(writer,
		ASMLIT(this->frame_size),
		ASMREG(stackptr),
		ik_unsigned_long);
	
	asm_writer_comment(writer, "move parameters into stack:");
	asm_writer_indent(writer);
	
	ssize_t regoff = -8;
	struct variable_link* vlink;
	enum integer_register_id iparam = first_parameter;
/*	enum float_register_id fparam = first__parameter;*/
	for (vlink = this->parameters->head; vlink; vlink = vlink->next)
	{
		struct variable* const variable = vlink->element;
		struct type* const type = variable->type;
		
		dpvs(variable->name);
		
		asm_writer_comment(writer,
			"parameter '%s' (sizeof(%T) == %lu):",
			variable->name, type, type->size);
		
		switch (type->kind)
		{
			case tk_struct:
			{
				TODO;
				break;
			}
			
			case tk_float:
			{
				TODO;
				#if 0
				struct float_type* const ftype = (typeof(ftype)) type;
				enum float_kind fkind;
				
				if (fparam <= sixth_parameter)
				{
					asm_writer_write_movf(writer,
						ASMREG(fparam), fkind,
						ASMOFF(variable->offset), fkind);
					
					fparam++;
				}
				else
				{
					asm_writer_write_movf(writer,
						ASMOFF(regoff), fkind,
						ASMOFF(variable->offset), fkind);
					
					regoff += 8;
				}
				#endif
				break;
			}
			
			enum integer_kind ikind;
			
			case tk_pointer:
				ikind = ik_unsigned_long;
				goto after_ikind;
			case tk_integer:
			{
				ikind = ((struct integer_type*) type)->kind;
				after_ikind:
				
				if (iparam <= sixth_parameter)
				{
					asm_writer_write_mov(writer,
						ASMREG(iparam), ikind,
						ASMOFF(variable->offset), ikind);
					
					iparam++;
				}
				else
				{
					asm_writer_write_mov(writer,
						ASMOFF(regoff), ikind,
						ASMOFF(variable->offset), ikind);
					
					regoff += 8;
				}
				break;
			}
			
			case tk_void:
			case tk_array:
			case tk_function:
				abort();
				break;
		}
	}
	
	asm_writer_unindent(writer);
	
	asm_writer_comment(writer, "function body:");
	
	if (!error)
	{
		asm_writer_indent(writer);
		
		error = compound_statement_write_asm(this->body, writer);
		
		asm_writer_unindent(writer);
	}
	
	asm_writer_comment(writer, "load old stack info:");
/*	asm_writer_write_pop(writer, baseptr);*/
	asm_writer_write(writer, "leave");
	asm_writer_write(writer, "ret");
	
	asm_writer_unindent(writer);
	
	EXIT;
	return error;
}


















