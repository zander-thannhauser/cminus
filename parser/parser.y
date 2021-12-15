
%token<identifier> IDENTIFIER
%token<sintegerlit> SINT_LITERAL
%token<uintegerlit> UINT_LITERAL
%token<slonglit> SLONG_LITERAL
%token<ulonglit> ULONG_LITERAL
%token<floatlit> FLOAT_LITERAL
%token<doublelit> DOUBLE_LITERAL
%token<string> STRING_LITERAL

%token<type> TYPE_NAME

%token SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN 

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%start start

%define parse.error verbose

// https://stackoverflow.com/questions/12731922/reforming-the-grammar-to-remove-shift-reduce-conflict-in-if-then-else:
%right "then" ELSE // Same precedence, but "shift" wins.

%parse-param {int *error}
%parse-param {struct scope *scope}
%parse-param {struct types *types}
%parse-param {struct asm_writer* asm_writer}
%parse-param {unsigned *line}
%parse-param {size_t *section_counter}

%lex-param {struct scope *scope}
%lex-param {unsigned *line}

%code requires {
	struct types;
	struct scope;
	struct asm_writer;
	
	#include <stddef.h>
	#include <stdbool.h>
	#include <inttypes.h>
	
	#include <enums/storage_class.h>
	#include <enums/type_qualifier.h>
	
	#include <expression/binary/kind.h>
	#include <expression/unary/kind.h>
}

%code top {
	#include <memory/tfree.h>
	
	struct type* rettype;
	char* funcname;
}

%union {
	bool boolean;
	
	signed int sintegerlit;
	unsigned int uintegerlit;
	signed long slonglit;
	unsigned long ulonglit;
	
	float floatlit;
	double doublelit;
	
	unsigned line;
	
	char* identifier;
	
	struct {
		char* data;
		size_t strlen;
	} string;
	
	struct expression* expression;
	struct type* type;
	struct function_type* ftype;
	struct declaration_specifiers* declaration_specifiers;
	struct declarator* declarator;
	struct init_declarator* init_declarator;
	struct init_declarator_ll* init_declarator_ll;
	struct declaration_ll* declaration_ll;
	struct expression_ll* expression_ll;
	struct statement* statement;
	struct statement_ll* statement_ll;
	struct compound_statement* compound_statement;
	struct function_definition* function_definition;
	struct translation_unit* translation_unit;
	struct translation_unit_ll* translation_unit_ll;
	struct parameter* parameter;
	struct parameter_ll* parameter_ll;
	struct struct_field_ll* struct_field_ll;
	struct struct_field* struct_field;
	struct specifier_qualifiers* specifier_qualifiers;
	struct enumerator* enumerator;
	struct enumerator_entry* enumerator_entry;
	struct pointer* pointer;
	struct identifier_ll* identifier_ll;
	struct abstract_declarator* abstract_declarator;
	struct initializer* initializer;
	struct struct_declarator_ll* struct_declarator_ll;
	struct struct_declarator* struct_declarator;
	struct type_qualifiers* type_qualifier_list;
	
	enum type_qualifier type_qualifier;
	enum storage_class storage_class;
	enum unary_expression_kind unary_expression_kind;
	enum binary_expression_kind binary_expression_kind;
};

%destructor { tfree($$); } <*>
%destructor { tfree($$.data); } <string>
%destructor {  } <sintegerlit>
%destructor {  } <uintegerlit>
%destructor {  } <slonglit>
%destructor {  } <ulonglit>
%destructor {  } <floatlit>
%destructor {  } <doublelit>
%destructor {  } <boolean>
%destructor {  } <line>
%destructor {  } <storage_class>
%destructor {  } <type_qualifier>
%destructor {  } <unary_expression_kind>
%destructor {  } <binary_expression_kind>

