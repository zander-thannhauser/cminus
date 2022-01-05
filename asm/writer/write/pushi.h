
#include <inttypes.h>

struct asm_writer;

void asm_writer_write_pushi(
	struct asm_writer* this,
	uintmax_t val);
