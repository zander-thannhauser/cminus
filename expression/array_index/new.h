
struct yylloc;
struct expression;
struct struct_field;
struct type;

int new_array_index_expression(
	struct expression** new,
	struct yylloc* loc,
	struct expression* array,
	struct expression* index,
	struct type* type);



