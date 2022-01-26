
#if 0
#include <sys/types.h>

#include "../../enums/register_size.h"
#include "../../enums/intregs.h"

struct asm_writer;

int asm_writer_write_mov(
	struct asm_writer* this,
	ssize_t src_offset, enum integer_register_id src_rel,
	ssize_t dst_offset, enum integer_register_id dst_rel,
	enum register_size rsize);

#endif
