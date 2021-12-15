
#include <type/float/kind.h>

struct asm_writer;
struct asm_location;

int asm_writer_write_movf(
	struct asm_writer* this,
	struct asm_location* src_loc, enum float_kind src_kind,
	struct asm_location* dst_loc, enum float_kind dst_kind);
