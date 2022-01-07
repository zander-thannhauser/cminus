
struct expression;
struct initializer_ll;

struct initializer
{
	enum {
		ik_expression,
		ik_initializer_list,
	} kind;
	
	union
	{
		struct expression* expression;
		struct initializer_ll* initializer_ll;
	};
	
	struct yylloc* loc;
};

