
#include <stddef.h>

#include "kind.h"

struct expression;
struct expression_inheritance;
struct type;

int new_expression(
	struct expression** new,
	enum expression_kind kind,
	struct expression_inheritance* inheritance,
	unsigned first_line, unsigned first_column,
	unsigned last_line,  unsigned last_column,
	struct type* type,
	size_t alloc_size);
