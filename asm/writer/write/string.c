
#include <debug.h>

#include "../struct.h"

#include "string.h"

int asm_writer_write_string(
	struct asm_writer* this,
	size_t string_id,
	char* data, size_t len)
{
	int error = 0;
	unsigned i, n;
	ENTER;
	
	
	#ifdef VERBOSE_ASSEMBLY
	assert(!this->indent_head);
	#endif
	
	fprintf(this->stream, ".string_%lu: .ascii \"", string_id);
	
	for (i = 0; i < len; i++)
		fprintf(this->stream, "\\x%02hhX", data[i]);
	
	fprintf(this->stream, "\"\n");
	
	EXIT;
	return error;
}
