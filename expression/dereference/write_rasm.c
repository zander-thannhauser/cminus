
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
/*#include <asm/writer/write/mov.h>*/
/*#include <asm/writer/write/movi.h>*/
/*#include <asm/writer/write/subi.h>*/
/*#include <asm/writer/write/leag.h>*/
/*#include <asm/writer/write/pushg.h>*/
/*#include <asm/writer/write/movf.h>*/
/*#include <asm/writer/write/push.h>*/

/*#include <type/integer/struct.h>*/
/*#include <type/float/struct.h>*/
/*#include <type/struct.h>*/
/*#include <type/get_rs.h>*/

/*#include <scope/variable.h>*/

/*#include <expression/write_rasm.h>*/

#include "struct.h"
#include "write_rasm.h"

int dereference_expression_write_rasm(
	struct expression* super, struct asm_writer* writer)
{
	int error = 0;
	ENTER;
	
	struct dereference_expression* const this = (typeof(this)) super;
	
	TODO;
	
	EXIT;
	return error;
}

















