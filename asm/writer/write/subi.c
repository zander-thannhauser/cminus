
#include <debug.h>

#include "../../tables/intregs.h"
/*#include "../../tables/iktors.h"*/
/*#include "../../location/write.h"*/

#include "../write.h"

#include "subi.h"

static const char* lookup[number_of_register_sizes] =
{
	"subb", "subw", "subl", "sub"
};

int asm_writer_write_subi_const(
	struct asm_writer* this,
	uintmax_t val,
	enum integer_register_id id,
	enum register_size rsize)
{
	ENTER;
	
	asm_writer_write(this, "%s $%ju, %s",
		lookup[rsize],
		val,
		intregs[id][rsize]);
	
	EXIT;
	return 0;
}

#if 0
int asm_writer_write_sub(
	struct asm_writer* this,
	struct asm_location* src_loc,
	struct asm_location* dst_loc,
	enum integer_kind result_kind)
{
	int error = 0;
	char src_buffer[30], dst_buffer[30];
	ENTER;
	
		write_asm_location(src_loc, rs, src_buffer),
		write_asm_location(dst_loc, rs, dst_buffer));
	
	EXIT;
	return error;
}
#endif
