
#ifdef VERBOSE_ASSEMBLY

#include <assert.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include "struct.h"
#include "unindent.h"

void asm_writer_unindent(struct asm_writer* this)
{
	ENTER;
	
	assert(this->indent_tail);
	
	struct indent_link* ilink = this->indent_tail;
	
	if (ilink->prev)
	{
		tfree(ilink->prev->next);
		ilink->prev->next = NULL;
	}
	else
	{
		tfree(this->indent_head);
		this->indent_head = NULL;
	}
	
	this->indent_tail = tinc(ilink->prev);
	tfree(ilink);
	
	EXIT;
}

#endif
