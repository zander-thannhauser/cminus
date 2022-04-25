
#include <assert.h>

#include "../write.h"
#include "lea.h"
#include "movi.h"
#include "memset.h"

int asm_writer_write_memset(
	struct asm_writer* this,
	ssize_t offset, enum integer_register_id ptr_relto,
	uint8_t value,
	uint64_t n)
{
	int error = 0;
	ENTER;
	
	error = 0
		?: asm_writer_write_lea(this, -offset, ptr_relto, rdi)
		?: asm_writer_write_movi_const_v2(this, value, rax, byte)
		?: asm_writer_write_movi_const_v2(this, n, rcx, quadword)
		?: asm_writer_write(this, "rep stosb");
	
	EXIT;
	return error;
}

