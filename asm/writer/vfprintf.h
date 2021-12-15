
struct asm_writer;

int asm_writer_vfprintf(
	struct asm_writer* this,
	const char* fmt,
	va_list vargs);
