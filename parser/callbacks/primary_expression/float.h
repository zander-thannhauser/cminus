
struct types;
struct expression;
struct asm_writer;

int primary_expression_float_callback(
	struct expression** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct types* types,
	float floatlit);
