
struct expression;
struct type;
struct types;

int unary_expression_sizeof_type_callback(
	struct expression** retval,
	struct type* type,
	struct types* types);
