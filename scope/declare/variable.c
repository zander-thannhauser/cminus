
#include <stdio.h>
#include <errno.h>

#include <debug.h>
#include <enums/error.h>

#include <defines/argv0.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

#include <avl/avl.h>

#include <type/struct.h>
#include <type/compare.h>

#include "../struct.h"
#include "../variable.h"
#include "../free/variable.h"

#include "variable.h"

int scope_declare_variable(
	struct scope* this,
	char* identifier,
	struct type* type,
	enum storage_class storage_class,
	struct variable** outgoing)
{
	int error = 0;
	struct variable* variable = NULL;
	ENTER;
	
	// shortcut:
	struct avl_tree_t* searchme = this->stackhead ? this->stackhead->local.variables : this->global.variables;
	
	if (!error)
		error = tmalloc((void**) &variable, sizeof(*variable), free_variable);
	
	if (!error)
	{
		variable->name = tinc(identifier);
		variable->type = tinc(type);
		variable->storage_class = storage_class;
		
		variable->is_global = !this->stackhead || storage_class == sc_static;
		
		if (!variable->is_global)
		{
			if ((variable->offset = this->stackhead->offset += type->size) > this->frame_size)
				this->frame_size = variable->offset;
			
			dpv(variable->offset);
		}
		
		dpvs(variable->name);
		dpvb(variable->is_global);
		
		if (avl_insert(searchme, variable))
		{
			if (outgoing)
				*outgoing = tinc(variable);
			
			tinc(variable);
		}
		else if (errno == EEXIST)
		{
			struct avl_node_t* node;
			struct variable* oldvar;
			
			// global variables *can* be redeclared, as long
			// as they're the same type and storage class:
			
			node = avl_search(searchme, variable);
			assert(node);
			oldvar = node->item;
			
			if (false
				|| this->stackhead
				|| compare_types(type, oldvar->type)
				|| storage_class != oldvar->storage_class)
			{
				fprintf(stderr, "%s: variable '%s' redeclared in same scope "
					"with as different type!\n", argv0, identifier);
				error = e_bad_input_file;
			}
			
			if (!error && outgoing)
				*outgoing = tinc(oldvar);
		}
		else
		{
			TODO;
			error = 1;
		}
	}
	
	tfree(variable);
	
	EXIT;
	return error;
}











