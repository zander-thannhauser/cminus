
#include <stddef.h>

struct string_expression;
struct type;

int new_string_expression(
	struct string_expression** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	size_t string_id,
	char* data, size_t strlen,
	struct type* charptr_type);
