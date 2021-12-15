
#include <stdlib.h>
#include <inttypes.h>

struct asm_writer;

int asm_writer_write_string(
	struct asm_writer* this,
	size_t string_id,
	char* data,
	size_t len);
