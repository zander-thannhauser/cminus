
#if 0
#include <assert.h>

/*#include "../struct.h"*/

#include "../write.h"

#include "double.h"

int asm_writer_write_double(
	struct asm_writer* this,
	size_t section_id, double flo)
{
	int error = 0;
	unsigned i, n;
	ENTER;
	
	uint64_t u64 = *((typeof(u64)*) &flo);
	
	uint32_t high = u64 >> 32, low = u64 & ~(-1UL << 32);
	
	asm_writer_write(this,
		".double_%lu: .long %u .long %u", section_id, low, high);
	
	EXIT;
	return error;
}
#endif
