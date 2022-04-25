
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_specifier_qualifiers(
	struct specifier_qualifiers* this)
{
	ENTER;
	tfree(this->type);
	tfree(this->qualifiers);
	EXIT;
}

