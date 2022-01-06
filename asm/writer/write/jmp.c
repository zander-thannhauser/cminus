
#include <debug.h>

#include "../write.h"

#include "jmp.h"

void asm_writer_write_jmp(
	struct asm_writer* this,
	const char* label)
{
	ENTER;
	
	asm_writer_write(this, "jmp .%s", label);
	
	EXIT;
}

