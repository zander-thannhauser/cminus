
struct expression;
struct types;
struct yylloc;

int new_logical_and_expression(
	struct expression** new,
	struct yylloc* loc,
	struct expression* left,
	struct expression* right,
	struct types* types);
