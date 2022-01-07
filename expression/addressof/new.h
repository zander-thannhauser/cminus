
struct yylloc;
struct addressof_expression;

int new_addressof_expression(
	struct expression** new,
	struct yylloc* loc,
	struct expression* inner,
	struct type* type);




