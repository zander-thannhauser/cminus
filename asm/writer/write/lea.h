
/*#include <stdbool.h>*/

#include <asm/enums/intregs.h>
/*#include <asm/enums/register_size.h>*/

/*#include <type/integer/kind.h>*/

struct asm_writer;
struct asm_location;

int asm_writer_write_lea(
	struct asm_writer* this,
	struct asm_location* src_loc,
	enum integer_register_id rid);
