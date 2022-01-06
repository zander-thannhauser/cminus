
#include <stddef.h>

struct statement;
enum statement_kind;
struct statement_inheritance;
struct yylloc;

#include "kind.h"

int new_statement(
	struct statement** new,
	enum statement_kind kind,
	struct statement_inheritance* inheritance,
	struct yylloc* loc,
	size_t alloc_size);
