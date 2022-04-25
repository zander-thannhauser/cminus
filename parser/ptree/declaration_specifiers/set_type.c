
#include <stdio.h>

#include <debug.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <types/struct.h>

#include <type/struct.h>
#include <types/combine.h>

#include "struct.h"
#include "set_type.h"

int declaration_specifiers_set_type(
	struct declaration_specifiers* this,
	struct type* type,
	struct types* types)
{
	int error = 0;
	ENTER;
	
	if (!this->type)
	{
		this->type = tinc(type);
	}
	else
	{
		TODO;
		#if 0
		struct type* combined = NULL;
		
		error = types_combine(&combined, types, this->type, type);
		
		if (!error)
		{
			tfree(this->type);
			
			this->type = tinc(combined);
		}
		
		tfree(combined);
		#endif
	}
	
	EXIT;
	return error;
}













