
#include <stdlib.h>

/*#include <stdbool.h>*/

/*#include <asm/enums/registers.h>*/
/*#include <asm/enums/register_size.h>*/

#include <type/integer/kind.h>

#include "../../enums/intregs.h"

struct asm_writer;
/*struct asm_location;*/

int asm_writer_write_movi_between(
	struct asm_writer* this,
	enum integer_register_id siid,
	enum integer_register_id diid,
	enum integer_kind ikind);

int asm_writer_write_movi_to(
	struct asm_writer* this,
	/* from: */ ssize_t offset, enum integer_register_id fiid,
	/* to:   */ enum integer_register_id tiid,
	enum integer_kind ikind);

int asm_writer_write_movi_from(
	struct asm_writer* this,
	/* from: */ enum integer_register_id fiid,
	/* to:   */ ssize_t offset, enum integer_register_id tiid,
	enum integer_kind ikind);
