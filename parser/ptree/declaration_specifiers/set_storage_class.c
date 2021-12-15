
#include <stdio.h>

#include <debug.h>
#include <enums/error.h>

#include <defines/argv0.h>

#include "struct.h"
#include "set_storage_class.h"

int declaration_specifiers_set_storage_class(
	struct declaration_specifiers* this,
	enum storage_class storage_class)
{
	int error = 0;
	ENTER;
	
	if (this->storage_class != sc_default)
		fprintf(stderr, "%s: two or more storage class specifiers specified!\n", argv0),
		error = e_bad_input_file;
	
	if (!error)
		this->storage_class = storage_class;
	
	EXIT;
	return error;
}

