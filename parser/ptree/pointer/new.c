
#include <assert.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

#include "struct.h"
#include "free.h"
#include "new.h"

int new_pointer(
	struct pointer** new,
	struct type_qualifiers* qualifiers,
	struct pointer* inner)
{
	int error = 0;
	ENTER;
	
	struct pointer* this = NULL;
	
	error = tmalloc(
		(void**) &this, sizeof(*this),
		(void (*)(void*)) free_pointer);
	
	if (!error)
	{
		this->qualifiers = tinc(qualifiers);
		this->inner = tinc(inner);
		
		*new = this;
	}
	
	EXIT;
	return error;
}











