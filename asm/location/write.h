
#include "../enums/register_size.h"

struct asm_location;

char* write_asm_location(
	struct asm_location* this,
	enum register_size rsize,
	char* buffer);
