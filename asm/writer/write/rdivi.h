
#if 0

#include <asm/enums/intregs.h>
#include <type/integer/kind.h>

struct asm_writer;

int asm_writer_write_rdivi(
	struct asm_writer* this,
	enum integer_register_id numerator_reg,
	enum integer_register_id denominator_reg,
	enum integer_kind ikind);


#endif
