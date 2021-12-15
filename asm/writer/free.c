
#include <debug.h>

#include "struct.h"
#include "free.h"

void free_asm_writer(struct asm_writer* this)
{
	fclose(this->out);
}

