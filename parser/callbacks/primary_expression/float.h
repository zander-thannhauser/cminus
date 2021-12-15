
struct types;
struct expression;
struct asm_writer;

int primary_expression_float_callback(
	struct expression** retval,
	struct types* types,
	float floatlit);
