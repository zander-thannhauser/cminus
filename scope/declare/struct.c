
#include <errno.h>

#include <assert.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

#include <avl/avl.h>

#include <type/struct/struct.h>

#include "../struct.h"
#include "../namedtype.h"
#include "../free/type.h"

#include "struct.h"

int scope_declare_struct(
	struct scope* this,
	char* identifier,
	struct type* type)
{
	int error = 0;
	struct namedtype* namedtype = NULL;
	struct avl_tree_t* searchme;
	ENTER;
	
	dpvs(identifier);
	
	searchme = this->stackhead
		? this->stackhead->local.structs
		: this->global.structs;
	
	if (!error)
		error = tmalloc((void**) &namedtype, sizeof(*namedtype), free_namedtype);
	
	if (!error)
	{
		namedtype->name = tinc(identifier);
		namedtype->type = tinc(type);
		
		if (avl_insert(searchme, namedtype))
		{
			tinc(namedtype);
		}
		else if (errno != EEXIST)
		{
			TODO;
			error = 1;
		}
		else
		{
			struct avl_node_t* old;
			struct namedtype* oldnamedtype;
			struct type* oldtype;
			
			assert((old = avl_search(searchme, namedtype)));
			
			if (type->is_complete)
			{
				if ((oldtype = (oldnamedtype = old->item)->type)->is_complete)
				{
					TODO; // "redeclaration!"
					error = 1;
				}
				else
				{
					assert(oldtype->kind == tk_struct);
					
					struct struct_type* old = (typeof(old)) oldtype;
					struct struct_type* new = (typeof(new)) type;
					
					// oldtype->fields = type->fields
					old->fields = tinc(new->fields);
					
					oldtype->is_complete = true;
				}
			}
		}
	}
	
	tfree(namedtype);
	
	EXIT;
	return error;
}













