
#include <debug.h>

/*#include "../../tables/intregs.h"*/
#include "../../tables/iktors.h"
#include "../../location/write.h"

#include "../write.h"

#include "sub.h"

static const char* lookup[number_of_register_sizes] = {
	"subb", "subw", "subl", "sub"
};

int asm_writer_write_sub(
	struct asm_writer* this,
	struct asm_location* src_loc,
	struct asm_location* dst_loc,
	enum integer_kind result_kind)
{
	int error = 0;
	char src_buffer[30], dst_buffer[30];
	enum register_size rs = iktors[result_kind];
	ENTER;
	
	asm_writer_write(this, "%s %s, %s",
		lookup[rs],
		write_asm_location(src_loc, rs, src_buffer),
		write_asm_location(dst_loc, rs, dst_buffer));
	
	EXIT;
	return error;
}

