
#include <assert.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

/*#include <type/primitive/kind.h>*/
/*#include <type/primitive/integer_kind.h>*/

#include <type/integer/new.h>
#include <type/float/new.h>

#include <type/pointer/new.h>
#include <type/void/new.h>

#include <type/free.h>

#include "struct.h"
#include "new.h"
#include "free.h"

int new_types(struct types** new)
{
	int error = 0;
	int i;
	struct type* integers[number_of_integer_kinds] = {};
	struct type* floats[number_of_float_kinds] = {};
	struct type* void_type = NULL;
	struct type* charptr_type = NULL;
	ENTER;
	
	for (i = 0; !error && i < number_of_integer_kinds; i++)
		error = new_integer_type((struct integer_type**) &integers[i], i);
	
	for (i = 0; !error && i < number_of_float_kinds; i++)
		error = new_float_type((struct float_type**) &floats[i], i);
	
	if (!error)
		error = 0
			?: new_void_type((struct void_type**) &void_type)
			?: new_pointer_type(
				(struct pointer_type**) &charptr_type, NULL,
				integers[ik_signed_char]);
	
	struct types* this = NULL;
	
	if (!error)
		error = tmalloc(
			(void**) &this, sizeof(*this),
			(void (*)(void*)) free_types);
	
	if (!error)
	{
		for (i = 0; i < number_of_integer_kinds; i++)
			this->integers[i] = tinc(integers[i]);
		
		for (i = 0; i < number_of_float_kinds; i++)
			this->floats[i] = tinc(floats[i]);
		
		this->void_type = tinc(void_type);
		this->charptr_type = tinc(charptr_type);
		
		*new = this;
	}
	
	for (i = 0; i < number_of_integer_kinds; i++)
		tfree(integers[i]);
	
	for (i = 0; i < number_of_float_kinds; i++)
		tfree(floats[i]);
	
	tfree(void_type);
	tfree(charptr_type);
	
	EXIT;
	return error;
}












