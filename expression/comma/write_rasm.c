
#include <debug.h>

/*#include <asm/tables/instrs.h>*/
/*#include <asm/tables/intregs.h>*/
/*#include <asm/tables/pktors.h>*/

/*#include <type/float/struct.h>*/
/*#include <type/integer/struct.h>*/

#ifdef VERBOSE_ASSEMBLY
/*#include <asm/writer/indent.h>*/
#include <asm/writer/unindent.h>
#endif

/*#include <asm/writer/comment.h>*/

/*#include <asm/location/struct.h>*/

/*#include <asm/writer/write/push.h>*/
/*#include <asm/writer/write/pop.h>*/
#include <asm/writer/write/addi.h>
/*#include <asm/writer/write/subi.h>*/
/*#include <asm/writer/write/mov.h>*/
/*#include <asm/writer/write/addf.h>*/
/*#include <asm/writer/write/movf.h>*/
/*#include <asm/writer/write/movi.h>*/

/*#include <type/primitive/struct.h>*/

/*#include <expression/write_rasm.h>*/
/*#include <expression/write_lasm.h>*/

#include "../write_rasm.h"

#include "struct.h"
#include "write_rasm.h"

int comma_expression_write_rasm(struct expression* super, struct asm_writer* writer)
{
	int error = 0;
	struct comma_expression* const this = (typeof(this)) super;
	ENTER;
	
	TODO;
	#if 0
	expression_write_rasm(this->left, writer);
	
	asm_writer_write_addi_const(writer, 8, stackptr, quadword);
	
	#ifdef VERBOSE_ASSEMBLY
	asm_writer_unindent(writer);
	#endif
	
	expression_write_rasm(this->right, writer);
	
	#ifdef VERBOSE_ASSEMBLY
	asm_writer_unindent(writer);
	#endif
	#endif
	
	EXIT;
	return error;
}

























