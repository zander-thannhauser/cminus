
#include <stdlib.h>

#include <type/float/kind.h>

#include "../../enums/floatregs.h"
#include "../../enums/intregs.h"

struct asm_writer;
struct asm_location;

int asm_writer_write_movf_between(
	struct asm_writer* this,
	/* from: */ enum float_register_id src,
	/* to:   */ enum float_register_id dst,
	enum float_kind fkind);

int asm_writer_write_movf_to(
	struct asm_writer* this,
	/* from: */ ssize_t offset, enum integer_register_id iid,
	/* to:   */ enum float_register_id fid,
	enum float_kind fkind);

int asm_writer_write_movf_from(
	struct asm_writer* this,
	/* from: */ enum float_register_id fid,
	/* to:   */ ssize_t offset, enum integer_register_id iid,
	enum float_kind fkind);
