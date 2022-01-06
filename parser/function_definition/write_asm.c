
#include <stdio.h>

#include <debug.h>

/*#include <asm/tables/instrs.h>*/
/*#include <asm/tables/pktors.h>*/

#include <asm/tables/intregs.h>
#include <asm/tables/floatregs.h>
#include <asm/tables/fktors.h>

/*#include <asm/location/struct.h>*/

#include <asm/writer/write.h>

#include <asm/writer/write/movi.h>
#ifdef VERBOSE_ASSEMBLY
#include <asm/writer/comment.h>
#include <asm/writer/indent.h>
#include <asm/writer/unindent.h>
#endif
#include <asm/writer/write/mov.h>
#include <asm/writer/write/movf.h>
#include <asm/writer/write/subi.h>
#include <asm/writer/write/addi.h>
#include <asm/writer/write/push.h>
/*#include <asm/writer/write/pop.h>*/

#include <type/integer/struct.h>

#include <type/float/struct.h>

#include <type/struct.h>

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
	
	if (this->storage_class != sc_static)
		asm_writer_write(writer, ".global %s", this->name);
	
	asm_writer_write(writer, ".type %s @function", this->name);
	
	#ifdef VERBOSE_ASSEMBLY
	asm_writer_comment(writer, "function %T", this->name, ftype);
	#endif
	
	asm_writer_write(writer, "%s:", this->name);
	
	asm_writer_write(writer, "endbr64");
	
	#ifdef VERBOSE_ASSEMBLY
	asm_writer_comment(writer, "save old stack info:");
	#endif
	
	asm_writer_write_push(writer, baseptr);
	
	#ifdef VERBOSE_ASSEMBLY
	asm_writer_indent2(writer, "%s", "<old-rbp>");
	#endif
	
	asm_writer_write_movi_between_v2(writer, stackptr, baseptr, quadword);
	
	#ifdef VERBOSE_ASSEMBLY
	asm_writer_comment(writer, "allocate new stack space:");
	#endif
	asm_writer_write_subi_const(writer, this->frame_size, stackptr, quadword);
	
	#ifdef VERBOSE_ASSEMBLY
	asm_writer_indent2(writer, "%s", "<stack-frame>");
	
	asm_writer_comment(writer, "move parameters into stack:");
	#endif
	
	ssize_t regoff = 8;
	struct variable_link* vlink;
	enum integer_register_id iparam = first_parameter;
	enum float_register_id fparam = first_fparameter;
	
	for (vlink = this->parameters->head; vlink; vlink = vlink->next)
	{
		struct variable* const variable = vlink->element;
		struct type* const type = variable->type;
		
		dpvs(variable->name);
		
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_comment(writer,
			"load parameter %T (sizeof %lu):",
			variable->name, type, type->size);
		#endif
		
		switch (type->kind)
		{
			enum float_kind fkind;
			
			case tk_float:
			{
				fkind = ((struct float_type*) type)->kind;
				
				if (fparam <= first_fparameter + number_of_float_parameters)
				{
					asm_writer_write_movf_from(writer,
						fparam++,
						-variable->offset, baseptr,
						fkind);
				}
				else
				{
					asm_writer_write_mov(writer,
						regoff, baseptr,
						-variable->offset, baseptr,
						fktors[fkind]);
					
					regoff += 8;
				}
				break;
			}
			
			enum integer_kind ikind;
			
			case tk_struct:
				TODO;
				// fallthrough
			case tk_array:
				TODO;
				// fallthrough
			case tk_pointer:
				ikind = ik_unsigned_long;
				goto after_ikind;
			case tk_integer:
			{
				ikind = ((struct integer_type*) type)->kind;
				after_ikind:
				
				if (iparam <= first_parameter + number_of_integer_parameters)
				{
					TODO;
					#if 0
					asm_writer_write_movi_from(
						writer,
						/* from: */ iparam,
						/* to:   */ -variable->offset, baseptr,
						ikind);
					#endif
					
					iparam++;
				}
				else
				{
					TODO;
					#if 0
					asm_writer_write_mov(writer,
						ASMOFF(regoff), ikind,
						ASMOFF(variable->offset), ikind);
				
					regoff += 8;
					#endif
				}
				break;
			}
			
			case tk_void:
			case tk_function:
				abort();
				break;
		}
	}
	
	if (!error)
		error = compound_statement_write_asm(this->body, writer);
	
	asm_writer_write(writer, "%s_return:", this->name);
	
	#ifdef VERBOSE_ASSEMBLY
	asm_writer_comment(writer, "deallocate stack space:");
	#endif
	asm_writer_write_addi_const(writer, this->frame_size, stackptr, quadword);
	
	#ifdef VERBOSE_ASSEMBLY
	asm_writer_unindent(writer);
	asm_writer_comment(writer, "load old stack info:");
	#endif
	
	asm_writer_write(writer, "leave");
	
	#ifdef VERBOSE_ASSEMBLY
	asm_writer_unindent(writer);
	#endif
	
	asm_writer_write(writer, "ret");
	
	EXIT;
	return error;
}


















