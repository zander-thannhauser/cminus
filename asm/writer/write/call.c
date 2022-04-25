
#include <assert.h>

/*#include "../../enums/register_size.h"*/
#include "../../tables/intregs.h"
/*#include "../../location/write.h"*/
#include "../write.h"

#include "call.h"

int asm_writer_write_call(
	struct asm_writer* this,
	enum integer_register_id rid)
{
	int error = 0;
	ENTER;
	
	asm_writer_write(this,
		"call *%s",
		intregs[rid][quadword]);
	
	EXIT;
	return error;
}














