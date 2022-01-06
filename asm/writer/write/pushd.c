
#if 0
#include <inttypes.h>

#include <debug.h>

#include "../write.h"

#include "pushd.h"

void asm_writer_write_pushd(
	struct asm_writer* this,
	double dou)
{
	ENTER;
	
	assert(sizeof(uint64_t) == sizeof(double));
	
	uint64_t x = *((typeof(x)*) &dou);
	
	asm_writer_write(this, "movq $0x%016lX, %%r10", x);
	asm_writer_write(this, "movq %%r10, -8(%%rsp)");
	asm_writer_write(this, "subq $8, %%rsp");
	
	EXIT;
}




















#endif
