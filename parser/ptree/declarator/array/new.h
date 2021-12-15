
#include <stddef.h>

struct array_declarator;
struct declarator;
struct expression;

int new_array_declarator(
	struct array_declarator** new,
	struct declarator* inner,
	size_t array_size);


int new_sizeless_array_declarator(
	struct array_declarator** new,
	struct declarator* inner);
