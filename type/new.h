
#include <stdbool.h>
#include <stddef.h>

#include <enums/storage_class.h>
#include <enums/type_qualifier.h>

struct type;
enum type_kind;
struct type_inheritance;

#include "kind.h"

int new_type(
	struct type** new,
	enum type_kind kind,
	struct type_inheritance* inheritance,
	bool is_complete,
	size_t size,
	size_t alloc_size);
