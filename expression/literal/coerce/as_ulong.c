
#include <debug.h>

#include "../struct.h"
#include "as_ulong.h"

int coerce_literal_as_ulong(
	unsigned long* retval,
	struct literal_expression* this)
{
	int error = 0;
	ENTER;
	
	TODO;
	#if 0
	switch (this->kind)
	{
		case pk_unsigned_long:
			*retval = this->value._unsigned_long;
			break;
		
		default:
			TODO;
			break;
	}
	#endif
	
	EXIT;
	return error;
}
