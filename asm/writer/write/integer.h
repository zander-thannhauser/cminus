
#if 0
#include <inttypes.h>

#include <asm/enums/intregs.h>
#include <asm/enums/register_size.h>

struct asm_writer;

void asm_writer_write_integer(
	struct asm_writer* this,
	uintmax_t literal,
	enum integer_register_id where,
	enum register_size rsize);

#endif
