
#include <debug.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_pointer(struct pointer* this)
{
	ENTER;
	tfree(this->qualifiers);
	tfree(this->inner);
	EXIT;
}

