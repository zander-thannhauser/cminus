
#include <stdlib.h>

#include <stdio.h>
#include <debug.h>

#include <asm/enums/intregs.h>
/*#include <asm/tables/instrs.h>*/
/*#include <asm/tables/intregs.h>*/
#include <asm/tables/fktors.h>
#include <asm/tables/iktors.h>

/*#include <asm/location/struct.h>*/

/*#include <asm/writer/comment.h>*/
#include <asm/writer/indent.h>
#include <asm/writer/write/mov.h>
#include <asm/writer/write/subi.h>
#include <asm/writer/write/pushg.h>
/*#include <asm/writer/write/movf.h>*/
/*#include <asm/writer/write/push.h>*/

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
			case tk_float:
			{
				struct float_type* ftype = (typeof(ftype)) type;
				
				asm_writer_write_mov(writer,
					-variable->offset, baseptr,
					-8, stackptr,
					fktors[ftype->kind]);
				
				break;
			}
			
			case tk_integer:
			{
				struct integer_type* itype = (typeof(itype)) type;
				
				asm_writer_write_mov(writer,
					-variable->offset, baseptr,
					-8, stackptr,
					iktors[itype->kind]);
				
				break;
			}
			
			case tk_pointer:
				TODO;
				break;
			
			case tk_array:
			case tk_struct:
			case tk_function:
			case tk_void:
				abort();
		}
		
		asm_writer_write_subi_const(writer, 8, stackptr, quadword);
	}
	else
	{
		TODO;
		#if 0
		asm_writer_write_pushg(writer, variable->name);
		#endif
	}
	
	EXIT;
	return error;
}

















