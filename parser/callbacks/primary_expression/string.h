
struct types;
struct expression;
struct asm_writer;

int primary_expression_string_callback(
	struct expression** out,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	char* string_data,
	size_t string_strlen,
	struct types* types,
	size_t* string_counter,
	struct asm_writer* writer);
