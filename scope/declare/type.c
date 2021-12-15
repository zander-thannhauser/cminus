
#include <errno.h>

#include <debug.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

#include <avl/avl.h>

#include "../struct.h"
#include "../namedtype.h"
#include "../free/type.h"

#include "type.h"

int scope_declare_type(
	struct scope* this,
	char* identifier,
	struct type* type)
{
	int error = 0;
	struct namedtype* namedtype = NULL;
	ENTER;
	
	if (!error)
		error = tmalloc((void**) &namedtype, sizeof(*namedtype), free_namedtype);
	
	if (!error)
	{
		namedtype->name = tinc(identifier);
		namedtype->type = tinc(type);
		
		if (avl_insert(this->stackhead
			? this->stackhead->local.types
			: this->global.types, namedtype))
		{
			tinc(namedtype);
		}
		else if (errno == EEXIST)
		{
			TODO;
			error = 1;
		}
		else
		{
			TODO;
			error = 1;
		}
	}
	
	tfree(namedtype);
	
	EXIT;
	return error;
}










