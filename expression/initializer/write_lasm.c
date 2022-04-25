
#include <stdio.h>
#include <assert.h>

/*#include <asm/tables/instrs.h>*/
/*#include <asm/tables/intregs.h>*/
/*#include <asm/tables/pktors.h>*/

/*#include <asm/enums/intregs.h>*/

/*#include <asm/location/struct.h>*/
/*#include <asm/writer/comment.h>*/
#include <asm/writer/write/movi.h>
/*#include <asm/writer/write/pushag.h>*/

#include <type/get_rs.h>
#include <type/struct.h>
/*#include <type/compare.h>*/

/*#include <asm/writer/write.h>*/
#include <asm/writer/write/lea.h>
/*#include <asm/writer/write/leag.h>*/
#include <asm/writer/write/mov.h>
/*#include <asm/writer/write/movi.h>*/
#include <asm/writer/write/addi.h>
#include <asm/writer/write/subi.h>
#include <asm/writer/write/memset.h>
/*#include <asm/writer/write/push.h>*/

/*#include <scope/variable.h>*/

/*#include <expression/write_rasm.h>*/

#include <parser/initializer/traverse.h>

#ifdef VERBOSE_ASSEMBLY
#include <asm/writer/comment.h>
#include <asm/writer/unindent.h>
#endif

#include "../write_rasm.h"

#include "struct.h"
#include "write_lasm.h"

int initializer_expression_write_lasm(
	struct expression* super,
	struct asm_writer* writer)
{
	int error = 0;
	struct initializer_expression* const this = (typeof(this)) super;
	ENTER;
	
	size_t offset = this->stack_offset;
	
	int on_zero(size_t size)
	{
		int error = 0;
		ENTER;
		
		error = 0
			#ifdef VERBOSE_ASSEMBLY
			?: asm_writer_comment(writer, "... with zeros")
			#endif
			?: asm_writer_write_memset(writer, -offset, baseptr, 0, size);
		
		EXIT;
		return error;
	}
	
	int on_primitive(struct type* t, struct expression** e)
	{
		int error = 0;
		ENTER;
		
		error = 0
			#ifdef VERBOSE_ASSEMBLY
			?: asm_writer_comment(writer, "... with %E", *e)
			#endif
			?: expression_write_rasm(*e, writer)
			?: asm_writer_write_mov(writer,
				0, stackptr, -offset, baseptr, type_get_rs(t))
			?: asm_writer_write_addi_const(writer, 8, stackptr, quadword);
		
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_unindent(writer);
		#endif
		
		offset -= t->size;
		
		EXIT;
		return error;
	}
	
	int on_struct(struct struct_type* t, struct expression** e)
	{
		int error = 0;
		ENTER;
		
		// memcpy()
		TODO;
		
		EXIT;
		return error;
	}
	
	int ef(struct type* t, const char* n)
	{
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_comment(writer, "initializing field '%s'", n);
		#endif
		return 0;
	}
	
	int xf(struct type* t)
	{
		return 0;
	}
	
	int ei(unsigned long i)
	{
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_comment(writer, "initializing element [%lu]", i);
		#endif
		return 0;
	}
	
	int xi(unsigned long i)
	{
		return 0;
	}
	
	error = initializer_traverse(
		this->initializer, super->type,
		on_zero,
		(void*) on_primitive, (void*) on_primitive,
		(void*) on_primitive,
		on_struct, ef, xf, ei, xi);
	
	// then movi stack_offset to -8(stackptr)
	asm_writer_write_lea(writer, -this->stack_offset, baseptr, working_1);
	asm_writer_write_movi_from_v2(writer, working_1, -8, stackptr, quadword);
	asm_writer_write_subi_const(writer, 8, stackptr, quadword);
	
	EXIT;
	return error;
}

























