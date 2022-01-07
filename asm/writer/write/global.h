
#include <stdbool.h>

struct asm_writer;
struct initializer;
struct type;

int asm_writer_write_global(
	struct asm_writer* this,
	const char* identifier,
	bool is_static,
	struct initializer* value,
	struct type* type);