%{

#include <stdio.h>
#include <stdlib.h>

#include <debug.h>

#include "yyerror.h"

#include "callbacks/abstract_declarator/pointer.h"
#include "callbacks/additive_expression/add.h"
#include "callbacks/additive_expression/subtract.h"
#include "callbacks/and_expression/and.h"
#include "callbacks/argument_expression_list/append.h"
#include "callbacks/argument_expression_list/head.h"
#include "callbacks/assignment_expression/assignment.h"
#include "callbacks/cast_expression/cast.h"
#include "callbacks/compound_statement/close.h"
#include "callbacks/compound_statement/open.h"
#include "callbacks/compound_statement/statements.h"
#include "callbacks/conditional_expression/ternary.h"
#include "callbacks/declaration/just_specifiers.h"
#include "callbacks/declaration/specifiers_and_init_list.h"
#include "callbacks/declaration_list/merge.h"
#include "callbacks/declaration_specifiers/storage_class.h"
#include "callbacks/declaration_specifiers/type_qualifier.h"
#include "callbacks/declaration_specifiers/type_specifier.h"
#include "callbacks/declarator/pointer.h"
#include "callbacks/direct_abstract_declarator/array.h"
#include "callbacks/direct_abstract_declarator/empty_function.h"
#include "callbacks/direct_abstract_declarator/function.h"
#include "callbacks/direct_abstract_declarator/sizeless_array.h"
#include "callbacks/direct_declarator/array.h"
#include "callbacks/direct_declarator/function.h"
#include "callbacks/direct_declarator/identifier.h"
#include "callbacks/direct_declarator/identifier_list.h"
#include "callbacks/direct_declarator/parameter_list.h"
#include "callbacks/direct_declarator/sizeless_array.h"
#include "callbacks/enumerator/identifier_and_expression.h"
#include "callbacks/enumerator/just_identifier.h"
#include "callbacks/enumerator_list/append.h"
#include "callbacks/enumerator_list/head.h"
#include "callbacks/enum_specifier/identifier_and_list.h"
#include "callbacks/enum_specifier/just_identifier.h"
#include "callbacks/enum_specifier/just_list.h"
#include "callbacks/equality_expression/equal_to.h"
#include "callbacks/equality_expression/not_equal_to.h"
#include "callbacks/exclusive_or_expression/xor.h"
#include "callbacks/expression/comma.h"
#include "callbacks/expression_statement/expression.h"
#include "callbacks/external_declaration/function.h"
#include "callbacks/external_declaration/global.h"
#include "callbacks/function_definition/prebody.h"
#include "callbacks/function_definition/postbody.h"
#include "callbacks/function_definition/declarator.h"
#include "callbacks/function_definition/declarator_and_list.h"
#include "callbacks/function_definition/specifiers_declarator_and_list.h"
#include "callbacks/function_definition/specifiers_and_declarator.h"
#include "callbacks/identifier_list/append.h"
#include "callbacks/identifier_list/head.h"
#include "callbacks/inclusive_or_expression/or.h"
#include "callbacks/initializer/expression.h"
#include "callbacks/initializer/initializer_list.h"
#include "callbacks/initializer_list/append.h"
#include "callbacks/initializer_list/head.h"
#include "callbacks/init_declarator/just_declarator.h"
#include "callbacks/init_declarator/declarator_and_initializer.h"
#include "callbacks/init_declarator_list/append.h"
#include "callbacks/init_declarator_list/head.h"
#include "callbacks/iteration_statement/dowhile.h"
#include "callbacks/iteration_statement/for.h"
#include "callbacks/iteration_statement/while.h"
#include "callbacks/jump_statement/break.h"
#include "callbacks/jump_statement/continue.h"
#include "callbacks/jump_statement/goto.h"
#include "callbacks/jump_statement/return.h"
#include "callbacks/labeled_statement/case.h"
#include "callbacks/labeled_statement/default.h"
#include "callbacks/labeled_statement/label.h"
#include "callbacks/logical_and_expression/and.h"
#include "callbacks/logical_or_expression/or.h"
#include "callbacks/multiplicative_expression/divide.h"
#include "callbacks/multiplicative_expression/multiply.h"
#include "callbacks/multiplicative_expression/rdivide.h"
#include "callbacks/parameter_declaration/abstract_declarator.h"
#include "callbacks/parameter_declaration/declarator.h"
#include "callbacks/parameter_declaration/just_specifiers.h"
#include "callbacks/parameter_list/append.h"
#include "callbacks/parameter_list/head.h"
#include "callbacks/parameter_type_list/ellipsis.h"
#include "callbacks/pointer/pointer.h"
#include "callbacks/pointer/with_qualifiers.h"
#include "callbacks/postfix_expression/array_index.h"
#include "callbacks/postfix_expression/arrow_access.h"
#include "callbacks/postfix_expression/decrement.h"
#include "callbacks/postfix_expression/empty_function_call.h"
#include "callbacks/postfix_expression/field_access.h"
#include "callbacks/postfix_expression/function_call.h"
#include "callbacks/postfix_expression/increment.h"
#include "callbacks/primary_expression/sinteger.h"
#include "callbacks/primary_expression/uinteger.h"
#include "callbacks/primary_expression/slong.h"
#include "callbacks/primary_expression/ulong.h"
#include "callbacks/primary_expression/string.h"
#include "callbacks/primary_expression/float.h"
#include "callbacks/primary_expression/double.h"
#include "callbacks/primary_expression/identifier.h"
#include "callbacks/primary_expression/parentheses.h"
#include "callbacks/relational_expression/greater_than.h"
#include "callbacks/relational_expression/greater_than_equal_to.h"
#include "callbacks/relational_expression/less_than.h"
#include "callbacks/relational_expression/less_than_equal_to.h"
#include "callbacks/selection_statement/if.h"
#include "callbacks/selection_statement/switch.h"
#include "callbacks/shift_expression/leftshift.h"
#include "callbacks/shift_expression/rightshift.h"
#include "callbacks/specifier_qualifier_list/head_qualifier.h"
#include "callbacks/specifier_qualifier_list/head_specifier.h"
#include "callbacks/specifier_qualifier_list/prepend_qualifier.h"
#include "callbacks/specifier_qualifier_list/prepend_specifier.h"
#include "callbacks/statement_list/append.h"
#include "callbacks/statement_list/head.h"
#include "callbacks/struct_declarator/bitfield.h"
#include "callbacks/struct_declarator/declarator.h"
#include "callbacks/struct_declarator/declarator_and_bitfield.h"
#include "callbacks/struct_declarator_list/append.h"
#include "callbacks/struct_declarator_list/head.h"
#include "callbacks/translation_unit/append.h"
#include "callbacks/type_name/just_qualifier_list.h"
#include "callbacks/type_name/qualifier_list_and_abstract_declarator.h"
#include "callbacks/type_qualifier_list/append.h"
#include "callbacks/type_qualifier_list/head.h"
#include "callbacks/type_specifier/char.h"
#include "callbacks/type_specifier/double.h"
#include "callbacks/type_specifier/float.h"
#include "callbacks/type_specifier/int.h"
#include "callbacks/type_specifier/long.h"
#include "callbacks/type_specifier/short.h"
#include "callbacks/type_specifier/signed.h"
#include "callbacks/type_specifier/unsigned.h"
#include "callbacks/type_specifier/void.h"
#include "callbacks/struct_declaration_list/merge.h"
#include "callbacks/struct_declaration/declaration.h"
#include "callbacks/struct_or_union_specifier/declaration_list.h"
#include "callbacks/struct_or_union_specifier/just_identifier.h"
#include "callbacks/unary_expression/decrement.h"
#include "callbacks/unary_expression/increment.h"
#include "callbacks/unary_expression/operator.h"
#include "callbacks/unary_expression/sizeof_expression.h"
#include "callbacks/unary_expression/sizeof_type.h"

struct scope;

int yylex(struct scope *scope, unsigned* line);

%}

