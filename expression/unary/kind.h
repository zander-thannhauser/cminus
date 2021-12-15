
#ifndef UNARY_EXPRESSION_KIND_ENUM
#define UNARY_EXPRESSION_KIND_ENUM

enum unary_expression_kind
{
	uek_address_of,
	uek_dereference,
	
	uek_numeric_plus,
	uek_numeric_negate,
	uek_bitwise_negate,
	uek_logical_negate,
};

#endif
