
struct type;
struct specifier_qualifiers;
struct declarator;

int type_name_qualifier_list_and_abstract_declarator(
	struct type** retval,
	struct specifier_qualifiers* sq,
	struct declarator* declarator);