%type <expression> primary_expression
%type <expression> postfix_expression
%type <expression> unary_expression
%type <expression> cast_expression
%type <expression> multiplicative_expression
%type <expression> additive_expression
%type <expression> shift_expression
%type <expression> relational_expression
%type <expression> equality_expression
%type <expression> and_expression
%type <expression> exclusive_or_expression
%type <expression> inclusive_or_expression
%type <expression> logical_and_expression
%type <expression> logical_or_expression
%type <expression> conditional_expression
%type <expression> assignment_expression
%type <expression> expression
%type <declaration_specifiers> declaration_specifiers
%type <storage_class> storage_class_specifier
%type <declarator> declarator
%type <declarator> direct_declarator
%type <type> type_specifier
%type <init_declarator> init_declarator
%type <init_declarator_ll> init_declarator_list
%type <statement_ll> declaration
%type <statement_ll> declaration_list
%type <statement_ll> optional_declaration_list
%type <expression_ll> argument_expression_list
%type <statement> expression_statement
%type <statement> statement
%type <statement_ll> statement_list
%type <binary_expression_kind> assignment_operator
%type <statement_ll> optional_statement_list
%type <compound_statement> compound_statement
%type <function_definition> function_definition
%type <expression> constant_expression
%type <parameter> parameter_declaration
%type <parameter_ll> parameter_list
%type <parameter_ll> parameter_type_list
%type <statement> jump_statement
%type <statement> selection_statement
%type <statement> iteration_statement
%type <unary_expression_kind> unary_operator
%type <statement> labeled_statement
%type <initializer> initializer
%type <initializer> initializer_list
%type <declarator> direct_abstract_declarator
%type <declarator> abstract_declarator
%type <pointer> pointer
%type <specifier_qualifiers> specifier_qualifier_list
%type <type> type_name
%type <identifier_ll> identifier_list
%type <type_qualifier> type_qualifier
%type <type_qualifier_list> type_qualifier_list
%type <enumerator> enumerator_list
%type <enumerator_entry> enumerator
%type <type> enum_specifier
%type <type> struct_or_union_specifier
%type <struct_declarator> struct_declarator
%type <struct_declarator_ll> struct_declarator_list
%type <struct_field_ll> struct_declaration
%type <struct_field_ll> struct_declaration_list
%type <boolean> struct_or_union
%%

primary_expression
	: IDENTIFIER {
		if ((*error = primary_expression_identifier_callback(&$$, scope, $1)))
			YYABORT;
	} | SINT_LITERAL {
		if ((*error = primary_expression_sinteger_callback(&$$, types, $1)))
			YYABORT;
	} | UINT_LITERAL {
		if ((*error = primary_expression_uinteger_callback(&$$, types, $1)))
			YYABORT;
	} | SLONG_LITERAL {
		if ((*error = primary_expression_slong_callback(&$$, types, $1)))
			YYABORT;
	} | ULONG_LITERAL {
		if ((*error = primary_expression_ulong_callback(&$$, types, $1)))
			YYABORT;
	} | FLOAT_LITERAL {
		if ((*error = primary_expression_float_callback(&$$, types, $1)))
			YYABORT;
	} | DOUBLE_LITERAL {
		if ((*error = primary_expression_double_callback(&$$, types, $1)))
			YYABORT;
	} | STRING_LITERAL {
		if ((*error = primary_expression_string_callback(&$$, $1.data, $1.strlen, types, section_counter, asm_writer)))
			YYABORT;
	} | '(' expression ')' {
		if ((*error = primary_expression_parentheses_callback(&$$, $2)))
			YYABORT;
	};

