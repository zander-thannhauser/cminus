
#if 0
#include <stdlib.h>

#include <debug.h>

/*#include "../../tables/intregs.h"*/

/*#include "../write.h"*/

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
	const char* gname, enum storage_class sc,
	ssize_t dst_offset, enum integer_register_id dst_rel,
	enum register_size rsize)
{
	int error = 0;
	ENTER;
	
	asm_writer_write(this,
		"%s %zi(%s), %zi(%s)",
		mov[rsize],
		src_offset, intregs[src_rel][rsize],
		dst_offset, intregs[dst_rel][rsize]);
	
	EXIT;
	return error;
}













#endif
