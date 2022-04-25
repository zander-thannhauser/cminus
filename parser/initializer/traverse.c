
#include <assert.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <type/struct.h>
#include <type/struct/field_ll/struct.h>
#include <type/struct/field/struct.h>
#include <type/struct/struct.h>
#include <type/array/struct.h>

#include "../initializer_ll/struct.h"

#include "struct.h"
#include "traverse.h"

int initializer_traverse(
	struct initializer* this,
	struct type* type,
	int (*on_zero)(size_t),
	int (*on_integer)(struct integer_type*, struct expression**),
	int (*on_float)(struct float_type*, struct expression**),
	int (*on_pointer)(struct pointer_type*, struct expression**),
	int (*on_struct)(struct struct_type*, struct expression**),
	int (*ef)(struct type*, const char*),
	int (*xf)(struct type* t),
	int (*ei)(unsigned long),
	int (*xi)(unsigned long))
{
	int error = 0;
	ENTER;
	
	dpv(this);
	
	if (!this) {
		error = on_zero(type->size);
	}
	else switch (type->kind)
	{
		case tk_integer:
		{
			struct integer_type* spef = (typeof(spef)) type;
			
			if (this->kind != ik_expression)
			{
				TODO;
				error = 1;
			}
			
			struct expression* before = NULL, *after = NULL;
			
			if (!error)
			{
				after = before = this->expression;
				error = on_integer(spef, &after);
			}
			
			if (!error && before != after)
			{
				this->expression = tinc(after);
				tfree(before);
			}
			
			break;
		}
		
		case tk_float:
		{
			struct float_type* spef = (typeof(spef)) type;
			
			if (this->kind != ik_expression)
			{
				TODO;
				error = 1;
			}
			
			struct expression* before = NULL, *after = NULL;
			
			if (!error)
			{
				after = before = this->expression;
				error = on_float(spef, &after);
			}
			
			if (!error && before != after)
			{
				this->expression = tinc(after);
				tfree(before);
			}
			
			break;
		}
		
		case tk_pointer:
		{
			struct pointer_type* spef = (typeof(spef)) type;
			
			if (this->kind != ik_expression)
			{
				TODO;
				error = 1;
			}
			
			struct expression* before = NULL, *after = NULL;
			
			if (!error)
			{
				after = before = this->expression;
				error = on_pointer(spef, &after);
			}
			
			if (!error && before != after)
			{
				this->expression = tinc(after);
				tfree(before);
			}
			
			break;
		}
		
		case tk_array:
		{
			struct array_type* spef = (typeof(spef)) type;
			
			if (this->kind != ik_initializer_list)
			{
				TODO;
				error = 1;
			}
			
			struct initializer_ll* initializer_ll;
			struct initializer_ll_link* ill;
			struct type* element;
			size_t i, n;
			if (!error)
			{
				initializer_ll = this->initializer_ll;
				ill = initializer_ll->head;
				element = spef->element_type;
				i = 0, n = spef->number_of_elements;
			}
			
			for (; !error && i < n; i++)
			{
				error = 0
					?: ei(i)
					?: initializer_traverse(ill ? ill->element : NULL, element,
						on_zero, on_integer, on_float, on_pointer, on_struct,
						ef, xf, ei, xi)
					?: xi(i);
				
				if (ill)
					ill = ill->next;
			}
			
			break;
		}
		
		case tk_struct:
		{
			struct struct_type* spef = (typeof(spef)) type;
			
			if (this->kind != ik_initializer_list)
			{
				TODO; // then call on_struct()
				error = 1;
			}
			
			struct initializer_ll* initializer_ll;
			struct initializer_ll_link* ill;
			struct struct_field_ll* sfll;
			struct struct_field_ll_link* sflll;
			if (!error)
			{
				initializer_ll = this->initializer_ll;
				ill = initializer_ll->head;
				sfll = spef->fields;
				sflll = sfll->head;
			}
			
			for (; !error && sflll; sflll = sflll->next)
			{
				struct struct_field* const sf = sflll->element;
				
				error = 0
					?: ef(sf->type, sf->name)
					?: initializer_traverse(ill ? ill->element : NULL, sf->type,
						on_zero, on_integer, on_float, on_pointer, on_struct,
						ef, xf, ei, xi)
					?: xf(sf->type);
				
				if (ill)
					ill = ill->next;
			}
			
			break;
		}
		
		default:
			TODO;
			break;
	}
	
	EXIT;
	return error;
}


















