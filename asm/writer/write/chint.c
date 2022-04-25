
#if 0
#include <assert.h>

#include "chint.h"

static const char* const zero_extend_lookup[][] = {
	
	[] = {[] = ,[] = ,[] = ,[] = },
};

void asm_writer_write_chint(
	struct asm_writer* this,
	size_t src_offset, enum integer_register_id src, enum integer_kind src_kind,
	enum integer_register_id dst, enum integer_kind dst_kind)
{
	
	if (src_kind & 1)
	{
		// initially unsigned:
		fprintf(this->stream,
			"%s %zi(%s), %s",
			zero_extend_lookup[][],
			src_offset, intregs[src][quadword],
			
	}
	else
	{
		// initially signed:
		TODO;
	}
	
	TODO;
}
#endif
