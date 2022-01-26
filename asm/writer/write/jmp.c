
#if 0
#include <debug.h>

#include "../write.h"

#include "jmp.h"

int asm_writer_write_jmp(
	struct asm_writer* this,
	const char* label)
{
	int error = 0;
	ENTER;
	
	error = asm_writer_write(this, "jmp .%s", label);
	
	EXIT;
	return error;
}

#endif
