
#include <stdio.h>

#include <debug.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <scope/variable.h>

#include <type/struct.h>
#include <type/array/struct.h>
#include <type/pointer/new.h>

#include "../kind.h"
#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_variable_expression(
	struct variable_expression** new,
	struct variable* variable)
{
	int error = 0;
	bool is_array = false;
	struct type* type = NULL;
	struct variable_expression* this = NULL;
	ENTER;
	
	if (variable->type->kind == tk_array)
	{
		struct array_type* spef = (typeof(spef)) variable->type;
		is_array = true;
		error = new_pointer_type((struct pointer_type**) &type,
			(bool[number_of_type_qualifiers]) {
				[tq_constant] = true,
			}, spef->element_type);
	}
	else
	{
		type = tinc(variable->type);
	}
	
	if (!error)
		error = new_expression(
			(struct expression**) &this,
			/* kind: */ ek_variable,
			/* inheritance: */ &variable_expression_inheritance,
			/* type: */ type,
			sizeof(*this));
	
	if (!error)
	{
		this->is_array = is_array;
		this->variable = tinc(variable);
		
		*new = this;
	}
	
	tfree(type);
	
	EXIT;
	return error;
}










