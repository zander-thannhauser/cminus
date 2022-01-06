
struct ternary_expression;
struct variable;

int new_ternary_expression(
	struct ternary_expression** new,
	struct yylloc* loc,
	struct expression* conditional,
	struct expression* true_expression,
	struct expression* false_expression);


