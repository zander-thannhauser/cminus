
struct types;
struct expression;
enum binary_expression_kind;

#include <expression/binary/kind.h>

int assignment_expression_assignment_callback(
	struct expression** retval,
	struct expression* left,
	enum binary_expression_kind kind,
	struct expression* right,
	struct types* types);
