
#include <debug.h>

#include <type/struct.h>
#include <type/integer/struct.h>
#include <type/float/struct.h>
/*#include <type/array/struct.h>*/
/*#include <type/struct/struct.h>*/
/*#include <type/struct/field/struct.h>*/
/*#include <type/struct/field_ll/struct.h>*/

#include <expression/struct.h>
#include <expression/literal/struct.h>
/*#include <expression/cast/new.h>*/

/*#include <parser/ptree/initializer_ll/struct.h>*/
#include <parser/initializer/traverse.h>

#include "../write.h"

#ifdef VERBOSE_ASSEMBLY
#include "../comment.h"
#include "../indent.h"
#include "../unindent.h"
#endif

#include "global.h"

int asm_writer_write_global(
	struct asm_writer* this,
	const char* identifier,
	bool is_static,
	struct initializer* value,
	struct type* type)
{
	int error = 0;
	ENTER;
	
	int on_zero(size_t size)
	{
		int error = 0;
		ENTER;
		
		asm_writer_write(this, ".zero %lu", size);
		
		EXIT;
		return error;
	}
	
	int on_integer(struct integer_type* spef, struct expression** e)
	{
		int error = 0;
		ENTER;
		
		if ((*e)->kind != ek_literal)
		{
			TODO;
			error = 1;
		}
		
		struct literal_expression* literal;
		
		if (!error)
		{
			literal = (typeof(literal)) (*e);
			
			switch (spef->kind)
			{
				case ik_signed_int:
				{
					error = asm_writer_write(this,
						".long %i", literal->value._signed_char);
					break;
				}
				
				default:
					TODO;
					break;
			}
		}
		
		EXIT;
		return error;
	}
	
	int on_float(struct float_type* spef, struct expression** e)
	{
		int error = 0;
		ENTER;
			
		if ((*e)->kind != ek_literal)
		{
			TODO;
			error = 1;
		}
		
		struct literal_expression* literal;
		
		if (!error)
		{
			literal = (typeof(literal)) *e;
			
			switch (spef->kind)
			{
				case fk_float:
				{
					uint32_t value;
					value = *((uint32_t*) &literal->value._float);
					dpv(value);
					error = asm_writer_write(this, ".long %u", value);
					break;
				}
				
				default:
					TODO;
					break;
			}
		}
		
		EXIT;
		return error;
	}
	
	int on_struct(struct struct_type* st, struct expression** e)
	{
		int error = 0;
		ENTER;
		TODO;
		EXIT;
		return error;
	}
	
	int ef(struct type* ft, const char* n)
	{
		int error = 0;
		ENTER;
		
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_indent2(this, ".%s", n);
		#endif
		
		EXIT;
		return error;
	}
	
	int xf(struct type* ft)
	{
		int error = 0;
		ENTER;
		
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_unindent(this);
		#endif
		
		EXIT;
		return error;
	}
	
	int ei(unsigned long index)
	{
		int error = 0;
		ENTER;
		
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_indent2(this, ".%lu", index);
		#endif
		
		EXIT;
		return error;
	}
	
	int xi(unsigned long index)
	{
		int error = 0;
		ENTER;
		
		#ifdef VERBOSE_ASSEMBLY
		asm_writer_unindent(this);
		#endif
		
		EXIT;
		return error;
	}

	
	dpvs(identifier);
	dpv(type->size);
	
	#ifdef VERBOSE_ASSEMBLY
	error = asm_writer_comment(this, "global %T:", identifier, type);
	#endif
	
	if (!error && is_static)
		error = asm_writer_write(this, ".local %s", identifier);
	
	if (!error)
	{
		if (value)
		{
			// following form to GCC:
			error = 0
				?: asm_writer_write(this, ".globl %s", identifier)
				?: asm_writer_write(this, ".align 32")
				?: asm_writer_write(this, ".type %s, @object", identifier)
				?: asm_writer_write(this, ".size %s, %lu", identifier, type->size)
				?: asm_writer_write(this, "%s:", identifier)
				?: initializer_traverse(value, type,
					on_zero, on_integer, on_float, on_struct,
					ef, xf, ei, xi);
		}
		else
		{
			error = asm_writer_write(this, ".comm %s, %lu", identifier, type->size);
		}
	}
	
	
	EXIT;
	return error;
}

















