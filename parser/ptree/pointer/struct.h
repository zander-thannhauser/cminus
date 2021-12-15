
struct type_qualifiers;

struct pointer
{
	struct type_qualifiers* qualifiers;
	struct pointer* inner;
};

