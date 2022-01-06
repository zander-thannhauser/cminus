
#include <stddef.h>

struct statement;
enum statement_kind;
struct statement_inheritance;

#include "kind.h"

int new_statement(
	struct statement** new,
	enum statement_kind kind,
	struct statement_inheritance* inheritance,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	size_t alloc_size);
