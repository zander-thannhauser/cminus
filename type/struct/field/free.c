
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_struct_field(struct struct_field* this)
{
	tfree(this->name);
	tfree(this->type);
}

