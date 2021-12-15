
struct type;
struct declarator;

struct declarator_inheritance
{
	int (*build_type)(
		char** out_identifier,
		struct type** out_type,
		struct type* base_type,
		struct declarator* this);
	
	void (*free)(
		struct declarator* this);
};

