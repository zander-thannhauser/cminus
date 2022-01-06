
enum bitshift_expression_kind;
struct expression;
struct types;

#include "kind.h"

int new_bitshift_expression(
	struct expression** new,
	enum bitshift_expression_kind kind,
	struct expression* left,
	struct expression* right,
	struct types* types);