postfix_expression
	: primary_expression {
		$$ = $1;
	} | postfix_expression '[' expression ']' {
		if ((*error = postfix_expression_array_index_callback(&$$, $1, $3, types)))
			YYABORT;
	} | postfix_expression '(' ')' {
		if ((*error = postfix_expression_empty_function_call_callback(&$$, $1, types)))
			YYABORT;
	} | postfix_expression '(' argument_expression_list ')' {
		if ((*error = postfix_expression_function_call_callback(&$$, $1, $3, types)))
			YYABORT;
	} | postfix_expression '.' IDENTIFIER {
		if ((*error = postfix_expression_field_access_callback(&$$, $1, $3)))
			YYABORT;
	} | postfix_expression PTR_OP IDENTIFIER {
		if ((*error = postfix_expression_arrow_access_callback(&$$, $1, $3)))
			YYABORT;
	} | postfix_expression INC_OP {
		if ((*error = postfix_expression_increment_callback(&$$, $1)))
			YYABORT;
	} | postfix_expression DEC_OP {
		if ((*error = postfix_expression_decrement_callback(&$$, $1)))
			YYABORT;
	} ;

argument_expression_list
	: assignment_expression {
		if ((*error = argument_expression_list_head_callback(&$$, $1)))
			YYABORT;
	} | argument_expression_list ',' assignment_expression {
		if ((*error = argument_expression_list_append_callback(&$$, $1, $3)))
			YYABORT;
	};

unary_expression
	: postfix_expression {
		$$ = $1;
	} | INC_OP unary_expression {
		if ((*error = unary_expression_increment_callback(&$$, $2)))
			YYABORT;
	} | DEC_OP unary_expression {
		if ((*error = unary_expression_decrement_callback(&$$, $2)))
			YYABORT;
	} | unary_operator cast_expression {
		if ((*error = unary_expression_operator(&$$, $1, $2, types)))
			YYABORT;
	} | SIZEOF unary_expression {
		if ((*error = unary_expression_sizeof_expression_callback(&$$, $2)))
			YYABORT;
	} | SIZEOF '(' type_name ')' {
		if ((*error = unary_expression_sizeof_type_callback(&$$, $3, types)))
			YYABORT;
	} ;

unary_operator
	: '&' { $$ = uek_address_of; }
	| '*' { $$ = uek_dereference; }
	| '+' { $$ = uek_numeric_plus; }
	| '-' { $$ = uek_numeric_negate; }
	| '~' { $$ = uek_bitwise_negate; }
	| '!' { $$ = uek_logical_negate; }
	;

cast_expression
	: unary_expression {
		$$ = $1;
	} | '(' type_name ')' cast_expression {
		if ((*error = cast_expression_cast_callback(&$$, $2, $4)))
			YYABORT;
	} ;

multiplicative_expression
	: cast_expression {
		$$ = $1;
	} | multiplicative_expression '*' cast_expression {
		if ((*error = multiplicative_expression_multiply_callback(&$$, $1, $3, types)))
			YYABORT;
	} | multiplicative_expression '/' cast_expression {
		if ((*error = multiplicative_expression_divide_callback(&$$, $1, $3, types)))
			YYABORT;
	} | multiplicative_expression '%' cast_expression {
		if ((*error = multiplicative_expression_rdivide_callback(&$$, $1, $3)))
			YYABORT;
	};

additive_expression
	: multiplicative_expression {
		$$ = $1;
	} | additive_expression '+' multiplicative_expression {
		if ((*error = additive_expression_add_callback(&$$, $1, $3, types)))
			YYABORT;
	} | additive_expression '-' multiplicative_expression {
		if ((*error = additive_expression_subtract_callback(&$$, $1, $3, types)))
			YYABORT;
	};

shift_expression
	: additive_expression {
		$$ = $1;
	} | shift_expression LEFT_OP additive_expression {
		if ((*error = shift_expression_leftshift_callback(&$$, $1, $3)))
			YYABORT;
	} | shift_expression RIGHT_OP additive_expression {
		if ((*error = shift_expression_rightshift_callback(&$$, $1, $3)))
			YYABORT;
	} ;

relational_expression
	: shift_expression {
		$$ = $1;
	} | relational_expression '<' shift_expression {
		if ((*error = relational_expression_less_than_callback(&$$, $1, $3, types)))
			YYABORT;
	} | relational_expression '>' shift_expression {
		if ((*error = relational_expression_greater_than_callback(&$$, $1, $3, types)))
			YYABORT;
	} | relational_expression LE_OP shift_expression {
		if ((*error = relational_expression_less_than_equal_to_callback(&$$, $1, $3, types)))
			YYABORT;
	} | relational_expression GE_OP shift_expression {
		if ((*error = relational_expression_greater_than_equal_to_callback(&$$, $1, $3, types)))
			YYABORT;
	};

equality_expression
	: relational_expression {
		$$ = $1;
	} | equality_expression EQ_OP relational_expression {
		if ((*error = equality_expression_equal_to_callback(&$$, $1, $3, types)))
			YYABORT;
	} | equality_expression NE_OP relational_expression {
		if ((*error = equality_expression_not_equal_to_callback(&$$, $1, $3, types)))
			YYABORT;
	};

and_expression
	: equality_expression {
		$$ = $1;
	} | and_expression '&' equality_expression {
		if ((*error = and_expression_and_callback(&$$, $1, $3)))
			YYABORT;
	} ;

