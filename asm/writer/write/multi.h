
#if 0
#include <asm/enums/intregs.h>
#include <asm/enums/register_size.h>

#include <type/integer/kind.h>

struct asm_writer;

int asm_writer_write_multi_v2(
	struct asm_writer* this,
	enum integer_register_id a,
	enum integer_register_id b,
	enum integer_kind ikind);
#endif
