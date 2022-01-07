
#include <stdio.h>

#include <debug.h>

#include <memory/tinc.h>

#include <avl/avl.h>

#include "../namedtype.h"
#include "../struct.h"

#include "struct.h"

struct type* scope_lookup_struct(
	struct scope* this,
	const char* name)
{
	struct type* retval = NULL;
	struct layer* i;
	struct avl_node_t* node;
	struct namedtype* namedtype;
	ENTER;
	
	for (i = this->stackhead; !retval && i; i = i->prev)
		if ((node = avl_search(i->local.structs, &name)))
		{
			namedtype = node->item;
			retval = tinc(namedtype->type);
		}
	
	if (!retval && (node = avl_search(this->global.structs, &name)))
	{
		namedtype = node->item;
		retval = tinc(namedtype->type);
	}
	
	dpv(retval);
	
	EXIT;
	return retval;
}

