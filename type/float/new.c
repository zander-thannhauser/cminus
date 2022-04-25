
#include <assert.h>

#include "../kind.h"
#include "../new.h"

#include "kind.h"
#include "struct.h"
#include "inheritance.h"
#include "new.h"

static size_t lookup[] =
{
	[fk_double] = sizeof(double),
	[fk_float] = sizeof(float),
};

int new_float_type(
	struct float_type** new,
	enum float_kind kind)
{
	int error = 0;
	ENTER;
	
	dpv(kind);
	
	struct float_type* this = NULL;
	
	assert(lookup[kind]);
	
	error = new_type(
		(struct type**) &this,
		/* kind: */ tk_float,
		/* inheritance: */ &float_type_inheritance,
		/* is_complete: */ true,
		/* size: */ lookup[kind],
		sizeof(*this));
	
	if (!error)
	{
		this->kind = kind;
		
		*new = this;
	}
	
	EXIT;
	return error;
}


















