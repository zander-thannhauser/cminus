
/*#include <stdlib.h>*/

/*#include <asm/enums/intregs.h>*/
/*#include <asm/enums/floatregs.h>*/
#include <asm/enums/register_size.h>

#include <type/integer/kind.h>

struct asm_writer;

void asm_writer_write_ftoi(
	struct asm_writer* this,
	ssize_t src_offset, enum integer_register_id src_relto, enum float_kind src_kind,
	enum integer_register_id dst, enum integer_kind dst_kind);
