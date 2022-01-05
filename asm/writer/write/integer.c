
#include <debug.h>

#include "../../tables/intregs.h"

#include "../write.h"

#include "integer.h"

void asm_writer_write_integer(
	struct asm_writer* this,
	uintmax_t literal,
	enum integer_register_id where,
	enum register_size rsize)
{
	ENTER;
	
	asm_writer_write(this,
		"mov $%ju, %s",
		literal,
		intregs[where][rsize]);
	
	EXIT
}

