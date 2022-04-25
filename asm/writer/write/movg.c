
#if 0
#include <stdlib.h>

#include <assert.h>

#include "../../tables/intregs.h"

#include "../write.h"

#include "movg.h"

static const char* mov[number_of_register_sizes] = 
{
	[byte] = "movb",
	[word] = "mov",
	[doubleword] = "movl",
	[quadword] = "movq",
};

int asm_writer_write_movg(
	struct asm_writer* this,
	const char* name,
	ssize_t dst_offset, enum integer_register_id dst_rel,
	enum register_size rsize)
{
	int error = 0;
	ENTER;
	
	asm_writer_write_leag(this, name,
		enum integer_register_id rid);
	
	asm_writer_write(this,
		"%s (%s@GOTPCREL(%%rip)), %zi(%s)",
		mov[rsize],
		name,
		dst_offset, intregs[dst_rel][rsize]);
	
	EXIT;
	return error;
}













#endif
