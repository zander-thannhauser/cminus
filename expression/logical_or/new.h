
struct expression;
struct types;
struct yylloc;

int new_logical_or_expression(
	struct expression** new,
	struct yylloc* loc,
	struct expression* left,
	struct expression* right,
	struct types* types);
