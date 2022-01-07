
struct yylloc;
struct dereference_expression;

int new_dereference_expression(
	struct expression** new,
	struct yylloc* loc,
	struct expression* inner,
	struct type* type);




