
#ifndef BINARY_EXPRESSION_KIND_ENUM
#define BINARY_EXPRESSION_KIND_ENUM

enum binary_expression_kind
{
	bek_add,
	bek_divide,
	bek_equal_to,
	bek_logical_and,
	bek_logical_or,
	bek_greater_than,
	bek_greater_than_equal_to,
	bek_leftshift,
	bek_less_than,
	bek_less_than_equal_to,
	bek_multiply,
	bek_rdivide,
	bek_rightshift,
	bek_not_equal_to,
	bek_subtract,
	
	number_of_binary_expressions,
};

#endif
