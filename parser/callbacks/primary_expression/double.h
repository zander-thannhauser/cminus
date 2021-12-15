
struct types;
struct expression;
struct asm_writer;

int primary_expression_double_callback(
	struct expression** retval,
	struct types* types,
	double doublelit);
