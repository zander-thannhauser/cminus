
#ifndef UNARY_EXPRESSION_KIND_ENUM
#define UNARY_EXPRESSION_KIND_ENUM

enum unary_expression_kind
{
	uek_addressof,
	uek_dereference,
	
	uek_numeric_plus,
	uek_numeric_negate,
	uek_bitwise_negate,
	uek_logical_negate,
	
	number_of_unary_expressions,
};

#endif
