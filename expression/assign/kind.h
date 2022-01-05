
#ifndef BINARY_EXPRESSION_KIND_ENUM
#define BINARY_EXPRESSION_KIND_ENUM

enum assign_expression_kind
{
	aek_regular_assign,
	
	aek_add_assign,
	aek_bitwise_and_assign,
	aek_bitwise_or_assign,
	aek_bitwise_xor_assign,
	aek_divide_assign,
	aek_leftshift_assign,
	aek_multiply_assign,
	aek_rdivide_assign,
	aek_rightshift_assign,
	aek_subtract_assign,
	
	number_of_assign_expressions,
};

#endif
