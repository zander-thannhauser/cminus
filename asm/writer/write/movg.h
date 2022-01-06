
#if 0
#include <asm/enums/register_size.h>
#include <asm/enums/intregs.h>

struct asm_writer;

int asm_writer_write_movg(
	struct asm_writer* this,
	const char* name,
	ssize_t dst_offset, enum integer_register_id dst_rel,
	enum register_size rsize);
#endif
