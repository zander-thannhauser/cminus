
/*#include <type/integer/kind.h>*/

#include "../../enums/intregs.h"

struct asm_writer;
struct asm_location;

int asm_writer_write_add(
	struct asm_writer* this,
	struct asm_location* src_loc,
	struct asm_location* dst_loc,
	enum integer_kind result_kind);
