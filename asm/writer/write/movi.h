
#include <stdint.h>
#include <stdlib.h>

/*#include <stdbool.h>*/

/*#include <asm/enums/registers.h>*/
#include <asm/enums/register_size.h>

#include <type/integer/kind.h>

#include "../../enums/intregs.h"

struct asm_writer;
/*struct asm_location;*/

int asm_writer_write_movi_const_v2(
	struct asm_writer* this,
	uint64_t val,
	enum integer_register_id dst_id,
	enum register_size rs);

int asm_writer_write_movi_between_v2(
	struct asm_writer* this,
	enum integer_register_id src_id,
	enum integer_register_id dst_id,
	enum register_size rs);

int asm_writer_write_movi_to_v2(
	struct asm_writer* this,
	/* from: */ ssize_t offset, enum integer_register_id srcid,
	/* to:   */ enum integer_register_id dstid,
	enum register_size rs);

int asm_writer_write_movi_from_v2(
	struct asm_writer* this,
	/* from: */ enum integer_register_id srcid,
	/* to:   */ ssize_t offset, enum integer_register_id dstid,
	enum register_size rs);
