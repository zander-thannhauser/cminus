
#include <stdlib.h>

#include <stdio.h>
#include <assert.h>

/*#include <asm/enums/intregs.h>*/
/*#include <asm/tables/instrs.h>*/
#include <asm/tables/intregs.h>
/*#include <asm/tables/fktors.h>*/
/*#include <asm/tables/iktors.h>*/

/*#include <asm/location/struct.h>*/

#include <asm/writer/write.h>
#include <asm/writer/write/movi.h>
#include <asm/writer/write/addi.h>
#include <asm/writer/write/subi.h>
/*#include <asm/writer/write/leag.h>*/
/*#include <asm/writer/write/pushg.h>*/
/*#include <asm/writer/write/movf.h>*/
/*#include <asm/writer/write/push.h>*/

#include <type/struct.h>
/*#include <type/float/struct.h>*/
/*#include <type/struct/field/struct.h>*/
#include <type/get_rs.h>

#ifdef VERBOSE_ASSEMBLY
#include <asm/writer/comment.h>
#include <asm/writer/unindent.h>
#endif

#include "../write_rasm.h"

#include "struct.h"
#include "write_rasm.h"

int array_index_expression_write_rasm(
	struct expression* super,
	struct asm_writer* writer)
{
	int error = 0;
	struct array_index_expression* const this = (typeof(this)) super;
	ENTER;
	
	enum register_size rs = type_get_rs(super->type);
	
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
			"%s (%%r10, %%r11, %lu), %s",
			((char*[]) {"movb", "mov", "movl", "movq"})[rs],
			super->type->size,
			intregs[working_3][rs])
		?: asm_writer_write_movi_from_v2(writer, working_3, -8, stackptr, rs)
		?: asm_writer_write_subi_const(writer, 8, stackptr, quadword);
	
	EXIT;
	return error;
}































