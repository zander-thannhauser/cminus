
#ifdef X64_TARGET
#include <asm/enums/intregs.h>
#endif

struct asm_writer;

int asm_writer_write_leag(
	struct asm_writer* this,
	char* name,
	#ifdef X64_TARGET
	enum integer_register_id rid);
	#else
	unsigned rid);
	#endif

