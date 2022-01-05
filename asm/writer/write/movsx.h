
#include <asm/enums/intregs.h>
#include <asm/enums/register_size.h>

struct asm_writer;

int asm_writer_write_movsx(
	struct asm_writer* this,
	enum integer_register_id src, enum register_size src_rs,
	enum integer_register_id dst, enum register_size dst_rs);
