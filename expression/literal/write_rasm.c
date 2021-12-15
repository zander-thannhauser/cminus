
#include <debug.h>

#include <type/integer/struct.h>
#include <type/float/struct.h>

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
	}
	else
	{
		struct float_type* ftype = (typeof(ftype)) type;
		
		switch (ftype->kind)
		{
			case fk_float:
			{
				ddprintf("fk_float\n");
				
				uint32_t temp = *((typeof(temp)*) &this->value._float);
				
				asm_writer_write_mov(writer,
					ASMLIT(temp), ik_unsigned_int,
					ASMREG(working_1), ik_unsigned_int);
				
				break;
			}
			
			case fk_double:
			{
				ddprintf("fk_double\n");
				
				uint64_t temp = *((typeof(temp)*) &this->value._double);
				
				asm_writer_write_mov(writer,
					ASMLIT(temp), ik_unsigned_long,
					ASMREG(working_1), ik_unsigned_long);
				
				break;
			}
			
			case number_of_float_kinds: abort();
		}
	}
	
	asm_writer_write_push(writer, working_1);
	
	EXIT;
	return error;
}












