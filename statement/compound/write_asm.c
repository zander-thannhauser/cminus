
#include <debug.h>

#include <asm/writer/indent.h>
#include <asm/writer/unindent.h>

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
	
	asm_writer_indent(writer);
	
	for (slink = this->statements->head; !error && slink; slink = slink->next)
	{
		struct statement* const statement = slink->element;
		
		error = statement_write_asm(statement, writer);
	}
	
	asm_writer_unindent(writer);
	
	EXIT;
	return error;
}








