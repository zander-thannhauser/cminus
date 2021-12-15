
#include <debug.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_types(struct types* this)
{
	int i;
	ENTER;
	
	for (i = 0; i < number_of_integer_kinds; i++)
		tfree(this->integers[i]);
		
	for (i = 0; i < number_of_float_kinds; i++)
		tfree(this->floats[i]);
		
	tfree(this->void_type);
	tfree(this->charptr_type);
	
	EXIT;
}

