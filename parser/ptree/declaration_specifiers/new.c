
#include <assert.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

#include <parser/ptree/type_qualifiers/new.h>

#include "free.h"
#include "struct.h"
#include "new.h"

int new_declaration_specifiers(
	struct declaration_specifiers** new)
{
	int error = 0;
	struct type_qualifiers* qualifiers = NULL;
	struct declaration_specifiers* this = NULL;
	ENTER;
	
	error = 0
		?: new_type_qualifiers(&qualifiers)
		?: tmalloc(
			(void**) &this, sizeof(*this),
			(void (*)(void*)) free_declaration_specifiers);
	
	if (!error)
	{
		this->storage_class = sc_default;
		
		this->type = NULL;
		
		this->qualifiers = tinc(qualifiers);
		
		*new = this;
	}
	
	tfree(qualifiers);
	
	EXIT;
	return error;
}












