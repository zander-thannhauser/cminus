
#include <stdlib.h>

#include <assert.h>

#include <type/integer/struct.h>
#include <type/float/struct.h>

#include <asm/location/struct.h>

#include <asm/writer/write/pushi.h>
/*#include <asm/writer/write/pushd.h>*/
/*#include <asm/writer/write/pushf.h>*/
/*#include <asm/writer/write/mov.h>*/
/*#include <asm/writer/indent.h>*/
/*#include <asm/writer/comment.h>*/

#include "struct.h"
#include "write_rasm.h"

int literal_expression_write_rasm(struct expression* super, struct asm_writer* writer)
{
	int error = 0;
	struct literal_expression* const this = (typeof(this)) super;
	ENTER;
	
	struct type* type = super->type;
	
	assert(type->kind == tk_integer || type->kind == tk_float);
	
	uint64_t literal;
	
	if (type->kind == tk_integer)
	{
		struct integer_type* itype = (typeof(itype)) type;
		
		switch (itype->kind)
		{
			case ik_signed_char:    literal = this->value._signed_char;     break;
			case ik_unsigned_char:  literal = this->value._unsigned_char;   break;
			case ik_signed_short:   literal = this->value._signed_short;   break;
			case ik_unsigned_short: literal = this->value._unsigned_short; break;
			case ik_signed_int:     literal = this->value._signed_int;     break;
			case ik_unsigned_int:   literal = this->value._unsigned_int;   break;
			case ik_signed_long:    literal = this->value._signed_long;    break;
			case ik_unsigned_long:  literal = this->value._unsigned_long;  break;
			
			case number_of_integer_kinds: abort();
		}
	}
	else
	{
		struct float_type* ftype = (typeof(ftype)) type;
		
		switch (ftype->kind)
		{
			#pragma GCC diagnostic push
			#pragma GCC diagnostic ignored "-Wstrict-aliasing"
			case fk_float:
			{
				literal = *((uint32_t*) &this->value._float);
				break;
			}
			
			case fk_double:
			{
				literal = *((uint64_t*) &this->value._double);
				break;
			}
			
			case number_of_float_kinds: abort();
			#pragma GCC diagnostic pop
		}
	}
	
	asm_writer_write_pushi(writer, literal);
	
	EXIT;
	return error;
}












