
#ifndef EXPRESSION_KIND_ENUM
#define EXPRESSION_KIND_ENUM

enum expression_kind
{
	ek_binary,
	ek_cast,
	ek_literal,
	ek_function_call,
	ek_unary,
	ek_parentheses,
	ek_string,
	ek_variable,
};

#endif // EXPRESSION_KIND_ENUM
