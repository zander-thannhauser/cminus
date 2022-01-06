
struct types;
struct expression;

int postfix_expression_array_index_callback(
	struct expression** out,
	struct expression* array,
	struct expression* index,
	struct types* types);
