
#include <type/float/kind.h>

#include "../../enums/floatregs.h"

struct asm_writer;
struct asm_location;

int asm_writer_write_addf(
	struct asm_writer* this,
	enum float_register_id fid1,
	enum float_register_id fid2,
	enum float_kind result_kind);
