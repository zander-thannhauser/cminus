
#include <stdio.h>
#include <debug.h>

/*#include <asm/tables/instrs.h>*/
/*#include <asm/tables/intregs.h>*/
/*#include <asm/tables/pktors.h>*/

#include <asm/location/struct.h>
#include <asm/writer/comment.h>
/*#include <asm/writer/write/mov.h>*/
/*#include <asm/writer/write/pushag.h>*/

/*#include <type/integer/struct.h>*/

#include <asm/writer/write/lea.h>
#include <asm/writer/write/leag.h>
#include <asm/writer/write/movi.h>
#include <asm/writer/write/subi.h>
/*#include <asm/writer/write/push.h>*/

#include <scope/variable.h>

/*#include <expression/write_rasm.h>*/

#include "struct.h"
#include "write_lasm.h"

int variable_expression_write_lasm(
	struct expression* super, struct asm_writer* writer)
{
	int error = 0;
	struct variable_expression* const this = (typeof(this)) super;
	struct variable* const variable = this->variable;
	ENTER;
	
	dpvs(variable->name);
	
	if (!variable->is_global)
	{
		// load effective address
		asm_writer_write_lea(writer, -variable->offset, baseptr, working_1);
	}
	else if (variable->storage_class == sc_static)
	{
		TODO;
	}
	else
	{
		asm_writer_write_leag(writer, variable->name, working_1);
	}
	
	asm_writer_write_movi_from(writer, working_1, -8, stackptr, ik_unsigned_long);
	asm_writer_write_subi_const(writer, 8, stackptr, quadword);
	
	EXIT;
	return error;
}

























