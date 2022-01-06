
#include <asm/enums/register_size.h>
#include <asm/enums/intregs.h>

struct asm_writer;

void asm_writer_write_on_zjmp(
	struct asm_writer* this,
	enum integer_register_id rid, enum register_size rs,
	const char* label);
