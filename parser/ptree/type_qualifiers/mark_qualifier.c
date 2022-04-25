
#include <assert.h>

#include "struct.h"
#include "mark_qualifier.h"

void type_qualifiers_mark_qualifier(
	struct type_qualifiers* this,
	enum type_qualifier q)
{
	ENTER;
	
	assert(0 <= q && q < number_of_type_qualifiers);
	
	dpv(q);
	
	this->qualifiers[q] = true;
	
	EXIT;
}

