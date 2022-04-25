
#if 0
#include <assert.h>

#include "../struct.h"

#include "float.h"

int asm_writer_write_float(
	struct asm_writer* this,
	size_t section_id, float flo)
{
	int error = 0;
	unsigned i, n;
	ENTER;
	
	TODO;
	#if 0
	for (i = 0, n = this->indent; !error && i < n; i++)
		fputc(' ', this->out);
	
	fprintf(this->out, ".string_%lu: .ascii \"", string_id);
	
	for (i = 0; i < len; i++)
		fprintf(this->out, "\\x%02hhX", data[i]);
	
	fprintf(this->out, "\"\n");
	#endif
	
	EXIT;
	return error;
}
#endif
