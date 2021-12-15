
#include <type/float/kind.h>

#include "../../enums/floatregs.h"

struct asm_writer;
struct asm_location;

int asm_writer_write_addf(
	struct asm_writer* this,
	struct asm_location* src_loc,
	struct asm_location* dst_loc,
	enum float_kind result_kind);
