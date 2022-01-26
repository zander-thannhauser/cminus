
#if 0

#include <sys/types.h>

#include <type/float/kind.h>

#include <asm/enums/intregs.h>
#include <asm/enums/floatregs.h>

struct asm_writer;

void asm_writer_write_chfloat(
	struct asm_writer* this,
	ssize_t src_off, enum integer_register_id src_relto, enum float_kind src_kind,
	enum float_register_id dst_rid, enum float_kind dst_kind);
#endif
