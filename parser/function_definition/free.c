
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_function_definition(
	struct function_definition* this)
{
	ENTER;
	tfree(this->name);
	tfree(this->parameters);
	tfree(this->ftype);
	tfree(this->body);
	EXIT;
}