exclusive_or_expression
	: and_expression {
		$$ = $1;
	} | exclusive_or_expression '^' and_expression {
		if ((*error = exclusive_or_expression_xor_callback(&$$, $1, $3)))
			YYABORT;
	} ;

inclusive_or_expression
	: exclusive_or_expression {
		$$ = $1;
	} | inclusive_or_expression '|' exclusive_or_expression {
		if ((*error = inclusive_or_expression_or_callback(&$$, $1, $3)))
			YYABORT;
	} ;

logical_and_expression
	: inclusive_or_expression {
		$$ = $1;
	} | logical_and_expression AND_OP inclusive_or_expression {
		if ((*error = logical_and_expression_and_callback(&$$, $1, $3, types)))
			YYABORT;
	};

logical_or_expression
	: logical_and_expression {
		$$ = $1;
	} | logical_or_expression OR_OP logical_and_expression {
		if ((*error = logical_or_expression_or_callback(&$$, $1, $3, types)))
			YYABORT;
	};

conditional_expression
	: logical_or_expression {
		$$ = $1;
	} | logical_or_expression '?' expression ':' conditional_expression {
		if ((*error = conditional_expression_ternary(&$$, $1, $3, $5)))
			YYABORT;
	} ;

assignment_expression
	: conditional_expression {
		$$ = $1;
	} | unary_expression assignment_operator assignment_expression {
		if ((*error = assignment_expression_assignment_callback(&$$, $1, $2, $3, types)))
			YYABORT;
	};

assignment_operator
	: '=' { $$ = bek_regular_assign; }
	| MUL_ASSIGN { $$ = bek_multiply_assign; }
	| DIV_ASSIGN { $$ = bek_divide_assign; }
	| MOD_ASSIGN { $$ = bek_rdivide_assign; }
	| ADD_ASSIGN { $$ = bek_add_assign; }
	| SUB_ASSIGN { $$ = bek_subtract_assign; }
	| LEFT_ASSIGN { $$ = bek_leftshift_assign; }
	| RIGHT_ASSIGN { $$ = bek_rightshift_assign; }
	| AND_ASSIGN { $$ = bek_bitwise_and_assign; }
	| XOR_ASSIGN { $$ = bek_bitwise_xor_assign; }
	| OR_ASSIGN { $$ = bek_bitwise_or_assign; }
	;

expression
	: assignment_expression {
		$$ = $1;
	} | expression ',' assignment_expression {
		if ((*error = expression_comma_callback(&$$, $1, $3)))
			YYABORT;
	} ;

constant_expression
	: conditional_expression {
		$$ = $1;
	} ;

declaration
	: declaration_specifiers ';' {
		// this could only be a struct declaration, right?
		if ((*error = declaration_just_specifiers_callback(&$$, $1)))
			YYABORT;
	} | declaration_specifiers init_declarator_list ';' {
		// these two TODOs are gonna possibly push into type name.
		// is the point where the two sides that make up a type collide:
		if ((*error = declaration_specifiers_and_init_list_callback(&$$, $1, $2, scope)))
			YYABORT;
	};

declaration_specifiers
	: storage_class_specifier {
		if ((*error = declaration_specifiers_storage_class_callback(&$$, $1, NULL)))
			YYABORT;
	} | storage_class_specifier declaration_specifiers {
		if ((*error = declaration_specifiers_storage_class_callback(&$$, $1, $2)))
			YYABORT;
	} | type_specifier {
		if ((*error = declaration_specifiers_type_specifier_callback(&$$, $1, NULL, types)))
			YYABORT;
	} | type_specifier declaration_specifiers {
		if ((*error = declaration_specifiers_type_specifier_callback(&$$, $1, $2, types)))
			YYABORT;
	} | type_qualifier {
		if ((*error = declaration_specifiers_type_qualifier_callback(&$$, $1, NULL)))
			YYABORT;
	} | type_qualifier declaration_specifiers {
		if ((*error = declaration_specifiers_type_qualifier_callback(&$$, $1, $2)))
			YYABORT;
	};

init_declarator_list
	: init_declarator {
		if ((*error = init_declarator_ll_head_callback(&$$, $1)))
			YYABORT;
	} | init_declarator_list ',' init_declarator {
		if ((*error = init_declarator_ll_append_callback(&$$, $1, $3)))
			YYABORT;
	};

init_declarator
	: declarator {
		if ((*error = init_declarator_just_declarator_callback(&$$, $1)))
			YYABORT;
	} | declarator '=' initializer {
		if ((*error = init_declarator_declarator_and_initializer_callback(&$$, $1, $3)))
			YYABORT;
	};

// this is an enum:
storage_class_specifier
	: TYPEDEF { $$ = sc_typedef; }
	| EXTERN { $$ = sc_extern; }
	| STATIC { $$ = sc_static; }
	| AUTO { $$ = sc_auto; }
	| REGISTER { $$ = sc_register; }
	;

