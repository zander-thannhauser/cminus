
struct expression;
struct types;

int expression_comma_callback(
	struct expression** retval,
	struct expression* left,
	struct expression* right,
	struct types* types);
