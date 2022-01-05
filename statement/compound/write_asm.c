
#include <debug.h>

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
	
	if (error)
	{
		CHECK;
	}
	
	EXIT;
	return error;
}








