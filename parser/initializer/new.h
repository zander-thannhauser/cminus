
struct initializer;
struct expression;
struct initializer_ll;
struct yylloc;

int new_initializer_as_expression(
	struct initializer** out,
	struct yylloc* loc,
	struct expression* expression);

int new_initializer_as_initializer_ll(
	struct initializer** out,
	struct yylloc* loc,
	struct initializer_ll* initializer_ll);



