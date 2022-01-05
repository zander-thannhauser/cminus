
#include <stdio.h>

struct asm_writer;

int asm_writer_vfprintf(
	FILE* const stream,
	const char* fmt,
	va_list vargs);



