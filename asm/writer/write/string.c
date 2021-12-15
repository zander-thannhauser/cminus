
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
	
	for (i = 0, n = this->indent; !error && i < n; i++)
		fputc(' ', this->out);
	
	fprintf(this->out, ".string_%lu: .ascii \"", string_id);
	
	for (i = 0; i < len; i++)
		fprintf(this->out, "\\x%02hhX", data[i]);
	
	fprintf(this->out, "\"\n");
	
	EXIT;
	return error;
}
