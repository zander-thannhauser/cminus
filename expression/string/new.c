
#include <debug.h>

#include <memory/tinc.h>

#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_string_expression(
	struct string_expression** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	size_t string_id,
	char* data, size_t strlen,
	struct type* charptr_type)
{
	int error = 0;
	ENTER;
	
	struct string_expression* this = NULL;
	
	error = new_expression(
		(struct expression**) &this,
		/* kind: */ ek_string,
		/* inheritance: */ &string_expression_inheritance,
		/* first: */ first_line, first_column,
		/* last:  */ last_line, last_column,
		/* type: */ charptr_type,
		sizeof(*this));
	
	if (!error)
	{
		this->string_id = string_id;
		
		this->data = tinc(data);
		this->strlen = strlen;
		
		*new = this;
	}
	
	EXIT;
	return error;
}

















