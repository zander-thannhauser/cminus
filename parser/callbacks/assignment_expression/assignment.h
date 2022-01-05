
struct types;
struct expression;
enum binary_expression_kind;

#include <expression/assign/kind.h>

int assignment_expression_assignment_callback(
	struct expression** retval,
	struct expression* left,
	enum assign_expression_kind kind,
	struct expression* right,
	struct types* types);
