
#include <assert.h>

#include "struct.h"
#include "free.h"

void free_asm_writer(struct asm_writer* this)
{
	ENTER;
	
	#if defined VERBOSE_ASSEMBLY && !(defined DEBUGGING)
	assert(!this->indent_head);
	#endif
	
	fclose(this->stream);
	
	EXIT;
}

