
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
#include <asm/writer/write/movi.h>
#include <asm/writer/write/subi.h>
#include <asm/writer/write/addi.h>
/*#include <asm/writer/write/push.h>*/
#include <asm/writer/write.h>

#include <type/struct.h>

/*#include <type/struct/field/struct.h>*/

/*#include <scope/variable.h>*/

/*#include <expression/write_rasm.h>*/

#ifdef VERBOSE_ASSEMBLY
#include <asm/writer/unindent.h>
#endif

#include "../write_rasm.h"

#include "struct.h"
#include "write_lasm.h"

int array_index_expression_write_lasm(
	struct expression* super, struct asm_writer* writer)
{
	int error = 0;
	struct array_index_expression* const this = (typeof(this)) super;
/*	struct struct_field* const struct_field = this->struct_field;*/
	ENTER;
	
	error = 0
		?: expression_write_rasm(this->array, writer)
		?: expression_write_rasm(this->index, writer)
		?: asm_writer_write_movi_to_v2(writer, 0, stackptr, working_2, quadword)
		?: asm_writer_write_addi_const(writer, 8, stackptr, quadword)
		#ifdef VERBOSE_ASSEMBLY
		?: (asm_writer_unindent(writer), 0)
		#endif
		?: asm_writer_write_movi_to_v2(writer, 0, stackptr, working_1, quadword)
		?: asm_writer_write_addi_const(writer, 8, stackptr, quadword)
		#ifdef VERBOSE_ASSEMBLY
		?: (asm_writer_unindent(writer), 0)
		#endif
		?: asm_writer_write(writer,
			"leaq (%%r10, %%r11, %lu), %%r12", super->type->size)
		?: asm_writer_write_movi_from_v2(writer, working_3, -8, stackptr, quadword)
		?: asm_writer_write_subi_const(writer, 8, stackptr, quadword);
	
	EXIT;
	return error;
}

























