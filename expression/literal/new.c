
#include <debug.h>

/*#include <type/primitive/struct.h>*/

#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_literal_expression_as__Bool(
	struct expression** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct type* bool_type,
	bool boollit)
{
	int error = 0;
	ENTER;
	
	dpvb(boollit);
	
	TODO;
	#if 0
	struct literal_expression* this = NULL;
	
	error = new_expression(
		/* return value: */ (struct expression**) &this,
		/* expression kind: */ ek_literal,
		/* inheritance*/ &literal_expression_inheritance,
		/* type: */ bool_type,
		/* alloc_size: */ sizeof(*this));
	
	if (!error)
	{
		this->kind = pk_bool,
		this->value._bool = boollit;
		
		*new = (struct expression*) this;
	}
	#endif
	
	EXIT;
	return error;
}

int new_literal_expression_as_signed_char(
	struct expression** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct type* sint_type,
	signed char scharlit)
{
	int error = 0;
	ENTER;
	
	dpv(scharlit);
	
	TODO;
	#if 0
	struct literal_expression* this = NULL;
	
	error = new_expression(
		/* return value: */ (struct expression**) &this,
		/* expression kind: */ ek_literal,
		/* inheritance*/ &literal_expression_inheritance,
		/* type: */ sint_type,
		/* alloc_size: */ sizeof(*this));
	
	if (!error)
	{
		this->kind = pk_signed_char,
		this->value._signed_char = scharlit;
		
		*new = (struct expression*) this;
	}
	#endif
	
	EXIT;
	return error;
}

int new_literal_expression_as_unsigned_char(
	struct expression** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct type* double_type,
	unsigned char floatlit)
{
	TODO;
}

int new_literal_expression_as_signed_short(
	struct expression** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct type* double_type,
	signed short floatlit)
{
	TODO;
}

int new_literal_expression_as_unsigned_short(
	struct expression** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct type* double_type,
	unsigned short floatlit)
{
	TODO;
}

int new_literal_expression_as_signed_int(
	struct expression** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct type* sint_type,
	signed int sintlit)
{
	int error = 0;
	ENTER;
	
	dpv(sintlit);
	
	struct literal_expression* this = NULL;
	
	error = new_expression(
		/* return value: */ (struct expression**) &this,
		/* expression kind: */ ek_literal,
		/* inheritance*/ &literal_expression_inheritance,
		/* first: */ first_line, first_column,
		/* last:  */ last_line, last_column,
		/* type: */ sint_type,
		/* alloc_size: */ sizeof(*this));
	
	if (!error)
	{
		this->value._signed_int = sintlit;
		
		*new = (struct expression*) this;
	}
	
	EXIT;
	return error;
}

int new_literal_expression_as_unsigned_int(
	struct expression** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct type* double_type,
	unsigned int floatlit)
{
	TODO;
}

int new_literal_expression_as_signed_long(
	struct expression** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct type* double_type,
	signed long floatlit)
{
	TODO;
}

int new_literal_expression_as_unsigned_long(
	struct expression** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct type* ulong_type,
	unsigned long ulong_value)
{
	int error = 0;
	ENTER;
	
	dpv(ulong_value);
	
	TODO;
	#if 0
	struct literal_expression* this = NULL;
	
	error = new_expression(
		/* return value: */ (struct expression**) &this,
		/* expression kind: */ ek_literal,
		/* inheritance*/ &literal_expression_inheritance,
		/* type: */ ulong_type,
		/* alloc_size: */ sizeof(*this));
	
	if (!error)
	{
		this->kind = pk_unsigned_long,
		this->value._unsigned_long = ulong_value;
		
		*new = (struct expression*) this;
	}
	#endif
	
	EXIT;
	return error;
}

int new_literal_expression_as_float(
	struct expression** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct type* float_type,
	float floatlit)
{
	int error = 0;
	ENTER;
	
	TODO;
	#if 0
	struct literal_expression* this = NULL;
	
	error = new_expression(
		(struct expression**) &this,
		ek_literal,
		&literal_expression_inheritance,
		line, column,
		float_type,
		sizeof(*this));
	
	if (!error)
	{
		this->is_integer_result = false;
		this->value._float = floatlit;
		
		*new = (struct expression*) this;
	}
	#endif
	
	EXIT;
	return error;
}


int new_literal_expression_as_double(
	struct expression** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct type* double_type,
	double doublelit)
{
	int error = 0;
	ENTER;
	
	struct literal_expression* this = NULL;
	
	error = new_expression(
		(struct expression**) &this,
		ek_literal,
		&literal_expression_inheritance,
		first_line, first_column,
		last_line, last_column,
		double_type,
		sizeof(*this));
	
	if (!error)
	{
		dpv(doublelit);
		
		this->value._double = doublelit;
		
		*new = (struct expression*) this;
	}
	
	EXIT;
	return error;
}











