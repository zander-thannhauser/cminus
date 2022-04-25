
#include <stdlib.h>

#include <stdio.h>
#include <assert.h>

/*#include <asm/enums/intregs.h>*/
/*#include <asm/tables/instrs.h>*/
/*#include <asm/tables/intregs.h>*/
/*#include <asm/tables/fktors.h>*/
/*#include <asm/tables/iktors.h>*/

/*#include <asm/location/struct.h>*/

/*#include <asm/writer/comment.h>*/
/*#include <asm/writer/indent.h>*/
#include <asm/writer/write/mov.h>
#include <asm/writer/write/movi.h>
#include <asm/writer/write/subi.h>
#include <asm/writer/write/leag.h>
/*#include <asm/writer/write/pushg.h>*/
/*#include <asm/writer/write/movf.h>*/
/*#include <asm/writer/write/push.h>*/

/*#include <type/integer/struct.h>*/
/*#include <type/float/struct.h>*/
#include <type/struct.h>
#include <type/get_rs.h>

#include <scope/variable.h>

/*#include <expression/write_rasm.h>*/

#include "struct.h"
#include "write_rasm.h"

int variable_expression_write_rasm(
	struct expression* super, struct asm_writer* writer)
{
	int error = 0;
	ENTER;
	
	struct variable_expression* const this = (typeof(this)) super;
	struct variable* const variable = this->variable;
	struct type* const type = variable->type;
	enum register_size rs = type_get_rs(type);
	
	dpvs(variable->name);
	
	assert(variable->type->is_complete);
	
	if (variable->is_global)
	{
		asm_writer_write_leag(writer, variable->name, working_1);
		
		asm_writer_write_movi_to_v2(
			writer,
			0, working_1,
			working_2,
			rs);
		
		asm_writer_write_movi_from_v2(
			writer,
			working_2,
			-8, stackptr,
			rs);
	}
	else
	{
		asm_writer_write_mov(writer,
			-variable->offset, baseptr,
			-8, stackptr,
			rs);
	}
	
	asm_writer_write_subi_const(writer, 8, stackptr, quadword);
	
	EXIT;
	return error;
}

















