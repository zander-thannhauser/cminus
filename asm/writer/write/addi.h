
#if 0
#include <inttypes.h>

#include "../../enums/intregs.h"
#include "../../enums/register_size.h"

struct asm_writer;
struct asm_location;

int asm_writer_write_addi_const(
	struct asm_writer* this,
	uintmax_t val,
	enum integer_register_id id,
	enum register_size rsize);

int asm_writer_write_addi(
	struct asm_writer* this,
	enum integer_register_id src,
	enum integer_register_id dst,
	enum register_size rs);

#endif
