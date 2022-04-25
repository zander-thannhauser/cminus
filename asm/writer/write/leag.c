
#include <assert.h>

#include "../../enums/register_size.h"
#include "../../tables/intregs.h"
/*#include "../../location/write.h"*/
#include "../write.h"

#include "lea.h"

int asm_writer_write_leag(
	struct asm_writer* this,
	char* name,
	enum integer_register_id rid)
{
	int error = 0;
	ENTER;
	
	// same size: just copy:
	asm_writer_write(this,
		"movq %s@GOTPCREL(%%rip), %s",
		name,
		intregs[rid][quadword]);
	
	EXIT;
	return error;
}














