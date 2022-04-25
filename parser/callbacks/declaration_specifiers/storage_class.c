
#include <assert.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <parser/ptree/declaration_specifiers/new.h>
#include <parser/ptree/declaration_specifiers/set_storage_class.h>

#include "storage_class.h"

int declaration_specifiers_storage_class_callback(
	struct declaration_specifiers** retval,
	enum storage_class storage_class,
	struct declaration_specifiers* specifiers)
{
	int error = 0;
	ENTER;
	
	if (!specifiers)
		error = new_declaration_specifiers(&specifiers);
	
	if (!error)
		error = declaration_specifiers_set_storage_class(
			specifiers, storage_class);
	
	if (!error)
		*retval = tinc(specifiers);
	
	tfree(specifiers);
	
	EXIT;
	return error;
}

