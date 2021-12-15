
#include <debug.h>

#include "struct.h"
#include "indent.h"

void asm_writer_indent(struct asm_writer* this)
{
	this->indent++;
}

