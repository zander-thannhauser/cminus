
#include <asm/enums/intregs.h>
#include <asm/enums/register_size.h>

struct asm_writer;

int asm_writer_write_push(
	struct asm_writer* this,
	enum integer_register_id rid);
