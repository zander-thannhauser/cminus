
#ifdef X64_TARGET
#include "../../enums/register_size.h"
#include "../../tables/intregs.h"
#endif

#include "../write.h"

#include "leag.h"

int asm_writer_write_leag(
	struct asm_writer* this,
	char* name,
	#ifdef X64_TARGET
	enum integer_register_id rid)
	#else
	unsigned rid)
	#endif
{
	int error = 0;
	ENTER;
	
	dpvs(name);
	
	asm_writer_write(this,
		#ifdef X64_TARGET
		"movq %s@GOTPCREL(%%rip), %s",
		#else
		"loadI %s, %%vr%u",
		#endif
		name,
		#ifdef X64_TARGET
		intregs[rid][quadword]);
		#else
		rid);
		#endif
	
	EXIT;
	return error;
}













