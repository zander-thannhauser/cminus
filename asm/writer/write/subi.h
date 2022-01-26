
#if 0

/*#include <type/integer/kind.h>*/

#include <inttypes.h>

#include "../../enums/intregs.h"
#include "../../enums/register_size.h"

struct asm_writer;
struct asm_location;

int asm_writer_write_subi_const(
	struct asm_writer* this,
	uintmax_t val,
	enum integer_register_id id,
	enum register_size rsize);

int asm_writer_write_subi(
	struct asm_writer* this,
	enum integer_register_id a,
	enum integer_register_id b,
	enum register_size rsize);


#endif
