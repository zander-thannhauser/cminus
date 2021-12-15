
#ifndef BINARY_EXPRESSION_KIND_ENUM
#define BINARY_EXPRESSION_KIND_ENUM

enum binary_expression_kind
{
	bek_add,
	bek_add_assign,
	bek_bitwise_and_assign,
	bek_bitwise_or_assign,
	bek_bitwise_xor_assign,
	bek_divide,
	bek_divide_assign,
	bek_equal_to,
	bek_logical_and,
	bek_logical_or,
	bek_greater_than,
	bek_greater_than_equal_to,
	bek_leftshift,
	bek_leftshift_assign,
	bek_less_than,
	bek_less_than_equal_to,
	bek_multiply,
	bek_multiply_assign,
	bek_rdivide,
	bek_rdivide_assign,
	bek_rightshift,
	bek_rightshift_assign,
	bek_not_equal_to,
	bek_regular_assign,
	bek_subtract,
	bek_subtract_assign,
	number_of_binary_expressions,
};

#endif
