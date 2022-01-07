
#ifndef EXPRESSION_KIND_ENUM
#define EXPRESSION_KIND_ENUM

enum expression_kind
{
	ek_addressof,
	ek_arithmetic,
	ek_array_index,
	ek_assign,
	ek_cast,
	ek_comma,
	ek_dereference,
	ek_field_access,
	ek_function_call,
	ek_initializer,
	ek_logical_and,
	ek_literal,
	ek_unary,
	ek_parentheses,
	ek_string,
	ek_relational,
	ek_variable,
	
	number_of_expression_kinds,
};

#endif // EXPRESSION_KIND_ENUM
