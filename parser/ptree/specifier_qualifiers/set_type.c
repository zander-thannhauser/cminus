
#include <stdio.h>

#include <debug.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <types/struct.h>

#include <type/struct.h>
#include <types/combine.h>

#include "struct.h"
#include "set_type.h"

int specifier_qualifiers_set_type(
	struct specifier_qualifiers* this,
	struct type* type,
	struct types* types)
{
	int error = 0;
	ENTER;
	
	dpv(type);
	
	if (!this->type)
		this->type = tinc(type);
	else
	{
		struct type* combined = NULL;
		
		error = types_combine(&combined, types, type, this->type);
		
		if (!error)
		{
			tfree(this->type);
			
			this->type = tinc(combined);
		}
		
		tfree(combined);
	}
	
	EXIT;
	return error;
}













