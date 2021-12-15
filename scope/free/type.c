
#include <debug.h>

#include <memory/tfree.h>

#include "../namedtype.h"

#include "type.h"

void free_namedtype(void* ptr)
{
	struct namedtype* nt = ptr;
	ENTER;
	
	dpv(ptr);
	
	tfree(nt->name);
	tfree(nt->type);
	
	EXIT;
}

