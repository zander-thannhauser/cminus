
#if 0
#include <debug.h>

#include "../../tables/intregs.h"
/*#include "../../tables/iktors.h"*/
/*#include "../../location/write.h"*/

#include "../write.h"

#include "addi.h"

static const char* lookup[number_of_register_sizes] = {
	"addb", "addw", "addl", "add"
};

int asm_writer_write_addi_const(
	struct asm_writer* this,
	uintmax_t val,
	enum integer_register_id id,
	enum register_size rs)
{
	int error = 0;
	ENTER;
	
	asm_writer_write(this, "%s $%ju, %s",
		lookup[rs],
		val,
		intregs[id][rs]);
	
	EXIT;
	return error;
}

int asm_writer_write_addi(
	struct asm_writer* this,
	enum integer_register_id src,
	enum integer_register_id dst,
	enum register_size rs)
{
	int error = 0;
	ENTER;
	
	asm_writer_write(this, "%s %s, %s",
		lookup[rs],
		intregs[src][rs],
		intregs[dst][rs]);
	
	EXIT;
	return error;
}









#endif