// returns `struct type*`:
type_specifier
	: VOID { $$ = type_specifier_void_callback(types); }
	| CHAR { $$ = type_specifier_char_callback(types); }
	| SHORT { $$ = type_specifier_short_callback(types); }
	| INT { $$ = type_specifier_int_callback(types); }
	| LONG { $$ = type_specifier_long_callback(types); }
	| FLOAT { $$ = type_specifier_float_callback(types); }
	| DOUBLE { $$ = type_specifier_double_callback(types); }
	| SIGNED { $$ = type_specifier_signed_callback(types); }
	| UNSIGNED { $$ = type_specifier_unsigned_callback(types); }
	| struct_or_union_specifier { $$ = $1; }
	| enum_specifier { $$ = $1; }
	| TYPE_NAME { $$ = $1; }
	;

// return `struct struct_type*`:
struct_or_union_specifier
	:   struct_or_union IDENTIFIER '{' struct_declaration_list '}' {
		if ((*error = struct_or_union_specifier_declaration_list_callback(&$$, $1, $2, $4, scope)))
			YYABORT;
	} | struct_or_union            '{' struct_declaration_list '}' {
		if ((*error = struct_or_union_specifier_declaration_list_callback(&$$, $1, NULL, $3, scope)))
			YYABORT;
	} | struct_or_union IDENTIFIER                                 {
		if ((*error = struct_or_union_specifier_just_identifier_callback(&$$, $1, $2, scope)))
			YYABORT;
	} ;

struct_or_union
	: STRUCT { $$ = true; }
	| UNION { $$ = false; }
	;

// returns a list of AST struct-fields:
struct_declaration_list
	: struct_declaration {
		$$ = $1;
	} | struct_declaration_list struct_declaration {
		if ((*error = struct_declaration_list_merge_callback(&$$, $1, $2)))
			YYABORT;
	} ;

// returns a list of AST struct-fields:
struct_declaration
	: specifier_qualifier_list struct_declarator_list ';' {
		if ((*error = struct_declaration_declaration_callback(&$$, $1, $2)))
			YYABORT;
	} ;

// returns `struct specifier_qualifier_list*`:
specifier_qualifier_list
	: type_specifier specifier_qualifier_list {
		if ((*error = specifier_qualifier_list_prepend_specifier(&$$, $1, $2, types)))
			YYABORT;
	} | type_specifier {
		if ((*error = specifier_qualifier_list_head_specifier(&$$, $1, types)))
			YYABORT;
	} | type_qualifier specifier_qualifier_list {
		TODO;
		if ((*error = specifier_qualifier_list_prepend_qualifier(&$$, $1, $2)))
			YYABORT;
	} | type_qualifier {
		TODO;
		if ((*error = specifier_qualifier_list_head_qualifier(&$$, $1)))
			YYABORT;
	} ;

// returns `struct struct_declarator_ll*`:
struct_declarator_list
	: struct_declarator {
		if ((*error = struct_declarator_list_head_callback(&$$, $1)))
			YYABORT;
	} | struct_declarator_list ',' struct_declarator {
		TODO;
		if ((*error = struct_declarator_list_append_callback(&$$, $1, $3)))
			YYABORT;
	} ;

// returns `struct struct_declarator*`:
struct_declarator
	: declarator {
		if ((*error = struct_declarator_declarator(&$$, $1)))
			YYABORT;
	} | ':' constant_expression {
		TODO;
		if ((*error = struct_declarator_bitfield(&$$, NULL, $2)))
			YYABORT;
	} | declarator ':' constant_expression {
		TODO;
		if ((*error = struct_declarator_declarator_and_bitfield(&$$, $1, $3)))
			YYABORT;
	} ;

enum_specifier
	: ENUM '{' enumerator_list '}' {
		if ((*error = enum_specifier_just_list(&$$, NULL, $3)))
			YYABORT;
	} | ENUM IDENTIFIER '{' enumerator_list '}' {
		if ((*error = enum_specifier_identifier_and_list(&$$, $2, $4)))
			YYABORT;
	} | ENUM IDENTIFIER {
		if ((*error = enum_specifier_just_identifier(&$$, $2, NULL)))
			YYABORT;
	} ;

enumerator_list
	: enumerator {
		if ((*error = enumerator_list_head_callback(&$$, $1)))
			YYABORT;
	} | enumerator_list ',' enumerator {
		if ((*error = enumerator_list_append_callback(&$$, $1, $3)))
			YYABORT;
	} ;

enumerator
	: IDENTIFIER {
		if ((*error = enumerator_just_identifier_callback(&$$, $1, NULL)))
			YYABORT;
	} | IDENTIFIER '=' constant_expression {
		if ((*error = enumerator_identifier_and_expression_callback(&$$, $1, $3)))
			YYABORT;
	} ;

// returns enum:
type_qualifier
	: CONST { $$ = tq_constant; }
	| VOLATILE { $$ = tq_volatile; }
	;

declarator
	: pointer direct_declarator {
		if ((*error = declarator_pointer_callback(&$$, $1, $2)))
			YYABORT;
	} | direct_declarator {
		$$ = $1;
	} ;

