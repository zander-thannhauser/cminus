
#include <stdio.h>

#include <debug.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <asm/writer/write/string.h>

#include <types/struct.h>

#include <expression/string/new.h>

#include <parser/yylloc/new.h>

#include "string.h"

int primary_expression_string_callback(
	struct expression** out,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	char* string_data,
	size_t string_strlen,
	struct types* types,
	size_t* string_counter,
	struct asm_writer* writer)
{
	int error = 0;
/*	size_t i;*/
	struct yylloc* loc = NULL;
	ENTER;
	
	asm_writer_write_string(writer,
		*string_counter,
		string_data,
		string_strlen);
	
	error = 0
		?: new_yyloc(&loc,
			first_line, first_column,
			last_line, last_column)
		?: new_string_expression(
			(struct string_expression**) out,
			loc,
			(*string_counter)++,
			tinc(string_data), string_strlen,
			types->charptr_type);
	
	tfree(string_data);
	tfree(loc);
	
	EXIT;
	return error;
}











