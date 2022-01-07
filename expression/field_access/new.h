
struct yylloc;
struct expression;
struct struct_field;

int new_field_access_expression(
	struct expression** new,
	struct yylloc* loc,
	struct expression* inner,
	struct struct_field* struct_field);




