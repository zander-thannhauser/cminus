
#include <type/integer/kind.h>

#include <asm/enums/intregs.h>

struct asm_writer;

int asm_writer_write_divi(
	struct asm_writer* this,
	enum integer_register_id numerator_reg,
	enum integer_register_id denominator_reg,
	enum integer_kind ikind);
