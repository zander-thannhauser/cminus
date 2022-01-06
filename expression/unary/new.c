
#include <debug.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

/*#include <type/pointer/struct.h>*/
#include <type/pointer/new.h>

/*#include <types/struct.h>*/

#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_unary_expression(
	struct expression** new,
	enum unary_expression_kind kind,
	struct expression* inner,
	struct types* types)
{
	int error = 0;
	struct type* type = NULL;
	ENTER;
	
	TODO;
	#if 0
	switch (kind)
	{
		case uek_address_of:
		{
			error = new_pointer_type(
				(struct pointer_type**) &type,
				/* qualifiers:  */ NULL,
				/* dereference: */ inner->type);
			break;
		}
		
		
		default:
			dpv(kind);
			TODO;
			break;
	}
	
	struct unary_expression* this = NULL;
	
	if (!error)
		error = new_expression(
			(struct expression**) &this,
			ek_unary, &unary_expression_inheritance,
			type, sizeof(*this));
	
	if (!error)
	{
		this->kind = kind;
		this->inner = tinc(inner);
		
		*new = (struct expression*) this;
	}
	#endif
	
	tfree(type);
	
	EXIT;
	return error;
}

#if 0

			case uek_dereference:
			{
				if (inner->type->kind != tk_pointer)
				{
					TODO;
					error = 1;
				}
				else
				{
					struct pointer_type* const spef = (typeof(spef)) inner->type;
					
					if (spef->dereference->kind == tk_array)
					{
						struct array_type* const spef2 = (typeof(spef2)) spef->dereference;
						
						TODO;
					}
					else if (spef->dereference->kind == tk_struct)
					{
						TODO;
					}
					else
					{
						type = tinc(spef->dereference);
					}
				}
				
				break;
			}


			case uek_logical_negate:
			{
				if (inner->type->kind != tk_primitive)
				{
					TODO;
					error = 1;
				}
				else
					type = tinc(types->primitives[pk_bool]);
				TODO; // cast to bool
				break;
			}
#endif










