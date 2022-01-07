
#include <debug.h>

#include <memory/tfree.h>

#include <type/struct.h>
#include <type/pointer/struct.h>
#include <type/pointer/new.h>

#include <expression/struct.h>
#include <expression/inheritance.h>
#include <expression/addressof/new.h>
#include <expression/dereference/new.h>

#include <parser/yylloc/new.h>

#include "operator.h"

int unary_expression_operator(
	struct expression** out,
	enum unary_expression_kind kind,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* inner)
{
	int error = 0;
	struct yylloc* loc = NULL;
	ENTER;
	
	error = new_yyloc(&loc, first_line, first_column, last_line, last_column);
	
	if (!error)
	{
		switch (kind)
		{
			case uek_dereference:
			{
				struct type* type = NULL;
				
				if (!inner->inheritance->write_rasm)
				{
					TODO;
					error = 1;
				}
				else switch (inner->type->kind)
				{
					case tk_pointer:
					{
						struct pointer_type* spef = (typeof(spef)) inner->type;
						type = tinc(spef->dereference);
						break;
					}
					
					case tk_struct:
						TODO;
						break;
					
					default:
						TODO;
						break;
				}
				
				if (!error)
				{
					error = new_dereference_expression(out, loc, inner, type);
				}
				
				tfree(type);
				break;
			}
			
			case uek_addressof:
			{
				struct pointer_type* ptype = NULL;
				
				if (!inner->inheritance->write_lasm)
				{
					TODO;
					error = 1;
				}
				
				if (!error)
				{
					error = 0
						?: new_pointer_type(&ptype, NULL, inner->type)
						?: new_addressof_expression(out, loc, inner, (struct type*) ptype);
				}
				
				tfree(ptype);
				break;
			}
			
			default:
				TODO;
				break;
		}
	}
	
	tfree(inner);
	tfree(loc);
	
	EXIT;
	return error;
}
















