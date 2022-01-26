
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
	[ik_signed_char] = sizeof(char),
	[ik_signed_short] = sizeof(short),
	[ik_signed_int] = sizeof(int),
	[ik_signed_long] = sizeof(long),
	
	[ik_unsigned_char] = sizeof(char),
	[ik_unsigned_short] = sizeof(short),
	[ik_unsigned_int] = sizeof(int),
	[ik_unsigned_long] = sizeof(long),
};
#endif

int new_integer_type(
	struct integer_type** new,
	enum integer_kind kind)
{
	int error = 0;
	ENTER;
	
	dpv(kind);
	
	struct integer_type* this = NULL;
	
	#ifdef X64_TARGET
	assert(lookup[kind]);
	#endif
	
	error = new_type(
		(struct type**) &this,
		/* kind: */ tk_integer,
		/* inheritance: */ &integer_type_inheritance,
		/* is_complete: */ true,
		#ifdef X64_TARGET
		/* size: */ lookup[kind],
		#else
		/* size: */ 4,
		#endif
		sizeof(*this));
	
	if (!error)
	{
		this->kind = kind;
		
		*new = this;
	}
	
	EXIT;
	return error;
}


















