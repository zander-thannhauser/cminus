
struct yylloc;
enum assign_expression_kind;
struct expression;
struct types;

#include "kind.h"

int new_assign_expression(
	struct expression** new,
	struct yylloc* loc,
	enum assign_expression_kind kind,
	struct expression* left,
	struct expression* right,
	struct types* types);
