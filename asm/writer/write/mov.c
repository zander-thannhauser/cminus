
#include <stdlib.h>

#include <assert.h>

#include "../../tables/intregs.h"

#include "../write.h"

#include "mov.h"

static const char* mov[number_of_register_sizes] = 
{
	[byte] = "movb",
	[word] = "mov",
	[doubleword] = "movl",
	[quadword] = "movq",
};

int asm_writer_write_mov(
	struct asm_writer* this,
	ssize_t src_offset, enum integer_register_id src_rel,
	ssize_t dst_offset, enum integer_register_id dst_rel,
	enum register_size rsize)
{
	int error = 0;
	ENTER;
	
	asm_writer_write(this,
		"%s %zi(%s), %s",
		mov[rsize],
		src_offset, intregs[src_rel][quadword],
		intregs[working_1][rsize]);
	
	asm_writer_write(this,
		"%s %s, %zi(%s)",
		mov[rsize],
		intregs[working_1][rsize],
		dst_offset, intregs[dst_rel][quadword]);
	
	EXIT;
	return error;
}














