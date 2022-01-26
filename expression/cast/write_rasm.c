
#include <debug.h>

#include <asm/tables/iktors.h>

#include <type/float/struct.h>
#include <type/integer/struct.h>

/*#include <asm/location/struct.h>*/

#include <asm/writer/write/movf.h>
#include <asm/writer/write/movi.h>
#include <asm/writer/write/itof.h>
#include <asm/writer/write/ftoi.h>
#include <asm/writer/write/movsx.h>
/*#include <asm/writer/write/chint.h>*/
#include <asm/writer/write/chfloat.h>
#include <expression/write_rasm.h>

#ifdef VERBOSE_ASSEMBLY
#include <asm/writer/unindent.h>
#endif

#include "struct.h"
#include "write_rasm.h"

int cast_expression_write_rasm(struct expression* super, struct asm_writer* writer)
{
	int error = 0;
	struct cast_expression* const this = (typeof(this)) super;
	struct type* const bt = this->inner->type;
	struct type* const at = this->type;
	ENTER;
	
	TODO;
	#if 0
	error = expression_write_rasm(this->inner, writer);
	
	if (bt->kind == tk_integer && at->kind == tk_integer)
	{
		struct integer_type* const ibt = (typeof(ibt)) bt;
		struct integer_type* const iat = (typeof(iat)) at;
		
		asm_writer_write_movi_to_v2(writer, 0, stackptr, working_1, iktors[ibt->kind]);
		
		if ((ibt->kind & ~1) == (iat->kind & ~1))
		{
			HERE; // same-sized integers: nothing to do
		}
		else if ((ibt->kind & 1) && (iat->kind & 1))
		{
			// unsigned to unsigned
			if (ibt->kind < iat->kind)
			{
				// getting larger
				TODO;
			}
			else
			{
				// getting smaller
				TODO;
			}
		}
		else if (!(ibt->kind & 1) && (iat->kind & 1))
		{
			// signed to unsigned
			if (ibt->kind < iat->kind)
			{
				// getting larger
				TODO;
			}
			else
			{
				// getting smaller
				TODO;
			}
		}
		else if ((ibt->kind & 1) && !(iat->kind & 1))
		{
			// unsigned to signed
			if (ibt->kind < iat->kind)
			{
				// getting larger
				TODO;
			}
			else
			{
				// getting smaller
				TODO;
			}
		}
		else
		{
			// signed to signed
			if (ibt->kind < iat->kind)
			{
				// getting larger
				asm_writer_write_movsx(writer,
					working_1, iktors[ibt->kind],
					working_1, iktors[iat->kind]);
			}
			else
			{
				// getting smaller
			}
		}
		
		asm_writer_write_movi_from_v2(writer, working_1, 0, stackptr, iktors[iat->kind]);
	}
	else if (bt->kind == tk_integer && at->kind == tk_float)
	{
		struct integer_type* const ibt = (typeof(ibt)) bt;
		struct float_type* const fat = (typeof(fat)) at;
		
		asm_writer_write_itof(writer, 0, stackptr, ibt->kind, working_f1, fat->kind);
		
		asm_writer_write_movf_from(writer, working_f1, 0, stackptr, fat->kind);
	}
	else if (bt->kind == tk_float && at->kind == tk_integer)
	{
		struct float_type* const fbt = (typeof(fbt)) bt;
		struct integer_type* const iat = (typeof(iat)) at;
		
		asm_writer_write_ftoi(writer, 0, stackptr, fbt->kind, working_1, iat->kind);
		
		asm_writer_write_movi_from_v2(writer, working_1, 0, stackptr, iktors[iat->kind]);
	}
	else if (bt->kind == tk_float && at->kind == tk_float)
	{
		struct float_type* const fbt = (typeof(fbt)) bt;
		struct float_type* const fat = (typeof(fat)) at;
		
		asm_writer_write_chfloat(writer,
			0, stackptr, fbt->kind,
			working_f1, fat->kind);
		
		asm_writer_write_movf_from(writer,
			working_f1,
			0, stackptr,
			fat->kind);
	}
	else
	{
		error = 1;
		TODO;
	}
	
	#ifdef VERBOSE_ASSEMBLY
	asm_writer_unindent(writer);
	#endif
	#endif
	
	EXIT;
	return error;
}










