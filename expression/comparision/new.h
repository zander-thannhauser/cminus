
enum comparision_expression_kind;
struct expression;
struct types;

#include "kind.h"

int new_comparision_expression(
	struct expression** new,
	enum comparision_expression_kind kind,
	struct expression* left,
	struct expression* right,
	struct types* types);
