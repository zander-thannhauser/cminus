
#include <stddef.h>

struct declarator;
enum declarator_kind;
struct declarator_inheritance;

int new_declarator(
	struct declarator** new,
	enum declarator_kind kind,
	struct declarator_inheritance* inheritance,
	size_t alloc_size);
