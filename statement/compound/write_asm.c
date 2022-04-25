
#include <assert.h>

#include <parser/statement_ll/struct.h>

#include <statement/write_asm.h>

#include "struct.h"
#include "write_asm.h"

int compound_statement_write_asm(
	struct compound_statement* this, struct asm_writer* writer)
{
	int error = 0;
	struct statement_link* slink;
	ENTER;
	
	for (slink = this->statements->head; !error && slink; slink = slink->next)
	{
		struct statement* const statement = slink->element;
		
		error = statement_write_asm(statement, writer);
	}
	
	EXIT;
	return error;
}

int inheritance_compound_statement_write_asm(
	struct statement* super, struct asm_writer* writer)
{
	int error = 0;
	struct compound_statement* const this = (typeof(this)) super;
	ENTER;
	
	error = compound_statement_write_asm(this, writer);
	
	EXIT;
	return error;
}








