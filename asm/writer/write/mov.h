
/*#include <stdbool.h>*/

/*#include <asm/enums/registers.h>*/
/*#include <asm/enums/register_size.h>*/

#include <type/integer/kind.h>

struct asm_writer;
struct asm_location;

int asm_writer_write_mov(
	struct asm_writer* this,
	struct asm_location* src_loc, enum integer_kind src_kind,
	struct asm_location* dst_loc, enum integer_kind dst_kind);
