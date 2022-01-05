
#include <stdint.h>

#include <debug.h>

#include "../write.h"

#include "pushf.h"

void asm_writer_write_pushf(
	struct asm_writer* this,
	float flo)
{
	ENTER;
	
	assert(sizeof(uint32_t) == sizeof(float));
	
	uint32_t x = *((typeof(x)*) &flo);
	
	asm_writer_write(this, "movq $0x%08lX, -8(%%rsp)", x);
	asm_writer_write(this, "subq $8, %%rsp");
	
	EXIT;
}

