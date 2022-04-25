
#include <string.h>

#include <assert.h>

#include <memory/tmalloc.h>

#include "struct.h"
#include "free.h"
#include "new.h"

int new_type_qualifiers(
	struct type_qualifiers** new)
{
	int error = 0;
	ENTER;
	
	struct type_qualifiers* this = NULL;
	
	error = tmalloc((void**) &this, sizeof(*this),
		(void (*)(void*)) free_type_qualifiers);
	
	if (!error)
	{
		memset(this->qualifiers, false, sizeof(this->qualifiers));
		
		*new = this;
	}
	
	EXIT;
	return error;
}

