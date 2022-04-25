
#include <assert.h>

#include "../write.h"

#include "label.h"

int asm_writer_write_label(
	struct asm_writer* this,
	const char* label)
{
	int error = 0;
	ENTER;
	
	asm_writer_write(this, ".%s:", label);
	
	EXIT;
	return error;
}
