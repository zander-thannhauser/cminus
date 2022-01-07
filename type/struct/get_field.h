
struct struct_type;
struct struct_field;

int struct_type_get_field(
	struct struct_field** out,
	struct struct_type* this,
	const char* field_name);
