
#include <debug.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

/*#include <type/struct.h>*/
/*#include <type/struct/field/struct.h>*/
/*#include <type/struct/field_ll/struct.h>*/
/*#include <type/struct/struct.h>*/

#include <expression/cast/new.h>

#include <parser/initializer/traverse.h>
/*#include <parser/initializer/struct.h>*/
/*#include <parser/initializer_ll/struct.h>*/

#include "new.h"
#include "new_casted.h"

int new_casted_initializer_expression(
	struct expression** new,
	struct yylloc* loc,
	struct initializer* initializer,
	size_t stack_offset,
	struct type* type)
{
	int error = 0;
	ENTER;
	
	dpv(initializer);
	dpv(type);
	
	int on_zero(size_t size)
	{
		HERE;
		return 0;
	}
	
	int on_primitive(struct type* ft, struct expression** e)
	{
		int error = 0;
		struct expression* casted = NULL;
		ENTER;
		
		error = new_cast_expression(&casted, NULL, (void*) ft, *e);
		
		if (!error)
		{
			*e = tinc(casted);
		}
		
		tfree(casted);
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
	
	int enter_field(struct type* t, const char* n)
	{
		HERE;
		return 0;
	}
	
	int exit_field()
	{
		HERE;
		return 0;
	}
	
	int enter_index()
	{
		HERE;
		return 0;
	}
	
	int exit_index(unsigned long index)
	{
		HERE;
		return 0;
	}
	
	error = 0
		?: initializer_traverse(initializer, type,
			on_zero,
			(void*) on_primitive,
			(void*) on_primitive,
			(void*) on_primitive,
			on_struct,
			enter_field, exit_field,
			enter_index, exit_index)
		?: new_initializer_expression(new, loc, initializer, stack_offset, type);
	
	EXIT;
	return error;
}












