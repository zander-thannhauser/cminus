
#if 0
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

int asm_writer_write_subi(
	struct asm_writer* this,
	enum integer_register_id a,
	enum integer_register_id b,
	enum register_size rsize)
{
	ENTER;
	
	asm_writer_write(this, "%s %s, %s",
		lookup[rsize],
		intregs[a][rsize],
		intregs[b][rsize]);
	
	EXIT;
	return 0;
}















#endif
