
struct types;
struct expression;

int postfix_expression_array_index_callback(
	struct expression** out,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* array,
	struct expression* index,
	struct types* types);