direct_declarator
	: IDENTIFIER {
		if ((*error = direct_declarator_identifier_callback(&$$, $1)))
			YYABORT;
	} | '(' declarator ')' {
		$$ = $2;
	} | direct_declarator '[' constant_expression ']' {
		if ((*error = direct_declarator_array_callback(&$$, $1, $3)))
			YYABORT;
	} | direct_declarator '[' ']' {
		// can only be the outer-most brackets
		if ((*error = direct_declarator_sizeless_array_callback(&$$, $1)))
			YYABORT;
	} | direct_declarator '(' parameter_type_list ')' {
		// parameter types and names
		if ((*error = direct_declarator_parameter_list_callback(&$$, $1, $3)))
			YYABORT;
	} | direct_declarator '(' identifier_list ')' {
		// just the parameter names are given now,
		// types show up later
		if ((*error = direct_declarator_identifier_list_callback(&$$, $1, $3)))
			YYABORT;
	} | direct_declarator '(' ')' {
		if ((*error = direct_declarator_function_callback(&$$, $1)))
			YYABORT;
	};

pointer
	: '*' {
		if ((*error = pointer_pointer_callback(&$$, NULL)))
			YYABORT;
	} | '*' type_qualifier_list         {
		if ((*error = pointer_with_qualifiers_callback(&$$, $2, NULL)))
			YYABORT;
	} | '*'                     pointer {
		if ((*error = pointer_pointer_callback(&$$, $2)))
			YYABORT;
	} | '*' type_qualifier_list pointer {
		if ((*error = pointer_with_qualifiers_callback(&$$, $2, $3)))
			YYABORT;
	} ;

type_qualifier_list
	: type_qualifier {
		if ((*error = type_qualifier_list_head_callback(&$$, $1)))
			YYABORT;
	} | type_qualifier_list type_qualifier {
		if ((*error = type_qualifier_list_append_callback(&$$, $1, $2)))
			YYABORT;
	} ;

parameter_type_list
	: parameter_list {
		$$ = $1;
	} | parameter_list ',' ELLIPSIS {
		parameter_type_list_ellipsis(&$$, $1);
	};

parameter_list
	: parameter_declaration {
		if ((*error = parameter_list_head_callback(&$$, $1)))
			YYABORT;
	} | parameter_list ',' parameter_declaration {
		if ((*error = parameter_list_append_callback(&$$, $1, $3)))
			YYABORT;
	};

parameter_declaration
	: declaration_specifiers declarator {
		if ((*error = parameter_declaration_declarator_callback(&$$, $1, $2)))
			YYABORT;
	} | declaration_specifiers abstract_declarator {
		if ((*error = parameter_declaration_abstract_declarator_callback(&$$, $1, $2)))
			YYABORT;
	} | declaration_specifiers {
		if ((*error = parameter_declaration_just_specifiers_callback(&$$, $1)))
			YYABORT;
	};

identifier_list
	: IDENTIFIER {
		if ((*error = identifier_list_head_callback(&$$, $1)))
			YYABORT;
	} | identifier_list ',' IDENTIFIER {
		if ((*error = identifier_list_append_callback(&$$, $1, $3)))
			YYABORT;
	} ;

type_name
	: specifier_qualifier_list {
		if ((*error = type_name_just_qualifier_list(&$$, $1)))
			YYABORT;
	} | specifier_qualifier_list abstract_declarator {
		if ((*error = type_name_qualifier_list_and_abstract_declarator(&$$, $1, $2)))
			YYABORT;
	} ;

abstract_declarator
	: pointer {
		if ((*error = abstract_declarator_pointer_callback(&$$, $1, NULL)))
			YYABORT;
	} | direct_abstract_declarator {
		$$ = $1;
	} | pointer direct_abstract_declarator {
		if ((*error = abstract_declarator_pointer_callback(&$$, $1, $2)))
			YYABORT;
	} ;

direct_abstract_declarator
	: '(' abstract_declarator ')' {
		$$ = $2;
	} | '[' ']' {
		if ((*error = direct_abstract_declarator_sizeless_array(&$$)))
			YYABORT;
	} | '[' constant_expression ']' {
		if ((*error = direct_abstract_declarator_array(&$$, $2)))
			YYABORT;
	} | direct_abstract_declarator '[' ']' {
		if ((*error = direct_abstract_declarator_sizeless_array(&$$, $1)))
			YYABORT;
	} | direct_abstract_declarator '[' constant_expression ']' {
		if ((*error = direct_abstract_declarator_array(&$$, $1, $3)))
			YYABORT;
	} | '(' ')' {
		if ((*error = direct_abstract_declarator_empty_function(&$$, NULL)))
			YYABORT;
	} | '(' parameter_type_list ')' {
		if ((*error = direct_abstract_declarator_function(&$$, NULL, $2)))
			YYABORT;
	} | direct_abstract_declarator '(' ')' {
		if ((*error = direct_abstract_declarator_empty_function(&$$, $1)))
			YYABORT;
	} | direct_abstract_declarator '(' parameter_type_list ')' {
		if ((*error = direct_abstract_declarator_function(&$$, $1, $3)))
			YYABORT;
	} ;

initializer
	: assignment_expression {
		if ((*error = initializer_expression_callback(&$$, $1)))
			YYABORT;
	} | '{' initializer_list '}' {
		if ((*error = initializer_initializer_list_callback(&$$, $2)))
			YYABORT;
	} | '{' initializer_list ',' '}' {
		if ((*error = initializer_initializer_list_callback(&$$, $2)))
			YYABORT;
	};

