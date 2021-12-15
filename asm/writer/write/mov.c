
#include <debug.h>

#include "../../enums/register_size.h"
#include "../../tables/iktors.h"
#include "../../location/write.h"
#include "../write.h"

#include "mov.h"

static const char* mov_lookup[number_of_register_sizes] = 
{
	[byte] = "movb",
	[word] = "mov",
	[doubleword] = "movl",
	[quadword] = "movq",
};

int asm_writer_write_mov(
	struct asm_writer* this,
	struct asm_location* src_loc, enum integer_kind src_kind,
	struct asm_location* dst_loc, enum integer_kind dst_kind)
{
	int error = 0;
	char src_buffer[30], dst_buffer[30];
	enum register_size src_size = iktors[src_kind], dst_size = iktors[dst_kind];
	ENTER;
	
	if (dst_size < src_size)
	{
		TODO; // truncate?
	}
	else if (dst_size > src_size)
	{
		TODO; // promotion?
	}
	else
	{
		// same size: just copy:
		asm_writer_write(this,
			"%s %s, %s",
			mov_lookup[dst_size],
			write_asm_location(src_loc, src_size, src_buffer),
			write_asm_location(dst_loc, dst_size, dst_buffer));
	}
	
	EXIT;
	return error;
}














