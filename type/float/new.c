
#include <debug.h>

#include "../kind.h"
#include "../new.h"

#include "kind.h"
#include "struct.h"
#include "inheritance.h"
#include "new.h"

#ifdef X64_TARGET
static size_t lookup[] =
{
	[fk_double] = sizeof(double),
	[fk_float] = sizeof(float),
};
#endif

int new_float_type(
	struct float_type** new
	#ifdef X64_TARGET
	, enum float_kind kind
	#endif
) {
	int error = 0;
	ENTER;
	
	struct float_type* this = NULL;
	
	#ifdef X64_TARGET
	assert(lookup[kind]);
	#endif
	
	error = new_type(
		(struct type**) &this,
		/* kind: */ tk_float,
		/* inheritance: */ &float_type_inheritance,
		/* is_complete: */ true,
		#ifdef X64_TARGET
		/* size: */ lookup[kind],
		#else
		/* size: */ 4,
		#endif
		sizeof(*this));
	
	if (!error)
	{
		#ifdef X64_TARGET
		this->kind = kind;
		#endif
		
		*new = this;
	}
	
	EXIT;
	return error;
}


















