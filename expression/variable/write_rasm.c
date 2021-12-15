
#include <stdio.h>
#include <debug.h>

/*#include <asm/tables/instrs.h>*/
/*#include <asm/tables/intregs.h>*/
/*#include <asm/tables/pktors.h>*/


#include <asm/location/struct.h>

#include <asm/writer/comment.h>
#include <asm/writer/write/mov.h>
#include <asm/writer/write/movf.h>
#include <asm/writer/write/push.h>

#include <type/integer/struct.h>
#include <type/float/struct.h>

#include <scope/variable.h>

/*#include <expression/write_rasm.h>*/

#include "struct.h"
#include "write_rasm.h"

int variable_expression_write_rasm(
	struct expression* super, struct asm_writer* writer)
{
	int error = 0;
	struct variable_expression* const this = (typeof(this)) super;
	struct variable* const variable = this->variable;
	ENTER;
	
	dpvs(variable->name);
	
	if (!variable->is_global)
	{
		struct type* const type = variable->type;
		
		switch (type->kind)
		{
			case tk_struct: TODO; break;
			
			case tk_array: TODO; break;
			
			case tk_float:
			{
				struct float_type* ftype = (typeof(ftype)) type;
				
				asm_writer_write_movf(writer,
					ASMOFF(variable->offset), ftype->kind,
					ASMREG(working_1), ftype->kind);
				break;
			}
			
			case tk_integer:
			{
				struct integer_type* itype = (typeof(itype)) type;
				
				asm_writer_write_mov(writer,
					ASMOFF(variable->offset), itype->kind,
					ASMREG(working_1), itype->kind);
				
				break;
			}
			
			case tk_pointer:
				TODO;
				break;
			
			case tk_function:
			case tk_void:
				abort();
		}
	}
	else if (variable->storage_class == sc_static)
	{
		TODO;
	}
	else
	{
		asm_writer_write_mov(writer,
			ASMGLO(variable->name), ik_unsigned_long,
			ASMREG(working_1), ik_unsigned_long);
	}
	
	asm_writer_write_push(writer, working_1);
	
	EXIT;
	return error;
}

















