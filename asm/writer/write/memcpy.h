
#if 0
#include <asm/enums/intregs.h>

struct asm_writer;

int asm_writer_write_memcpy(
	struct asm_writer* this,
	enum integer_register_id dst,
	enum integer_register_id src,
	uint64_t n);
#endif
