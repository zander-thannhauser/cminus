
#include <debug.h>

#include <type/integer/struct.h>

#include <asm/location/struct.h>

#include <asm/writer/write/push.h>
#include <asm/writer/write/mov.h>

#include "struct.h"
#include "write_rasm.h"

int literal_expression_write_rasm(struct expression* super, struct asm_writer* writer)
{
	int error = 0;
	struct literal_expression* const this = (typeof(this)) super;
	ENTER;
	
	struct type* type = super->type;
	
	assert(type->kind == tk_integer || type->kind == tk_float);
	
	if (type->kind == tk_integer)
	{
		uint64_t literal;
		
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
		
		dpv(literal);
		
		asm_writer_write_mov(writer,
			ASMLIT(literal), ik_unsigned_long,
			ASMREG(working_1), ik_unsigned_long);
			
		asm_writer_write_push(writer, working_1);
	}
	else
	{
		TODO;
		#if 0
		struct float_type* ftype = (typeof(ftype)) type;
		
		switch (ftype->kind)
		{
			case fk_float: fprintf(stream, "%g", this->value._float); break;
			case fk_double: fprintf(stream, "%lg", this->value._double); break;
			
			case number_of_float_kinds: abort();
		}
		#endif
	}
	
	EXIT;
	return error;
}












