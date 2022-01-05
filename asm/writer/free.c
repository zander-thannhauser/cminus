
#include <debug.h>

#include "struct.h"
#include "free.h"

void free_asm_writer(struct asm_writer* this)
{
	ENTER;
	
	#ifdef VERBOSE_ASSEMBLY
	assert(!this->indent_head);
	#endif
	
	fclose(this->stream);
	
	EXIT;
}

