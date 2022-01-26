
#ifdef X64_TARGET

#include <stdlib.h>

#include <debug.h>

#include <asm/tables/iktors.h>
#include <asm/tables/fktors.h>

#include "integer/struct.h"
#include "float/struct.h"

#include "struct.h"
#include "get_rs.h"

enum register_size type_get_rs(struct type* const this)
{
	enum register_size retval;
	ENTER;
	
	assert(this->is_complete);
	
	switch (this->kind)
	{
		case tk_integer:
		{
			struct integer_type* spef = (typeof(spef)) this;
			retval = iktors[spef->kind];
			break;
		}
		
		case tk_float:
		{
			struct float_type* spef = (typeof(spef)) this;
			retval = fktors[spef->kind];
			break;
		}
		
		case tk_pointer:
		case tk_array:
		case tk_struct:
		{
			retval = quadword;
			break;
		}
		
		case tk_function:
		case tk_void:
			abort();
	}
	
	EXIT;
	return retval;
}



















#endif