initializer_list
	: initializer {
		if ((*error = initializer_list_head_callback(&$$, $1)))
			YYABORT;
	} | initializer_list ',' initializer {
		if ((*error = initializer_list_append_callback(&$$, $1, $3)))
			YYABORT;
	} ;

statement
	: labeled_statement { $$ = $1; }
	| compound_statement { $$ = (struct statement*) $1; }
	| expression_statement { $$ = $1; }
	| selection_statement { $$ = $1; }
	| iteration_statement { $$ = $1; }
	| jump_statement { $$ = $1; }
	;

labeled_statement
	: IDENTIFIER ':' statement {
		if ((*error = labeled_statement_label_callback(&$$, $1, $3)))
			YYABORT;
	} | CASE constant_expression ':' statement {
		if ((*error = labeled_statement_case_callback(&$$, $2, $4)))
			YYABORT;
	} | DEFAULT ':' statement {
		if ((*error = labeled_statement_default_callback(&$$, $3)))
			YYABORT;
	} ;

optional_declaration_list
	: %empty {
		$$ = NULL;
	} | declaration_list {
		$$ = $1;
	};

optional_statement_list
	: %empty {
		$$ = NULL;
	} | statement_list {
		$$ = $1;
	};

compound_statement
	: '{' <line> {
			$$ = *line;
			if ((*error = compound_statement_open_callback(scope)))
				YYABORT;
		} optional_declaration_list optional_statement_list {
			compound_statement_close_callback(scope);
		} '}' {
			if ((*error = compound_statement_statements_callback(&$$, $2, $3, $4)))
				YYABORT;
		};
	;

declaration_list
	: declaration {
		$$ = $1;
	} | declaration_list declaration {
		declaration_list_merge_callback(&$$, $1, $2);
	};

statement_list
	: statement {
		if ((*error = statement_list_head_callback(&$$, $1)))
			YYABORT;
	} | statement_list statement {
		if ((*error = statement_list_append_callback(&$$, $1, $2)))
			YYABORT;
	};

expression_statement
	: ';' {
		$$ = NULL;
	} | expression <line> { $$ = *line; } ';' {
		if ((*error = expression_statement_expression_callback(&$$, $2, $1)))
			YYABORT;
	};

selection_statement
	: IF '(' expression ')' statement %prec "then" {
		if ((*error = selection_statement_if_callback(&$$, $3, $5, NULL, types)))
			YYABORT;
	} | IF '(' expression ')' statement ELSE statement {
		if ((*error = selection_statement_if_callback(&$$, $3, $5, $7, types)))
			YYABORT;
	} | SWITCH '(' expression ')' statement {
		if ((*error = selection_statement_switch_callback(&$$, $3, $5)))
			YYABORT;
	};

iteration_statement
	: WHILE '(' expression ')' statement {
		if ((*error = iteration_statement_while_callback(&$$, $3, $5, types)))
			YYABORT;
	} | DO statement WHILE '(' expression ')' ';' {
		if ((*error = iteration_statement_dowhile_callback(&$$, $2, $5)))
			YYABORT;
	} | FOR '(' expression_statement expression_statement ')' statement {
		if ((*error = iteration_statement_for_callback(&$$, $3, $4, NULL, $6)))
			YYABORT;
	} | FOR '(' expression_statement expression_statement expression ')' statement {
		if ((*error = iteration_statement_for_callback(&$$, $3, $4, $5, $7)))
			YYABORT;
	} ;

jump_statement
	: GOTO IDENTIFIER ';' {
		if ((*error = jump_statement_goto_callback(&$$, $2)))
			YYABORT;
	} | CONTINUE ';' {
		if ((*error = jump_statement_continue_callback(&$$)))
			YYABORT;
	} | BREAK ';' {
		if ((*error = jump_statement_break_callback(&$$)))
			YYABORT;
	} | RETURN <line> {$$ = *line; } ';' {
		if ((*error = jump_statement_return_callback(&$$, $2, NULL, NULL, NULL, funcname)))
			YYABORT;
	} | RETURN <line> {$$ = *line; } expression ';' {
		if ((*error = jump_statement_return_callback(&$$, $2, rettype, $3, types, funcname)))
			YYABORT;
	};

start: translation_unit {
		HERE;
	};

translation_unit
	: external_declaration {
		HERE;
	} | translation_unit external_declaration {
		HERE;
	};

external_declaration
	: function_definition {
		if ((*error = external_declaration_function_callback($1, asm_writer)))
			YYABORT;
	} | declaration {
		if ((*error = external_declaration_global_callback($1)))
			YYABORT;
	};

function_definition
	: declaration_specifiers declarator <function_definition>{
		if ((*error = function_definition_prebody(&$$, $1, $2, scope, &rettype, &funcname)))
			YYABORT;
	} compound_statement {
		if ((*error = function_definition_postbody($3, scope)))
			YYABORT;
	} {
		if ((*error = function_definition_with_specifiers_and_declarator(&$$, $3, $4)))
			YYABORT;
		tfree($1), tfree($2);
	} |                       declarator                  compound_statement {
		CHECK;
		if ((*error = function_definition_with_declarator(&$$, NULL, $1, NULL, $2)))
			YYABORT;
	};

%%















