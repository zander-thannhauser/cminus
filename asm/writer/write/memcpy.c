
#if 0
#include <debug.h>

#include "../write.h"

#include "movi.h"
#include "memcpy.h"

int asm_writer_write_memcpy(
	struct asm_writer* this,
	enum integer_register_id dst,
	enum integer_register_id src,
	uint64_t n)
{
	int error = 0;
	ENTER;
	
	asm_writer_write_movi_between_v2(this, dst, rsi, quadword);
	asm_writer_write_movi_between_v2(this, src, rdi, quadword);
	asm_writer_write_movi_const_v2(this, n, rcx, quadword);
	
	asm_writer_write(this, "rep movsb");
	
	EXIT;
	return error;
}

#endif
