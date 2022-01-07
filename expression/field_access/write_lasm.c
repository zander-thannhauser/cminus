
#include <stdio.h>
#include <debug.h>

/*#include <asm/tables/instrs.h>*/
/*#include <asm/tables/intregs.h>*/
/*#include <asm/tables/pktors.h>*/

/*#include <asm/location/struct.h>*/
/*#include <asm/writer/comment.h>*/
/*#include <asm/writer/write/mov.h>*/
/*#include <asm/writer/write/pushag.h>*/

/*#include <type/integer/struct.h>*/

/*#include <asm/writer/write/lea.h>*/
/*#include <asm/writer/write/leag.h>*/
/*#include <asm/writer/write/movi.h>*/
/*#include <asm/writer/write/subi.h>*/
/*#include <asm/writer/write/push.h>*/
#include <asm/writer/write.h>

#include <type/struct/field/struct.h>

/*#include <scope/variable.h>*/

/*#include <expression/write_rasm.h>*/

#ifdef VERBOSE_ASSEMBLY
#include <asm/writer/unindent.h>
#endif

#include "../write_lasm.h"

#include "struct.h"
#include "write_lasm.h"

int field_access_expression_write_lasm(
	struct expression* super, struct asm_writer* writer)
{
	int error = 0;
	struct field_access_expression* const this = (typeof(this)) super;
/*	struct struct_field* const struct_field = this->struct_field;*/
	ENTER;
	
	error = 0
		?: expression_write_lasm(this->inner, writer)
		?: asm_writer_write(writer, "addq $%lu, 0(%%rsp)", this->field->offset);
	
	#ifdef VERBOSE_ASSEMBLY
	asm_writer_unindent(writer);
	#endif
	
	EXIT;
	return error;
}

























