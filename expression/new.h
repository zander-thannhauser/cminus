
#include <stddef.h>

#include "kind.h"

struct expression;
struct expression_inheritance;
struct type;

int new_expression(
	struct expression** new,
	enum expression_kind kind,
	struct expression_inheritance* inheritance,
	struct type* type,
	size_t alloc_size);
