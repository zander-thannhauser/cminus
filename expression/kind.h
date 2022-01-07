
#ifndef EXPRESSION_KIND_ENUM
#define EXPRESSION_KIND_ENUM

enum expression_kind
{
	ek_arithmetic,
	ek_array_index,
	ek_assign,
	ek_logical_and,
	ek_cast,
	ek_initializer,
	ek_literal,
	ek_field_access,
	ek_function_call,
	ek_unary,
	ek_parentheses,
	ek_string,
	ek_variable,
};

#endif // EXPRESSION_KIND_ENUM
