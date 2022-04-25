
#include <assert.h>

#include "../struct.h"

#include "string.h"

int asm_writer_write_string(
	struct asm_writer* this,
	size_t string_id,
	char* data, size_t len)
{
	int error = 0;
	unsigned i;
	ENTER;
	
	#ifdef VERBOSE_ASSEMBLY
	assert(!this->indent_head);
	#endif
	
	fprintf(this->stream, ".global string_%lu\n", string_id);
	fprintf(this->stream, ".type   string_%lu, @object\n", string_id);
	fprintf(this->stream, ".size   string_%lu, %lu\n", string_id, len);
	
	fprintf(this->stream, "string_%lu: .string \"", string_id);
	
	for (i = 0; i < len; i++)
		fprintf(this->stream, "\\x%02hhX", data[i]);
	
	fprintf(this->stream, "\"\n");
	
	EXIT;
	return error;
}
