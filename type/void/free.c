
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_void_type(struct type* super)
{
	struct void_type* this = (typeof(this)) super;
	ENTER;
	
	HERE;
	
	EXIT;
}

