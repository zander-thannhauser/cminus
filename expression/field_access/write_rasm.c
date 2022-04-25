
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
#include <asm/writer/unindent.h>
/*#include <asm/writer/write/mov.h>*/
#include <asm/writer/write/movi.h>
#include <asm/writer/write/addi.h>
#include <asm/writer/write/subi.h>
/*#include <asm/writer/write/leag.h>*/
/*#include <asm/writer/write/pushg.h>*/
/*#include <asm/writer/write/movf.h>*/
/*#include <asm/writer/write/push.h>*/

/*#include <type/integer/struct.h>*/
/*#include <type/float/struct.h>*/
#include <type/struct/field/struct.h>
#include <type/get_rs.h>

/*#include <scope/variable.h>*/

#include "../write_rasm.h"

#include "struct.h"
#include "write_rasm.h"

int field_access_expression_write_rasm(
	struct expression* super, struct asm_writer* writer)
{
	int error = 0;
	struct field_access_expression* const this = (typeof(this)) super;
	ENTER;
	
	error = 0
		?: expression_write_rasm(this->inner, writer)
		?: asm_writer_write_movi_to_v2(writer, 0, stackptr, working_1, quadword)
		?: asm_writer_write_addi_const(writer, 8, stackptr, quadword);
	
	#ifdef VERBOSE_ASSEMBLY
	asm_writer_unindent(writer);
	#endif
	
	if (!error)
	{
		asm_writer_write_movi_to_v2(writer,
			this->field->offset, working_1,
			working_2,
			type_get_rs(this->field->type));
		
		asm_writer_write_movi_from_v2(writer,
			working_2,
			-8, stackptr,
			type_get_rs(this->field->type));
		
		asm_writer_write_subi_const(writer, 8, stackptr, quadword);
	}
	
	EXIT;
	return error;
}































