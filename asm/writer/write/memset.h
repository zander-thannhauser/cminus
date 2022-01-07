
#include <asm/enums/intregs.h>

struct asm_writer;

int asm_writer_write_memset(
	struct asm_writer* write,
	ssize_t ptr_off, enum integer_register_id ptr_relto,
	uint8_t value,
	uint64_t n);
