
#if 0
#include <type/integer/kind.h>
#include <type/float/kind.h>

#include <asm/tables/intregs.h>
#include <asm/tables/floatregs.h>

struct asm_writer;

void asm_writer_write_chint(
	struct asm_writer* this,
	size_t src_offset, enum integer_register_id src, enum integer_kind src_kind,
	enum integer_register_id dst, enum integer_kind dst_kind);
#endif
