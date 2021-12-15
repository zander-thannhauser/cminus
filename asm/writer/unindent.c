
#include <debug.h>

#include "struct.h"
#include "unindent.h"

void asm_writer_unindent(struct asm_writer* this)
{
	assert(this->indent);
	this->indent--;
}

