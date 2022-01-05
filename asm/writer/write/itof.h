
/*#include <stdlib.h>*/

#include <asm/enums/intregs.h>
#include <asm/enums/floatregs.h>

#include <type/float/kind.h>
#include <type/integer/kind.h>

struct asm_writer;

void asm_writer_write_itof(
	struct asm_writer* this,
	ssize_t src_offset, enum integer_register_id src_relto, enum integer_kind src_kind,
	enum float_register_id dest, enum float_kind dest_kind);
