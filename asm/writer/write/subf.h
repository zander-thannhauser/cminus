
#include <type/float/kind.h>

#include "../../enums/floatregs.h"

struct asm_writer;
struct asm_location;

int asm_writer_write_subf(
	struct asm_writer* this,
	enum float_register_id a,
	enum float_register_id b,
	enum float_register_id q,
	enum float_kind result_kind);
