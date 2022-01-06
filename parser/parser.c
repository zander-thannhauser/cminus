/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* "%code top" blocks.  */
#line 61 "parser/parser.y"

	#include <memory/tfree.h>
	
	struct type* rettype;
	char* funcname;

#line 74 "parser/parser.c"




# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_PARSER_H_INCLUDED
# define YY_YY_PARSER_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 45 "parser/parser.y"

	struct types;
	struct scope;
	struct asm_writer;
	
	#include <stddef.h>
	#include <stdbool.h>
	#include <inttypes.h>
	
	#include <enums/storage_class.h>
	#include <enums/type_qualifier.h>
	
	#include <expression/assign/kind.h>
	#include <expression/unary/kind.h>

#line 136 "parser/parser.c"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    SINT_LITERAL = 259,
    UINT_LITERAL = 260,
    SLONG_LITERAL = 261,
    ULONG_LITERAL = 262,
    FLOAT_LITERAL = 263,
    DOUBLE_LITERAL = 264,
    STRING_LITERAL = 265,
    TYPE_NAME = 266,
    SIZEOF = 267,
    PTR_OP = 268,
    INC_OP = 269,
    DEC_OP = 270,
    LEFT_OP = 271,
    RIGHT_OP = 272,
    LE_OP = 273,
    GE_OP = 274,
    EQ_OP = 275,
    NE_OP = 276,
    AND_OP = 277,
    OR_OP = 278,
    MUL_ASSIGN = 279,
    DIV_ASSIGN = 280,
    MOD_ASSIGN = 281,
    ADD_ASSIGN = 282,
    SUB_ASSIGN = 283,
    LEFT_ASSIGN = 284,
    RIGHT_ASSIGN = 285,
    AND_ASSIGN = 286,
    XOR_ASSIGN = 287,
    OR_ASSIGN = 288,
    TYPEDEF = 289,
    EXTERN = 290,
    STATIC = 291,
    AUTO = 292,
    REGISTER = 293,
    CHAR = 294,
    SHORT = 295,
    INT = 296,
    LONG = 297,
    SIGNED = 298,
    UNSIGNED = 299,
    FLOAT = 300,
    DOUBLE = 301,
    CONST = 302,
    VOLATILE = 303,
    VOID = 304,
    STRUCT = 305,
    UNION = 306,
    ENUM = 307,
    ELLIPSIS = 308,
    CASE = 309,
    DEFAULT = 310,
    IF = 311,
    ELSE = 312,
    SWITCH = 313,
    WHILE = 314,
    DO = 315,
    FOR = 316,
    GOTO = 317,
    CONTINUE = 318,
    BREAK = 319,
    RETURN = 320
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 68 "parser/parser.y"

	bool boolean;
	
	  signed int  sintlit;
	unsigned int  uintlit;
	  signed long slonglit;
	unsigned long ulonglit;
	
	float floatlit;
	double doublelit;
	
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
	enum assign_expression_kind assign_expression_kind;

#line 267 "parser/parser.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (int *error, struct scope *scope, struct types *types, struct asm_writer* asm_writer, char** file, size_t *section_counter);

#endif /* !YY_YY_PARSER_PARSER_H_INCLUDED  */

/* Second part of user prologue.  */
#line 136 "parser/parser.y"


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

int yylex(int* error, struct scope *scope, char** file);


#line 454 "parser/parser.c"


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  59
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1008

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  221
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  354

#define YYUNDEFTOK  2
#define YYMAXUTOK   321


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    78,     2,     2,     2,    80,    73,     2,
      67,    68,    74,    75,    72,    76,    71,    79,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    86,    88,
      81,    87,    82,    85,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    69,     2,    70,    83,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    89,    84,    90,    77,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   359,   359,   365,   371,   374,   377,   380,   383,   389,
     395,   403,   405,   408,   414,   420,   423,   426,   429,   435,
     438,   444,   446,   449,   452,   455,   458,   467,   468,   469,
     470,   471,   472,   476,   478,   484,   486,   492,   498,   507,
     509,   515,   524,   526,   529,   535,   537,   540,   543,   546,
     552,   554,   557,   563,   565,   571,   573,   579,   581,   587,
     589,   598,   600,   606,   608,   617,   619,   628,   629,   630,
     631,   632,   633,   634,   635,   636,   637,   638,   642,   644,
     650,   655,   659,   667,   671,   675,   679,   683,   687,   694,
     697,   703,   707,   714,   715,   716,   717,   718,   723,   724,
     725,   726,   727,   728,   729,   730,   731,   732,   733,   734,
     739,   742,   745,   751,   752,   757,   759,   766,   773,   776,
     779,   783,   791,   794,   801,   804,   808,   815,   818,   821,
     827,   830,   836,   839,   846,   847,   851,   854,   859,   862,
     864,   867,   871,   875,   880,   886,   889,   892,   895,   901,
     904,   910,   912,   917,   920,   926,   929,   932,   938,   941,
     947,   950,   956,   959,   961,   967,   969,   972,   975,   978,
     981,   984,   987,   990,   996,   999,  1002,  1008,  1011,  1017,
    1018,  1019,  1020,  1021,  1022,  1026,  1029,  1032,  1038,  1040,
    1045,  1047,  1052,  1055,  1052,  1066,  1068,  1073,  1076,  1082,
    1087,  1095,  1098,  1101,  1107,  1110,  1113,  1116,  1122,  1125,
    1128,  1131,  1137,  1145,  1150,  1152,  1157,  1160,  1166,  1169,
    1166,  1176
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "SINT_LITERAL",
  "UINT_LITERAL", "SLONG_LITERAL", "ULONG_LITERAL", "FLOAT_LITERAL",
  "DOUBLE_LITERAL", "STRING_LITERAL", "TYPE_NAME", "SIZEOF", "PTR_OP",
  "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP",
  "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED",
  "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID", "STRUCT", "UNION",
  "ENUM", "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE",
  "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "\"then\"", "'('",
  "')'", "'['", "']'", "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'",
  "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='",
  "';'", "'{'", "'}'", "$accept", "primary_expression",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "cast_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "storage_class_specifier",
  "type_specifier", "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "optional_declaration_list", "optional_statement_list",
  "compound_statement", "$@1", "$@2", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "start", "translation_unit", "external_declaration",
  "function_definition", "@3", "$@4", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,    40,    41,    91,
      93,    46,    44,    38,    42,    43,    45,   126,    33,    47,
      37,    60,    62,    94,   124,    63,    58,    61,    59,   123,
     125
};
# endif

#define YYPACT_NINF (-269)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-219)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     802,  -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,
    -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,
    -269,    10,    38,    14,  -269,    19,   956,   956,  -269,    11,
    -269,   956,   -77,   120,    12,    49,   802,  -269,  -269,   -37,
      54,   -47,  -269,  -269,    14,  -269,    18,  -269,    58,  -269,
    -269,   103,   867,  -269,  -269,  -269,   852,   492,   120,  -269,
    -269,    54,   -10,   -43,  -269,  -269,  -269,  -269,    38,  -269,
     283,   -77,   867,   867,   364,  -269,    28,   867,   956,  -269,
    -269,    77,    30,   114,  -269,   111,  -269,  -269,  -269,  -269,
    -269,  -269,  -269,  -269,   618,   694,   694,   479,  -269,  -269,
    -269,  -269,  -269,  -269,  -269,  -269,   188,  -269,   707,  -269,
     102,    61,   161,   135,   147,   145,   138,   172,   218,     0,
    -269,   196,   -26,   707,    54,  -269,  -269,   171,   283,   368,
    -269,  -269,  -269,  -269,   427,  -269,  -269,  -269,   707,    76,
    -269,   191,  -269,  -269,    19,   266,   956,   752,   529,  -269,
      27,  -269,   140,  -269,   936,  -269,   276,   479,  -269,   707,
    -269,  -269,  -269,   116,   106,   214,   280,  -269,  -269,   568,
     707,   281,  -269,   707,   707,   707,   707,   707,   707,   707,
     707,   707,   707,   707,   707,   707,   707,   707,   707,   707,
     707,   707,  -269,  -269,  -269,  -269,  -269,   -22,  -269,  -269,
    -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,   707,
    -269,  -269,  -269,    28,  -269,   707,   199,   707,   208,   232,
     233,   234,   266,   241,   306,   222,   223,   359,  -269,    78,
    -269,  -269,  -269,  -269,   266,  -269,  -269,  -269,  -269,  -269,
    -269,   244,   245,  -269,   246,   140,   696,   583,  -269,  -269,
    -269,   247,  -269,   707,   894,   160,  -269,   707,  -269,  -269,
     127,  -269,   176,  -269,  -269,  -269,  -269,   102,   102,    61,
      61,   161,   161,   161,   161,   135,   135,   147,   145,   138,
     172,   218,   -30,   229,  -269,  -269,  -269,  -269,   266,   228,
     266,   707,   707,   707,   258,   375,   235,  -269,  -269,  -269,
      84,  -269,   242,  -269,  -269,  -269,  -269,  -269,   267,  -269,
     264,  -269,  -269,  -269,  -269,   707,  -269,   707,  -269,  -269,
    -269,   266,  -269,   142,   151,   156,   269,   375,  -269,  -269,
    -269,  -269,  -269,  -269,  -269,  -269,   266,   266,   266,   707,
     605,   288,  -269,  -269,   158,   266,   177,   266,   249,  -269,
     266,  -269,  -269,  -269
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   138,   109,    93,    94,    95,    96,    97,    99,   100,
     101,   102,   105,   106,   103,   104,   134,   135,    98,   113,
     114,     0,     0,   145,   217,     0,    83,    85,   107,     0,
     108,    87,     0,   137,     0,     0,   213,   214,   216,   129,
       0,     0,   149,   147,   146,    81,     0,    89,    91,    84,
      86,   112,     0,    88,   192,   221,     0,     0,   136,     1,
     215,     0,   132,     0,   130,   139,   150,   148,     0,    82,
       0,     0,     0,   119,     0,   115,     0,   121,   188,   158,
     144,   157,     0,   151,   153,     0,     2,     3,     4,     5,
       6,     7,     8,     9,     0,     0,     0,     0,   141,    27,
      28,    29,    30,    31,    32,    11,    21,    33,     0,    35,
      39,    42,    45,    50,    53,    55,    57,    59,    61,    63,
      80,     0,     0,     0,     0,   127,    90,    91,     0,    33,
      65,   174,    92,   219,     0,   118,   111,   116,     0,     0,
     122,   124,   120,   195,     0,   190,   189,     0,     0,   155,
     162,   156,   163,   142,     0,   143,     0,     0,    25,     0,
      22,    23,    78,     0,   160,     0,     0,    17,    18,     0,
       0,     0,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   140,   128,   133,   131,   177,     0,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    67,     0,
     220,   110,   125,     0,   117,     0,     2,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   199,     0,
     197,   179,   193,   180,   191,   181,   182,   183,   184,   196,
     170,     0,     0,   166,     0,   164,     0,     0,   152,   154,
     159,     0,    10,     0,     0,   162,   161,     0,    16,    13,
       0,    19,     0,    15,    36,    37,    38,    40,    41,    43,
      44,    48,    49,    46,    47,    51,    52,    54,    56,    58,
      60,    62,     0,     0,   175,    66,   123,   126,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   209,   210,   211,
       0,   200,     0,   198,   171,   165,   167,   172,     0,   168,
       0,    26,    79,    34,    14,     0,    12,     0,   176,   178,
     185,     0,   187,     0,     0,     0,     0,     0,   208,   212,
     194,   173,   169,    20,    64,   186,     0,     0,     0,     0,
       0,   201,   203,   204,     0,     0,     0,     0,     0,   206,
       0,   202,   205,   207
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -269,  -269,  -269,  -269,   -57,  -269,  -100,    21,    72,    82,
      83,   152,   159,   163,   164,   157,  -269,   -56,   -68,  -269,
     -87,  -104,   -62,     9,  -269,   284,  -269,    97,  -269,  -269,
     277,   -31,   -49,  -269,   173,  -269,   287,   252,   -19,    -5,
     -16,   -12,  -269,   -53,  -269,   216,  -269,   220,   -75,  -145,
    -121,  -269,  -125,  -269,  -269,  -269,    -6,  -269,  -269,  -269,
    -269,  -268,  -269,  -269,  -269,  -269,  -269,   352,  -269,  -269,
    -269
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   105,   106,   260,   129,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   130,   162,   209,
     229,   121,    24,    81,    46,    47,    26,    27,    28,    29,
      74,    75,    76,   139,   140,    30,    63,    64,    31,    32,
      33,    34,    44,   241,    83,    84,    85,   165,   242,   152,
     132,   197,   230,   231,   145,   232,   233,    78,   302,   146,
     234,   235,   236,   237,   238,    35,    36,    37,    38,    71,
     210
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     107,   120,   131,    82,    42,   245,   151,   196,   172,    25,
     163,    43,    54,    39,    51,     1,   143,    41,    58,   194,
      48,    65,     1,   190,   135,    66,    55,   327,   142,   124,
       1,     1,    67,    77,   212,    49,    50,   158,   160,   161,
      53,     1,   253,   137,   244,    25,   124,   125,   164,    59,
     283,   107,    61,    77,    77,    77,   317,    62,    77,   340,
     131,    16,    17,   127,   193,   133,   107,   120,   284,   150,
     163,   141,   163,   264,   265,   266,   149,   123,    77,    22,
       1,   107,   120,   262,   239,   191,    22,   144,    23,   256,
      68,   107,   120,    23,   147,    22,   148,   294,   153,    40,
      52,   261,    23,   137,   282,    22,    69,    45,   164,   303,
     245,   287,    23,   289,   138,    77,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,    58,   150,   176,   177,    77,   127,
     300,   285,    41,   310,   147,    70,   148,  -218,   213,    73,
     253,    23,   255,   180,   181,   144,   253,   313,   107,   120,
     107,   120,   319,   320,   214,   322,   301,   184,   185,    73,
      73,    73,   329,   254,    73,   148,   173,   178,   179,   155,
      23,   174,   175,   156,   252,   312,   154,    56,   253,    57,
     107,   120,    72,   308,    73,   314,   335,   267,   268,   315,
     107,   166,   167,   168,   323,   324,   325,   246,   141,   247,
     336,   341,   342,   343,   253,   131,   182,   183,   186,   337,
     349,   187,   351,   253,   338,   353,   348,   254,   253,   148,
     253,    73,    86,    87,    88,    89,    90,    91,    92,    93,
     189,    94,   255,    95,    96,   350,   316,   333,   253,   253,
     269,   270,   344,   346,    73,   169,   188,   170,    70,   171,
     107,   334,   271,   272,   273,   274,   192,   275,   276,   216,
      87,    88,    89,    90,    91,    92,    93,   215,    94,   250,
      95,    96,   257,   258,   263,   288,    86,    87,    88,    89,
      90,    91,    92,    93,   290,    94,    97,    95,    96,   291,
     292,   293,    99,   100,   101,   102,   103,   104,   295,   296,
     297,   298,   304,   305,   321,   311,   306,   326,   128,   318,
     217,   218,   219,   328,   220,   221,   222,   223,   224,   225,
     226,   227,   330,    97,   332,   331,   339,   352,   277,    99,
     100,   101,   102,   103,   104,   347,   278,   281,   122,   134,
      97,   279,   126,   280,   228,    54,    99,   100,   101,   102,
     103,   104,    86,    87,    88,    89,    90,    91,    92,    93,
     249,    94,   128,    95,    96,     2,   195,   251,    86,    87,
      88,    89,    90,    91,    92,    93,   286,    94,    60,    95,
      96,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    97,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,     2,     0,
       0,     0,    97,     0,     0,     0,     0,   299,    99,   100,
     101,   102,   103,   104,   136,   208,     0,     0,     0,     0,
       0,     0,     0,   228,     0,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       0,     0,    86,    87,    88,    89,    90,    91,    92,    93,
       2,    94,     0,    95,    96,    86,    87,    88,    89,    90,
      91,    92,    93,     0,    94,     0,    95,    96,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   211,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    86,    87,    88,    89,    90,    91,    92,    93,
       0,    94,     0,    95,    96,     0,    97,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,     0,    97,
       0,     0,    98,     0,     0,    99,   100,   101,   102,   103,
     104,    86,    87,    88,    89,    90,    91,    92,    93,     0,
      94,     0,    95,    96,     0,     0,    86,    87,    88,    89,
      90,    91,    92,    93,     0,    94,    97,    95,    96,   243,
       0,     0,    99,   100,   101,   102,   103,   104,    86,    87,
      88,    89,    90,    91,    92,    93,     0,    94,     0,    95,
      96,    86,    87,    88,    89,    90,    91,    92,    93,     0,
      94,     0,    95,    96,     0,    97,   259,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,     0,     0,     0,
      97,     0,     0,   309,     0,     0,    99,   100,   101,   102,
     103,   104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,   345,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,     0,   157,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,    86,    87,    88,
      89,    90,    91,    92,    93,     0,    94,     2,    95,    96,
      86,    87,    88,    89,    90,    91,    92,    93,     0,    94,
       0,    95,    96,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       0,   159,     0,     2,   307,     0,     0,    99,   100,   101,
     102,   103,   104,     0,    97,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,   104,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     1,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     0,   147,
     240,   148,     0,     0,     0,     0,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    79,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     0,    22,
       0,     0,     0,     0,     0,     0,    23,     0,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     2,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      80,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     2,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   254,   240,   148,     0,     0,     0,     2,    23,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   248,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21
};

static const yytype_int16 yycheck[] =
{
      57,    57,    70,    56,    23,   150,    81,   128,   108,     0,
      97,    23,    89,     3,     3,     3,    78,    22,    34,   123,
      25,    68,     3,    23,    73,    44,    32,   295,    77,    72,
       3,     3,    44,    52,   138,    26,    27,    94,    95,    96,
      31,     3,    72,    74,   148,    36,    72,    90,    97,     0,
      72,   108,    89,    72,    73,    74,    86,     3,    77,   327,
     128,    47,    48,    68,    90,    71,   123,   123,    90,    81,
     157,    76,   159,   173,   174,   175,    81,    87,    97,    67,
       3,   138,   138,   170,   146,    85,    67,    78,    74,   164,
      72,   148,   148,    74,    67,    67,    69,   222,    68,    89,
      89,   169,    74,   134,   191,    67,    88,    88,   157,   234,
     255,   215,    74,   217,    86,   134,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   150,   147,    75,    76,   157,   144,
     227,   209,   147,   247,    67,    87,    69,    89,    72,    52,
      72,    74,   164,    18,    19,   146,    72,   257,   215,   215,
     217,   217,   283,   288,    88,   290,    88,    20,    21,    72,
      73,    74,    88,    67,    77,    69,    74,    16,    17,    68,
      74,    79,    80,    72,    68,   253,    72,    67,    72,    69,
     247,   247,    89,   246,    97,    68,   321,   176,   177,    72,
     257,    13,    14,    15,   291,   292,   293,    67,   213,    69,
      68,   336,   337,   338,    72,   283,    81,    82,    73,    68,
     345,    83,   347,    72,    68,   350,    68,    67,    72,    69,
      72,   134,     3,     4,     5,     6,     7,     8,     9,    10,
      22,    12,   254,    14,    15,    68,    70,   315,    72,    72,
     178,   179,   339,   340,   157,    67,    84,    69,    87,    71,
     317,   317,   180,   181,   182,   183,    70,   184,   185,     3,
       4,     5,     6,     7,     8,     9,    10,    86,    12,     3,
      14,    15,    68,     3,     3,    86,     3,     4,     5,     6,
       7,     8,     9,    10,    86,    12,    67,    14,    15,    67,
      67,    67,    73,    74,    75,    76,    77,    78,    67,     3,
      88,    88,    68,    68,    86,    68,    70,    59,    89,    90,
      54,    55,    56,    88,    58,    59,    60,    61,    62,    63,
      64,    65,    90,    67,    70,    68,    67,    88,   186,    73,
      74,    75,    76,    77,    78,    57,   187,   190,    61,    72,
      67,   188,    68,   189,    88,    89,    73,    74,    75,    76,
      77,    78,     3,     4,     5,     6,     7,     8,     9,    10,
     154,    12,    89,    14,    15,    11,   124,   157,     3,     4,
       5,     6,     7,     8,     9,    10,   213,    12,    36,    14,
      15,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    78,    11,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    88,    73,    74,
      75,    76,    77,    78,    90,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    -1,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    -1,    14,    15,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    78,    -1,    67,
      -1,    -1,    70,    -1,    -1,    73,    74,    75,    76,    77,
      78,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    -1,    14,    15,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    67,    14,    15,    70,
      -1,    -1,    73,    74,    75,    76,    77,    78,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    -1,    14,
      15,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    -1,    14,    15,    -1,    67,    68,    -1,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    78,    -1,    -1,    -1,
      67,    -1,    -1,    70,    -1,    -1,    73,    74,    75,    76,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    73,    74,
      75,    76,    77,    78,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    78,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    11,    14,    15,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      -1,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    11,    68,    -1,    -1,    73,    74,    75,
      76,    77,    78,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      73,    74,    75,    76,    77,    78,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    11,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    -1,    11,    74,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    11,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    67,    74,   113,   114,   117,   118,   119,   120,
     126,   129,   130,   131,   132,   156,   157,   158,   159,     3,
      89,   130,   129,   132,   133,    88,   115,   116,   130,   114,
     114,     3,    89,   114,    89,   147,    67,    69,   131,     0,
     158,    89,     3,   127,   128,    68,   129,   132,    72,    88,
      87,   160,    89,   118,   121,   122,   123,   129,   148,     3,
      68,   114,   134,   135,   136,   137,     3,     4,     5,     6,
       7,     8,     9,    10,    12,    14,    15,    67,    70,    73,
      74,    75,    76,    77,    78,    92,    93,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   112,   127,    87,    72,    90,   116,   130,    89,    95,
     108,   109,   141,   147,   121,   123,    90,   122,    86,   124,
     125,   130,   123,   113,   114,   145,   150,    67,    69,   130,
     132,   139,   140,    68,    72,    68,    72,    67,    95,    67,
      95,    95,   109,   111,   123,   138,    13,    14,    15,    67,
      69,    71,    97,    74,    79,    80,    75,    76,    16,    17,
      18,    19,    81,    82,    20,    21,    73,    83,    84,    22,
      23,    85,    70,    90,   112,   128,   141,   142,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    87,   110,
     161,    90,   112,    72,    88,    86,     3,    54,    55,    56,
      58,    59,    60,    61,    62,    63,    64,    65,    88,   111,
     143,   144,   146,   147,   151,   152,   153,   154,   155,   113,
      68,   134,   139,    70,   112,   140,    67,    69,    53,   136,
       3,   138,    68,    72,    67,   132,   139,    68,     3,    68,
      94,   109,   111,     3,    97,    97,    97,    98,    98,    99,
      99,   100,   100,   100,   100,   101,   101,   102,   103,   104,
     105,   106,   111,    72,    90,   109,   125,   112,    86,   112,
      86,    67,    67,    67,   143,    67,     3,    88,    88,    88,
     111,    88,   149,   143,    68,    68,    70,    68,   134,    70,
     112,    68,   109,    97,    68,    72,    70,    86,    90,   141,
     143,    86,   143,   111,   111,   111,    59,   152,    88,    88,
      90,    68,    70,   109,   108,   143,    68,    68,    68,    67,
     152,   143,   143,   143,   111,    68,   111,    57,    68,   143,
      68,   143,    88,   143
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    91,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    93,    93,    93,    93,    93,    93,    93,    93,    94,
      94,    95,    95,    95,    95,    95,    95,    96,    96,    96,
      96,    96,    96,    97,    97,    98,    98,    98,    98,    99,
      99,    99,   100,   100,   100,   101,   101,   101,   101,   101,
     102,   102,   102,   103,   103,   104,   104,   105,   105,   106,
     106,   107,   107,   108,   108,   109,   109,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   111,   111,
     112,   113,   113,   114,   114,   114,   114,   114,   114,   115,
     115,   116,   116,   117,   117,   117,   117,   117,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     119,   119,   119,   120,   120,   121,   121,   122,   123,   123,
     123,   123,   124,   124,   125,   125,   125,   126,   126,   126,
     127,   127,   128,   128,   129,   129,   130,   130,   131,   131,
     131,   131,   131,   131,   131,   132,   132,   132,   132,   133,
     133,   134,   134,   135,   135,   136,   136,   136,   137,   137,
     138,   138,   139,   139,   139,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   141,   141,   141,   142,   142,   143,
     143,   143,   143,   143,   143,   144,   144,   144,   145,   145,
     146,   146,   148,   149,   147,   150,   150,   151,   151,   152,
     152,   153,   153,   153,   154,   154,   154,   154,   155,   155,
     155,   155,   155,   156,   157,   157,   158,   158,   160,   161,
     159,   159
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     4,     3,     4,     3,     3,     2,     2,     1,
       3,     1,     2,     2,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     3,     1,     2,     1,     2,     1,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     4,     2,     1,     1,     1,     2,     3,     2,     1,
       2,     1,     1,     3,     1,     2,     3,     4,     5,     2,
       1,     3,     1,     3,     1,     1,     2,     1,     1,     3,
       4,     3,     4,     4,     3,     1,     2,     2,     3,     1,
       2,     1,     3,     1,     3,     2,     2,     1,     1,     3,
       1,     2,     1,     1,     2,     3,     2,     3,     3,     4,
       2,     3,     3,     4,     1,     3,     4,     1,     3,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     0,     1,
       0,     1,     0,     0,     6,     1,     2,     1,     2,     1,
       2,     5,     7,     5,     5,     7,     6,     7,     3,     2,
       2,     2,     3,     1,     1,     2,     1,     1,     0,     0,
       5,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (error, scope, types, asm_writer, file, section_counter, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, error, scope, types, asm_writer, file, section_counter); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, int *error, struct scope *scope, struct types *types, struct asm_writer* asm_writer, char** file, size_t *section_counter)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  YYUSE (error);
  YYUSE (scope);
  YYUSE (types);
  YYUSE (asm_writer);
  YYUSE (file);
  YYUSE (section_counter);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, int *error, struct scope *scope, struct types *types, struct asm_writer* asm_writer, char** file, size_t *section_counter)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp, error, scope, types, asm_writer, file, section_counter);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, int *error, struct scope *scope, struct types *types, struct asm_writer* asm_writer, char** file, size_t *section_counter)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , error, scope, types, asm_writer, file, section_counter);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, error, scope, types, asm_writer, file, section_counter); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, int *error, struct scope *scope, struct types *types, struct asm_writer* asm_writer, char** file, size_t *section_counter)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (error);
  YYUSE (scope);
  YYUSE (types);
  YYUSE (asm_writer);
  YYUSE (file);
  YYUSE (section_counter);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
    case 3: /* IDENTIFIER  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).identifier)); }
#line 1862 "parser/parser.c"
        break;

    case 4: /* SINT_LITERAL  */
#line 124 "parser/parser.y"
            {  }
#line 1868 "parser/parser.c"
        break;

    case 5: /* UINT_LITERAL  */
#line 125 "parser/parser.y"
            {  }
#line 1874 "parser/parser.c"
        break;

    case 6: /* SLONG_LITERAL  */
#line 126 "parser/parser.y"
            {  }
#line 1880 "parser/parser.c"
        break;

    case 7: /* ULONG_LITERAL  */
#line 127 "parser/parser.y"
            {  }
#line 1886 "parser/parser.c"
        break;

    case 8: /* FLOAT_LITERAL  */
#line 128 "parser/parser.y"
            {  }
#line 1892 "parser/parser.c"
        break;

    case 9: /* DOUBLE_LITERAL  */
#line 129 "parser/parser.y"
            {  }
#line 1898 "parser/parser.c"
        break;

    case 10: /* STRING_LITERAL  */
#line 123 "parser/parser.y"
            { tfree(((*yyvaluep).string).data); }
#line 1904 "parser/parser.c"
        break;

    case 11: /* TYPE_NAME  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).type)); }
#line 1910 "parser/parser.c"
        break;

    case 92: /* primary_expression  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1916 "parser/parser.c"
        break;

    case 93: /* postfix_expression  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1922 "parser/parser.c"
        break;

    case 94: /* argument_expression_list  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).expression_ll)); }
#line 1928 "parser/parser.c"
        break;

    case 95: /* unary_expression  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1934 "parser/parser.c"
        break;

    case 96: /* unary_operator  */
#line 133 "parser/parser.y"
            {  }
#line 1940 "parser/parser.c"
        break;

    case 97: /* cast_expression  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1946 "parser/parser.c"
        break;

    case 98: /* multiplicative_expression  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1952 "parser/parser.c"
        break;

    case 99: /* additive_expression  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1958 "parser/parser.c"
        break;

    case 100: /* shift_expression  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1964 "parser/parser.c"
        break;

    case 101: /* relational_expression  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1970 "parser/parser.c"
        break;

    case 102: /* equality_expression  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1976 "parser/parser.c"
        break;

    case 103: /* and_expression  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1982 "parser/parser.c"
        break;

    case 104: /* exclusive_or_expression  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1988 "parser/parser.c"
        break;

    case 105: /* inclusive_or_expression  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1994 "parser/parser.c"
        break;

    case 106: /* logical_and_expression  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 2000 "parser/parser.c"
        break;

    case 107: /* logical_or_expression  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 2006 "parser/parser.c"
        break;

    case 108: /* conditional_expression  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 2012 "parser/parser.c"
        break;

    case 109: /* assignment_expression  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 2018 "parser/parser.c"
        break;

    case 110: /* assignment_operator  */
#line 134 "parser/parser.y"
            {  }
#line 2024 "parser/parser.c"
        break;

    case 111: /* expression  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 2030 "parser/parser.c"
        break;

    case 112: /* constant_expression  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 2036 "parser/parser.c"
        break;

    case 113: /* declaration  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).statement_ll)); }
#line 2042 "parser/parser.c"
        break;

    case 114: /* declaration_specifiers  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).declaration_specifiers)); }
#line 2048 "parser/parser.c"
        break;

    case 115: /* init_declarator_list  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).init_declarator_ll)); }
#line 2054 "parser/parser.c"
        break;

    case 116: /* init_declarator  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).init_declarator)); }
#line 2060 "parser/parser.c"
        break;

    case 117: /* storage_class_specifier  */
#line 131 "parser/parser.y"
            {  }
#line 2066 "parser/parser.c"
        break;

    case 118: /* type_specifier  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).type)); }
#line 2072 "parser/parser.c"
        break;

    case 119: /* struct_or_union_specifier  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).type)); }
#line 2078 "parser/parser.c"
        break;

    case 120: /* struct_or_union  */
#line 130 "parser/parser.y"
            {  }
#line 2084 "parser/parser.c"
        break;

    case 121: /* struct_declaration_list  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).struct_field_ll)); }
#line 2090 "parser/parser.c"
        break;

    case 122: /* struct_declaration  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).struct_field_ll)); }
#line 2096 "parser/parser.c"
        break;

    case 123: /* specifier_qualifier_list  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).specifier_qualifiers)); }
#line 2102 "parser/parser.c"
        break;

    case 124: /* struct_declarator_list  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).struct_declarator_ll)); }
#line 2108 "parser/parser.c"
        break;

    case 125: /* struct_declarator  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).struct_declarator)); }
#line 2114 "parser/parser.c"
        break;

    case 126: /* enum_specifier  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).type)); }
#line 2120 "parser/parser.c"
        break;

    case 127: /* enumerator_list  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).enumerator)); }
#line 2126 "parser/parser.c"
        break;

    case 128: /* enumerator  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).enumerator_entry)); }
#line 2132 "parser/parser.c"
        break;

    case 129: /* type_qualifier  */
#line 132 "parser/parser.y"
            {  }
#line 2138 "parser/parser.c"
        break;

    case 130: /* declarator  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).declarator)); }
#line 2144 "parser/parser.c"
        break;

    case 131: /* direct_declarator  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).declarator)); }
#line 2150 "parser/parser.c"
        break;

    case 132: /* pointer  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).pointer)); }
#line 2156 "parser/parser.c"
        break;

    case 133: /* type_qualifier_list  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).type_qualifier_list)); }
#line 2162 "parser/parser.c"
        break;

    case 134: /* parameter_type_list  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).parameter_ll)); }
#line 2168 "parser/parser.c"
        break;

    case 135: /* parameter_list  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).parameter_ll)); }
#line 2174 "parser/parser.c"
        break;

    case 136: /* parameter_declaration  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).parameter)); }
#line 2180 "parser/parser.c"
        break;

    case 137: /* identifier_list  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).identifier_ll)); }
#line 2186 "parser/parser.c"
        break;

    case 138: /* type_name  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).type)); }
#line 2192 "parser/parser.c"
        break;

    case 139: /* abstract_declarator  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).declarator)); }
#line 2198 "parser/parser.c"
        break;

    case 140: /* direct_abstract_declarator  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).declarator)); }
#line 2204 "parser/parser.c"
        break;

    case 141: /* initializer  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).initializer)); }
#line 2210 "parser/parser.c"
        break;

    case 142: /* initializer_list  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).initializer)); }
#line 2216 "parser/parser.c"
        break;

    case 143: /* statement  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).statement)); }
#line 2222 "parser/parser.c"
        break;

    case 144: /* labeled_statement  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).statement)); }
#line 2228 "parser/parser.c"
        break;

    case 145: /* optional_declaration_list  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).statement_ll)); }
#line 2234 "parser/parser.c"
        break;

    case 146: /* optional_statement_list  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).statement_ll)); }
#line 2240 "parser/parser.c"
        break;

    case 147: /* compound_statement  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).compound_statement)); }
#line 2246 "parser/parser.c"
        break;

    case 150: /* declaration_list  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).statement_ll)); }
#line 2252 "parser/parser.c"
        break;

    case 151: /* statement_list  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).statement_ll)); }
#line 2258 "parser/parser.c"
        break;

    case 152: /* expression_statement  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).statement)); }
#line 2264 "parser/parser.c"
        break;

    case 153: /* selection_statement  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).statement)); }
#line 2270 "parser/parser.c"
        break;

    case 154: /* iteration_statement  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).statement)); }
#line 2276 "parser/parser.c"
        break;

    case 155: /* jump_statement  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).statement)); }
#line 2282 "parser/parser.c"
        break;

    case 159: /* function_definition  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).function_definition)); }
#line 2288 "parser/parser.c"
        break;

    case 160: /* @3  */
#line 122 "parser/parser.y"
            { tfree(((*yyvaluep).function_definition)); }
#line 2294 "parser/parser.c"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (int *error, struct scope *scope, struct types *types, struct asm_writer* asm_writer, char** file, size_t *section_counter)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (error, scope, file);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 359 "parser/parser.y"
                     {
		if ((*error = primary_expression_identifier_callback(&(yyval.expression),
			(yyloc).first_line, (yyloc).first_column,
			(yyloc).last_line, (yyloc).last_column,
			scope, (yyvsp[0].identifier))))
			YYABORT;
	}
#line 2596 "parser/parser.c"
    break;

  case 3:
#line 365 "parser/parser.y"
                         {
		if ((*error = primary_expression_sinteger_callback(&(yyval.expression), 
			(yyloc).first_line, (yyloc).first_column,
			(yyloc).last_line, (yyloc).last_column,
			types, (yyvsp[0].sintlit))))
			YYABORT;
	}
#line 2608 "parser/parser.c"
    break;

  case 4:
#line 371 "parser/parser.y"
                         {
		if ((*error = primary_expression_uinteger_callback(&(yyval.expression), types, (yyvsp[0].uintlit))))
			YYABORT;
	}
#line 2617 "parser/parser.c"
    break;

  case 5:
#line 374 "parser/parser.y"
                          {
		if ((*error = primary_expression_slong_callback(&(yyval.expression), types, (yyvsp[0].slonglit))))
			YYABORT;
	}
#line 2626 "parser/parser.c"
    break;

  case 6:
#line 377 "parser/parser.y"
                          {
		if ((*error = primary_expression_ulong_callback(&(yyval.expression), types, (yyvsp[0].ulonglit))))
			YYABORT;
	}
#line 2635 "parser/parser.c"
    break;

  case 7:
#line 380 "parser/parser.y"
                          {
		if ((*error = primary_expression_float_callback(&(yyval.expression), types, (yyvsp[0].floatlit))))
			YYABORT;
	}
#line 2644 "parser/parser.c"
    break;

  case 8:
#line 383 "parser/parser.y"
                           {
		if ((*error = primary_expression_double_callback(&(yyval.expression),
			(yyloc).first_line, (yyloc).first_column,
			(yyloc).last_line, (yyloc).last_column,
			types, (yyvsp[0].doublelit))))
			YYABORT;
	}
#line 2656 "parser/parser.c"
    break;

  case 9:
#line 389 "parser/parser.y"
                           {
		if ((*error = primary_expression_string_callback(&(yyval.expression),
			(yyloc).first_line, (yyloc).first_column,
			(yyloc).last_line, (yyloc).last_column,
			(yyvsp[0].string).data, (yyvsp[0].string).strlen, types, section_counter, asm_writer)))
			YYABORT;
	}
#line 2668 "parser/parser.c"
    break;

  case 10:
#line 395 "parser/parser.y"
                               {
		if ((*error = primary_expression_parentheses_callback(&(yyval.expression),
			(yyloc).first_line, (yyloc).first_column,
			(yyloc).last_line, (yyloc).last_column, (yyvsp[-1].expression))))
			YYABORT;
	}
#line 2679 "parser/parser.c"
    break;

  case 11:
#line 403 "parser/parser.y"
                             {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 2687 "parser/parser.c"
    break;

  case 12:
#line 405 "parser/parser.y"
                                                  {
		if ((*error = postfix_expression_array_index_callback(&(yyval.expression), (yyvsp[-3].expression), (yyvsp[-1].expression), types)))
			YYABORT;
	}
#line 2696 "parser/parser.c"
    break;

  case 13:
#line 408 "parser/parser.y"
                                       {
		if ((*error = postfix_expression_empty_function_call_callback(&(yyval.expression),
			(yyloc).first_line, (yyloc).first_column,
			(yyloc).last_line, (yyloc).last_column,
			(yyvsp[-2].expression))))
			YYABORT;
	}
#line 2708 "parser/parser.c"
    break;

  case 14:
#line 414 "parser/parser.y"
                                                                {
		if ((*error = postfix_expression_function_call_callback(&(yyval.expression),
			(yyloc).first_line, (yyloc).first_column,
			(yyloc).last_line, (yyloc).last_column,
			(yyvsp[-3].expression), (yyvsp[-1].expression_ll), types)))
			YYABORT;
	}
#line 2720 "parser/parser.c"
    break;

  case 15:
#line 420 "parser/parser.y"
                                              {
		if ((*error = postfix_expression_field_access_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].identifier))))
			YYABORT;
	}
#line 2729 "parser/parser.c"
    break;

  case 16:
#line 423 "parser/parser.y"
                                                 {
		if ((*error = postfix_expression_arrow_access_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].identifier))))
			YYABORT;
	}
#line 2738 "parser/parser.c"
    break;

  case 17:
#line 426 "parser/parser.y"
                                      {
		if ((*error = postfix_expression_increment_callback(&(yyval.expression), (yyvsp[-1].expression))))
			YYABORT;
	}
#line 2747 "parser/parser.c"
    break;

  case 18:
#line 429 "parser/parser.y"
                                      {
		if ((*error = postfix_expression_decrement_callback(&(yyval.expression), (yyvsp[-1].expression))))
			YYABORT;
	}
#line 2756 "parser/parser.c"
    break;

  case 19:
#line 435 "parser/parser.y"
                                {
		if ((*error = argument_expression_list_head_callback(&(yyval.expression_ll), (yyvsp[0].expression))))
			YYABORT;
	}
#line 2765 "parser/parser.c"
    break;

  case 20:
#line 438 "parser/parser.y"
                                                               {
		if ((*error = argument_expression_list_append_callback(&(yyval.expression_ll), (yyvsp[-2].expression_ll), (yyvsp[0].expression))))
			YYABORT;
	}
#line 2774 "parser/parser.c"
    break;

  case 21:
#line 444 "parser/parser.y"
                             {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 2782 "parser/parser.c"
    break;

  case 22:
#line 446 "parser/parser.y"
                                    {
		if ((*error = unary_expression_increment_callback(&(yyval.expression), (yyvsp[0].expression))))
			YYABORT;
	}
#line 2791 "parser/parser.c"
    break;

  case 23:
#line 449 "parser/parser.y"
                                    {
		if ((*error = unary_expression_decrement_callback(&(yyval.expression), (yyvsp[0].expression))))
			YYABORT;
	}
#line 2800 "parser/parser.c"
    break;

  case 24:
#line 452 "parser/parser.y"
                                           {
		if ((*error = unary_expression_operator(&(yyval.expression), (yyvsp[-1].unary_expression_kind), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 2809 "parser/parser.c"
    break;

  case 25:
#line 455 "parser/parser.y"
                                    {
		if ((*error = unary_expression_sizeof_expression_callback(&(yyval.expression), (yyvsp[0].expression))))
			YYABORT;
	}
#line 2818 "parser/parser.c"
    break;

  case 26:
#line 458 "parser/parser.y"
                                     {
		if ((*error = unary_expression_sizeof_type_callback(&(yyval.expression), 
			(yyloc).first_line, (yyloc).first_column,
			(yyloc).last_line, (yyloc).last_column,
			(yyvsp[-1].type), types)))
			YYABORT;
	}
#line 2830 "parser/parser.c"
    break;

  case 27:
#line 467 "parser/parser.y"
              { (yyval.unary_expression_kind) = uek_address_of; }
#line 2836 "parser/parser.c"
    break;

  case 28:
#line 468 "parser/parser.y"
              { (yyval.unary_expression_kind) = uek_dereference; }
#line 2842 "parser/parser.c"
    break;

  case 29:
#line 469 "parser/parser.y"
              { (yyval.unary_expression_kind) = uek_numeric_plus; }
#line 2848 "parser/parser.c"
    break;

  case 30:
#line 470 "parser/parser.y"
              { (yyval.unary_expression_kind) = uek_numeric_negate; }
#line 2854 "parser/parser.c"
    break;

  case 31:
#line 471 "parser/parser.y"
              { (yyval.unary_expression_kind) = uek_bitwise_negate; }
#line 2860 "parser/parser.c"
    break;

  case 32:
#line 472 "parser/parser.y"
              { (yyval.unary_expression_kind) = uek_logical_negate; }
#line 2866 "parser/parser.c"
    break;

  case 33:
#line 476 "parser/parser.y"
                           {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 2874 "parser/parser.c"
    break;

  case 34:
#line 478 "parser/parser.y"
                                              {
		if ((*error = cast_expression_cast_callback(&(yyval.expression), (yyvsp[-2].type), (yyvsp[0].expression))))
			YYABORT;
	}
#line 2883 "parser/parser.c"
    break;

  case 35:
#line 484 "parser/parser.y"
                          {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 2891 "parser/parser.c"
    break;

  case 36:
#line 486 "parser/parser.y"
                                                          {
		if ((*error = multiplicative_expression_multiply_callback(&(yyval.expression),
			(yyloc).first_line, (yyloc).first_column,
			(yyloc).last_line, (yyloc).last_column,
			(yyvsp[-2].expression), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 2903 "parser/parser.c"
    break;

  case 37:
#line 492 "parser/parser.y"
                                                          {
		if ((*error = multiplicative_expression_divide_callback(&(yyval.expression),
			(yyloc).first_line, (yyloc).first_column,
			(yyloc).last_line, (yyloc).last_column,
			(yyvsp[-2].expression), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 2915 "parser/parser.c"
    break;

  case 38:
#line 498 "parser/parser.y"
                                                          {
		if ((*error = multiplicative_expression_rdivide_callback(&(yyval.expression),
			(yyloc).first_line, (yyloc).first_column,
			(yyloc).last_line, (yyloc).last_column,
			(yyvsp[-2].expression), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 2927 "parser/parser.c"
    break;

  case 39:
#line 507 "parser/parser.y"
                                    {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 2935 "parser/parser.c"
    break;

  case 40:
#line 509 "parser/parser.y"
                                                              {
		if ((*error = additive_expression_add_callback(&(yyval.expression), 
			(yyloc).first_line, (yyloc).first_column,
			(yyloc).last_line, (yyloc).last_column,
			(yyvsp[-2].expression), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 2947 "parser/parser.c"
    break;

  case 41:
#line 515 "parser/parser.y"
                                                              {
		if ((*error = additive_expression_subtract_callback(&(yyval.expression),
			(yyloc).first_line, (yyloc).first_column,
			(yyloc).last_line, (yyloc).last_column,
			(yyvsp[-2].expression), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 2959 "parser/parser.c"
    break;

  case 42:
#line 524 "parser/parser.y"
                              {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 2967 "parser/parser.c"
    break;

  case 43:
#line 526 "parser/parser.y"
                                                         {
		if ((*error = shift_expression_leftshift_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression))))
			YYABORT;
	}
#line 2976 "parser/parser.c"
    break;

  case 44:
#line 529 "parser/parser.y"
                                                          {
		if ((*error = shift_expression_rightshift_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression))))
			YYABORT;
	}
#line 2985 "parser/parser.c"
    break;

  case 45:
#line 535 "parser/parser.y"
                           {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 2993 "parser/parser.c"
    break;

  case 46:
#line 537 "parser/parser.y"
                                                       {
		if ((*error = relational_expression_less_than_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 3002 "parser/parser.c"
    break;

  case 47:
#line 540 "parser/parser.y"
                                                       {
		if ((*error = relational_expression_greater_than_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 3011 "parser/parser.c"
    break;

  case 48:
#line 543 "parser/parser.y"
                                                         {
		if ((*error = relational_expression_less_than_equal_to_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 3020 "parser/parser.c"
    break;

  case 49:
#line 546 "parser/parser.y"
                                                         {
		if ((*error = relational_expression_greater_than_equal_to_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 3029 "parser/parser.c"
    break;

  case 50:
#line 552 "parser/parser.y"
                                {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 3037 "parser/parser.c"
    break;

  case 51:
#line 554 "parser/parser.y"
                                                            {
		if ((*error = equality_expression_equal_to_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 3046 "parser/parser.c"
    break;

  case 52:
#line 557 "parser/parser.y"
                                                            {
		if ((*error = equality_expression_not_equal_to_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 3055 "parser/parser.c"
    break;

  case 53:
#line 563 "parser/parser.y"
                              {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 3063 "parser/parser.c"
    break;

  case 54:
#line 565 "parser/parser.y"
                                                   {
		if ((*error = and_expression_and_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression))))
			YYABORT;
	}
#line 3072 "parser/parser.c"
    break;

  case 55:
#line 571 "parser/parser.y"
                         {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 3080 "parser/parser.c"
    break;

  case 56:
#line 573 "parser/parser.y"
                                                       {
		if ((*error = exclusive_or_expression_xor_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression))))
			YYABORT;
	}
#line 3089 "parser/parser.c"
    break;

  case 57:
#line 579 "parser/parser.y"
                                  {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 3097 "parser/parser.c"
    break;

  case 58:
#line 581 "parser/parser.y"
                                                                {
		if ((*error = inclusive_or_expression_or_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression))))
			YYABORT;
	}
#line 3106 "parser/parser.c"
    break;

  case 59:
#line 587 "parser/parser.y"
                                  {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 3114 "parser/parser.c"
    break;

  case 60:
#line 589 "parser/parser.y"
                                                                  {
		if ((*error = logical_and_expression_and_callback(&(yyval.expression),
			(yyloc).first_line, (yyloc).first_column,
			(yyloc).last_line, (yyloc).last_column,
			(yyvsp[-2].expression), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 3126 "parser/parser.c"
    break;

  case 61:
#line 598 "parser/parser.y"
                                 {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 3134 "parser/parser.c"
    break;

  case 62:
#line 600 "parser/parser.y"
                                                               {
		if ((*error = logical_or_expression_or_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 3143 "parser/parser.c"
    break;

  case 63:
#line 606 "parser/parser.y"
                                {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 3151 "parser/parser.c"
    break;

  case 64:
#line 608 "parser/parser.y"
                                                                            {
		if ((*error = conditional_expression_ternary_callback(&(yyval.expression),
			(yyloc).first_line, (yyloc).first_column,
			(yyloc).last_line, (yyloc).last_column,
			(yyvsp[-4].expression), (yyvsp[-2].expression), (yyvsp[0].expression))))
			YYABORT;
	}
#line 3163 "parser/parser.c"
    break;

  case 65:
#line 617 "parser/parser.y"
                                 {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 3171 "parser/parser.c"
    break;

  case 66:
#line 619 "parser/parser.y"
                                                                       {
		if ((*error = assignment_expression_assignment_callback(&(yyval.expression),
			(yyloc).first_line, (yyloc).first_column,
			(yyloc).last_line, (yyloc).last_column,
			(yyvsp[-2].expression), (yyvsp[-1].assign_expression_kind), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 3183 "parser/parser.c"
    break;

  case 67:
#line 628 "parser/parser.y"
              { (yyval.assign_expression_kind) = aek_regular_assign; }
#line 3189 "parser/parser.c"
    break;

  case 68:
#line 629 "parser/parser.y"
                     { (yyval.assign_expression_kind) = aek_multiply_assign; }
#line 3195 "parser/parser.c"
    break;

  case 69:
#line 630 "parser/parser.y"
                     { (yyval.assign_expression_kind) = aek_divide_assign; }
#line 3201 "parser/parser.c"
    break;

  case 70:
#line 631 "parser/parser.y"
                     { (yyval.assign_expression_kind) = aek_rdivide_assign; }
#line 3207 "parser/parser.c"
    break;

  case 71:
#line 632 "parser/parser.y"
                     { (yyval.assign_expression_kind) = aek_add_assign; }
#line 3213 "parser/parser.c"
    break;

  case 72:
#line 633 "parser/parser.y"
                     { (yyval.assign_expression_kind) = aek_subtract_assign; }
#line 3219 "parser/parser.c"
    break;

  case 73:
#line 634 "parser/parser.y"
                      { (yyval.assign_expression_kind) = aek_leftshift_assign; }
#line 3225 "parser/parser.c"
    break;

  case 74:
#line 635 "parser/parser.y"
                       { (yyval.assign_expression_kind) = aek_rightshift_assign; }
#line 3231 "parser/parser.c"
    break;

  case 75:
#line 636 "parser/parser.y"
                     { (yyval.assign_expression_kind) = aek_bitwise_and_assign; }
#line 3237 "parser/parser.c"
    break;

  case 76:
#line 637 "parser/parser.y"
                     { (yyval.assign_expression_kind) = aek_bitwise_xor_assign; }
#line 3243 "parser/parser.c"
    break;

  case 77:
#line 638 "parser/parser.y"
                    { (yyval.assign_expression_kind) = aek_bitwise_or_assign; }
#line 3249 "parser/parser.c"
    break;

  case 78:
#line 642 "parser/parser.y"
                                {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 3257 "parser/parser.c"
    break;

  case 79:
#line 644 "parser/parser.y"
                                                 {
		if ((*error = expression_comma_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 3266 "parser/parser.c"
    break;

  case 80:
#line 650 "parser/parser.y"
                                 {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 3274 "parser/parser.c"
    break;

  case 81:
#line 655 "parser/parser.y"
                                     {
		// this could only be a struct declaration, right?
		if ((*error = declaration_just_specifiers_callback(&(yyval.statement_ll), (yyvsp[-1].declaration_specifiers))))
			YYABORT;
	}
#line 3284 "parser/parser.c"
    break;

  case 82:
#line 659 "parser/parser.y"
                                                            {
		// these two TODOs are gonna possibly push into type name.
		// is the point where the two sides that make up a type collide:
		if ((*error = declaration_specifiers_and_init_list_callback(&(yyval.statement_ll), (yyvsp[-2].declaration_specifiers), (yyvsp[-1].init_declarator_ll), scope)))
			YYABORT;
	}
#line 3295 "parser/parser.c"
    break;

  case 83:
#line 667 "parser/parser.y"
                                  {
		HERE;
		if ((*error = declaration_specifiers_storage_class_callback(&(yyval.declaration_specifiers), (yyvsp[0].storage_class), NULL)))
			YYABORT;
	}
#line 3305 "parser/parser.c"
    break;

  case 84:
#line 671 "parser/parser.y"
                                                           {
		HERE;
		if ((*error = declaration_specifiers_storage_class_callback(&(yyval.declaration_specifiers), (yyvsp[-1].storage_class), (yyvsp[0].declaration_specifiers))))
			YYABORT;
	}
#line 3315 "parser/parser.c"
    break;

  case 85:
#line 675 "parser/parser.y"
                           {
		HERE;
		if ((*error = declaration_specifiers_type_specifier_callback(&(yyval.declaration_specifiers), (yyvsp[0].type), NULL, types)))
			YYABORT;
	}
#line 3325 "parser/parser.c"
    break;

  case 86:
#line 679 "parser/parser.y"
                                                  {
		HERE;
		if ((*error = declaration_specifiers_type_specifier_callback(&(yyval.declaration_specifiers), (yyvsp[-1].type), (yyvsp[0].declaration_specifiers), types)))
			YYABORT;
	}
#line 3335 "parser/parser.c"
    break;

  case 87:
#line 683 "parser/parser.y"
                           {
		HERE;
		if ((*error = declaration_specifiers_type_qualifier_callback(&(yyval.declaration_specifiers), (yyvsp[0].type_qualifier), NULL)))
			YYABORT;
	}
#line 3345 "parser/parser.c"
    break;

  case 88:
#line 687 "parser/parser.y"
                                                  {
		HERE;
		if ((*error = declaration_specifiers_type_qualifier_callback(&(yyval.declaration_specifiers), (yyvsp[-1].type_qualifier), (yyvsp[0].declaration_specifiers))))
			YYABORT;
	}
#line 3355 "parser/parser.c"
    break;

  case 89:
#line 694 "parser/parser.y"
                          {
		if ((*error = init_declarator_ll_head_callback(&(yyval.init_declarator_ll), (yyvsp[0].init_declarator))))
			YYABORT;
	}
#line 3364 "parser/parser.c"
    break;

  case 90:
#line 697 "parser/parser.y"
                                                     {
		if ((*error = init_declarator_ll_append_callback(&(yyval.init_declarator_ll), (yyvsp[-2].init_declarator_ll), (yyvsp[0].init_declarator))))
			YYABORT;
	}
#line 3373 "parser/parser.c"
    break;

  case 91:
#line 703 "parser/parser.y"
                     {
		HERE;
		if ((*error = init_declarator_just_declarator_callback(&(yyval.init_declarator), (yyvsp[0].declarator))))
			YYABORT;
	}
#line 3383 "parser/parser.c"
    break;

  case 92:
#line 707 "parser/parser.y"
                                       {
		if ((*error = init_declarator_declarator_and_initializer_callback(&(yyval.init_declarator), (yyvsp[-2].declarator), (yyvsp[0].initializer))))
			YYABORT;
	}
#line 3392 "parser/parser.c"
    break;

  case 93:
#line 714 "parser/parser.y"
                  { (yyval.storage_class) = sc_typedef; }
#line 3398 "parser/parser.c"
    break;

  case 94:
#line 715 "parser/parser.y"
                 { (yyval.storage_class) = sc_extern; }
#line 3404 "parser/parser.c"
    break;

  case 95:
#line 716 "parser/parser.y"
                 { (yyval.storage_class) = sc_static; }
#line 3410 "parser/parser.c"
    break;

  case 96:
#line 717 "parser/parser.y"
               { (yyval.storage_class) = sc_auto; }
#line 3416 "parser/parser.c"
    break;

  case 97:
#line 718 "parser/parser.y"
                   { (yyval.storage_class) = sc_register; }
#line 3422 "parser/parser.c"
    break;

  case 98:
#line 723 "parser/parser.y"
               { (yyval.type) = type_specifier_void_callback(types); }
#line 3428 "parser/parser.c"
    break;

  case 99:
#line 724 "parser/parser.y"
               { (yyval.type) = type_specifier_char_callback(types); }
#line 3434 "parser/parser.c"
    break;

  case 100:
#line 725 "parser/parser.y"
                { (yyval.type) = type_specifier_short_callback(types); }
#line 3440 "parser/parser.c"
    break;

  case 101:
#line 726 "parser/parser.y"
              { (yyval.type) = type_specifier_int_callback(types); }
#line 3446 "parser/parser.c"
    break;

  case 102:
#line 727 "parser/parser.y"
               { (yyval.type) = type_specifier_long_callback(types); }
#line 3452 "parser/parser.c"
    break;

  case 103:
#line 728 "parser/parser.y"
                { (yyval.type) = type_specifier_float_callback(types); }
#line 3458 "parser/parser.c"
    break;

  case 104:
#line 729 "parser/parser.y"
                 { (yyval.type) = type_specifier_double_callback(types); }
#line 3464 "parser/parser.c"
    break;

  case 105:
#line 730 "parser/parser.y"
                 { (yyval.type) = type_specifier_signed_callback(types); }
#line 3470 "parser/parser.c"
    break;

  case 106:
#line 731 "parser/parser.y"
                   { (yyval.type) = type_specifier_unsigned_callback(types); }
#line 3476 "parser/parser.c"
    break;

  case 107:
#line 732 "parser/parser.y"
                                    { (yyval.type) = (yyvsp[0].type); }
#line 3482 "parser/parser.c"
    break;

  case 108:
#line 733 "parser/parser.y"
                         { (yyval.type) = (yyvsp[0].type); }
#line 3488 "parser/parser.c"
    break;

  case 109:
#line 734 "parser/parser.y"
                    { (yyval.type) = (yyvsp[0].type); }
#line 3494 "parser/parser.c"
    break;

  case 110:
#line 739 "parser/parser.y"
                                                                       {
		if ((*error = struct_or_union_specifier_declaration_list_callback(&(yyval.type), (yyvsp[-4].boolean), (yyvsp[-3].identifier), (yyvsp[-1].struct_field_ll), scope)))
			YYABORT;
	}
#line 3503 "parser/parser.c"
    break;

  case 111:
#line 742 "parser/parser.y"
                                                                       {
		if ((*error = struct_or_union_specifier_declaration_list_callback(&(yyval.type), (yyvsp[-3].boolean), NULL, (yyvsp[-1].struct_field_ll), scope)))
			YYABORT;
	}
#line 3512 "parser/parser.c"
    break;

  case 112:
#line 745 "parser/parser.y"
                                                                       {
		if ((*error = struct_or_union_specifier_just_identifier_callback(&(yyval.type), (yyvsp[-1].boolean), (yyvsp[0].identifier), scope)))
			YYABORT;
	}
#line 3521 "parser/parser.c"
    break;

  case 113:
#line 751 "parser/parser.y"
                 { (yyval.boolean) = true; }
#line 3527 "parser/parser.c"
    break;

  case 114:
#line 752 "parser/parser.y"
                { (yyval.boolean) = false; }
#line 3533 "parser/parser.c"
    break;

  case 115:
#line 757 "parser/parser.y"
                             {
		(yyval.struct_field_ll) = (yyvsp[0].struct_field_ll);
	}
#line 3541 "parser/parser.c"
    break;

  case 116:
#line 759 "parser/parser.y"
                                                       {
		if ((*error = struct_declaration_list_merge_callback(&(yyval.struct_field_ll), (yyvsp[-1].struct_field_ll), (yyvsp[0].struct_field_ll))))
			YYABORT;
	}
#line 3550 "parser/parser.c"
    break;

  case 117:
#line 766 "parser/parser.y"
                                                              {
		if ((*error = struct_declaration_declaration_callback(&(yyval.struct_field_ll), (yyvsp[-2].specifier_qualifiers), (yyvsp[-1].struct_declarator_ll))))
			YYABORT;
	}
#line 3559 "parser/parser.c"
    break;

  case 118:
#line 773 "parser/parser.y"
                                                  {
		if ((*error = specifier_qualifier_list_prepend_specifier(&(yyval.specifier_qualifiers), (yyvsp[-1].type), (yyvsp[0].specifier_qualifiers), types)))
			YYABORT;
	}
#line 3568 "parser/parser.c"
    break;

  case 119:
#line 776 "parser/parser.y"
                           {
		if ((*error = specifier_qualifier_list_head_specifier(&(yyval.specifier_qualifiers), (yyvsp[0].type), types)))
			YYABORT;
	}
#line 3577 "parser/parser.c"
    break;

  case 120:
#line 779 "parser/parser.y"
                                                    {
		TODO;
		if ((*error = specifier_qualifier_list_prepend_qualifier(&(yyval.specifier_qualifiers), (yyvsp[-1].type_qualifier), (yyvsp[0].specifier_qualifiers))))
			YYABORT;
	}
#line 3587 "parser/parser.c"
    break;

  case 121:
#line 783 "parser/parser.y"
                           {
		TODO;
		if ((*error = specifier_qualifier_list_head_qualifier(&(yyval.specifier_qualifiers), (yyvsp[0].type_qualifier))))
			YYABORT;
	}
#line 3597 "parser/parser.c"
    break;

  case 122:
#line 791 "parser/parser.y"
                            {
		if ((*error = struct_declarator_list_head_callback(&(yyval.struct_declarator_ll), (yyvsp[0].struct_declarator))))
			YYABORT;
	}
#line 3606 "parser/parser.c"
    break;

  case 123:
#line 794 "parser/parser.y"
                                                         {
		if ((*error = struct_declarator_list_append_callback(&(yyval.struct_declarator_ll), (yyvsp[-2].struct_declarator_ll), (yyvsp[0].struct_declarator))))
			YYABORT;
	}
#line 3615 "parser/parser.c"
    break;

  case 124:
#line 801 "parser/parser.y"
                     {
		if ((*error = struct_declarator_declarator(&(yyval.struct_declarator), (yyvsp[0].declarator))))
			YYABORT;
	}
#line 3624 "parser/parser.c"
    break;

  case 125:
#line 804 "parser/parser.y"
                                    {
		TODO;
		if ((*error = struct_declarator_bitfield(&(yyval.struct_declarator), NULL, (yyvsp[0].expression))))
			YYABORT;
	}
#line 3634 "parser/parser.c"
    break;

  case 126:
#line 808 "parser/parser.y"
                                               {
		TODO;
		if ((*error = struct_declarator_declarator_and_bitfield(&(yyval.struct_declarator), (yyvsp[-2].declarator), (yyvsp[0].expression))))
			YYABORT;
	}
#line 3644 "parser/parser.c"
    break;

  case 127:
#line 815 "parser/parser.y"
                                       {
		if ((*error = enum_specifier_just_list(&(yyval.type), NULL, (yyvsp[-1].enumerator))))
			YYABORT;
	}
#line 3653 "parser/parser.c"
    break;

  case 128:
#line 818 "parser/parser.y"
                                                    {
		if ((*error = enum_specifier_identifier_and_list(&(yyval.type), (yyvsp[-3].identifier), (yyvsp[-1].enumerator))))
			YYABORT;
	}
#line 3662 "parser/parser.c"
    break;

  case 129:
#line 821 "parser/parser.y"
                            {
		if ((*error = enum_specifier_just_identifier(&(yyval.type), (yyvsp[0].identifier), NULL)))
			YYABORT;
	}
#line 3671 "parser/parser.c"
    break;

  case 130:
#line 827 "parser/parser.y"
                     {
		if ((*error = enumerator_list_head_callback(&(yyval.enumerator), (yyvsp[0].enumerator_entry))))
			YYABORT;
	}
#line 3680 "parser/parser.c"
    break;

  case 131:
#line 830 "parser/parser.y"
                                           {
		if ((*error = enumerator_list_append_callback(&(yyval.enumerator), (yyvsp[-2].enumerator), (yyvsp[0].enumerator_entry))))
			YYABORT;
	}
#line 3689 "parser/parser.c"
    break;

  case 132:
#line 836 "parser/parser.y"
                     {
		if ((*error = enumerator_just_identifier_callback(&(yyval.enumerator_entry), (yyvsp[0].identifier), NULL)))
			YYABORT;
	}
#line 3698 "parser/parser.c"
    break;

  case 133:
#line 839 "parser/parser.y"
                                               {
		if ((*error = enumerator_identifier_and_expression_callback(&(yyval.enumerator_entry), (yyvsp[-2].identifier), (yyvsp[0].expression))))
			YYABORT;
	}
#line 3707 "parser/parser.c"
    break;

  case 134:
#line 846 "parser/parser.y"
                { (yyval.type_qualifier) = tq_constant; }
#line 3713 "parser/parser.c"
    break;

  case 135:
#line 847 "parser/parser.y"
                   { (yyval.type_qualifier) = tq_volatile; }
#line 3719 "parser/parser.c"
    break;

  case 136:
#line 851 "parser/parser.y"
                                    {
		if ((*error = declarator_pointer_callback(&(yyval.declarator), (yyvsp[-1].pointer), (yyvsp[0].declarator))))
			YYABORT;
	}
#line 3728 "parser/parser.c"
    break;

  case 137:
#line 854 "parser/parser.y"
                              {
		(yyval.declarator) = (yyvsp[0].declarator);
	}
#line 3736 "parser/parser.c"
    break;

  case 138:
#line 859 "parser/parser.y"
                     {
		if ((*error = direct_declarator_identifier_callback(&(yyval.declarator), (yyvsp[0].identifier))))
			YYABORT;
	}
#line 3745 "parser/parser.c"
    break;

  case 139:
#line 862 "parser/parser.y"
                               {
		(yyval.declarator) = (yyvsp[-1].declarator);
	}
#line 3753 "parser/parser.c"
    break;

  case 140:
#line 864 "parser/parser.y"
                                                          {
		if ((*error = direct_declarator_array_callback(&(yyval.declarator), (yyvsp[-3].declarator), (yyvsp[-1].expression), types)))
			YYABORT;
	}
#line 3762 "parser/parser.c"
    break;

  case 141:
#line 867 "parser/parser.y"
                                      {
		// can only be the outer-most brackets
		if ((*error = direct_declarator_sizeless_array_callback(&(yyval.declarator), (yyvsp[-2].declarator))))
			YYABORT;
	}
#line 3772 "parser/parser.c"
    break;

  case 142:
#line 871 "parser/parser.y"
                                                          {
		// parameter types and names
		if ((*error = direct_declarator_parameter_list_callback(&(yyval.declarator), (yyvsp[-3].declarator), (yyvsp[-1].parameter_ll))))
			YYABORT;
	}
#line 3782 "parser/parser.c"
    break;

  case 143:
#line 875 "parser/parser.y"
                                                      {
		// just the parameter names are given now,
		// types show up later
		if ((*error = direct_declarator_identifier_list_callback(&(yyval.declarator), (yyvsp[-3].declarator), (yyvsp[-1].identifier_ll))))
			YYABORT;
	}
#line 3793 "parser/parser.c"
    break;

  case 144:
#line 880 "parser/parser.y"
                                      {
		if ((*error = direct_declarator_function_callback(&(yyval.declarator), (yyvsp[-2].declarator))))
			YYABORT;
	}
#line 3802 "parser/parser.c"
    break;

  case 145:
#line 886 "parser/parser.y"
              {
		if ((*error = pointer_pointer_callback(&(yyval.pointer), NULL)))
			YYABORT;
	}
#line 3811 "parser/parser.c"
    break;

  case 146:
#line 889 "parser/parser.y"
                                            {
		if ((*error = pointer_with_qualifiers_callback(&(yyval.pointer), (yyvsp[0].type_qualifier_list), NULL)))
			YYABORT;
	}
#line 3820 "parser/parser.c"
    break;

  case 147:
#line 892 "parser/parser.y"
                                            {
		if ((*error = pointer_pointer_callback(&(yyval.pointer), (yyvsp[0].pointer))))
			YYABORT;
	}
#line 3829 "parser/parser.c"
    break;

  case 148:
#line 895 "parser/parser.y"
                                            {
		if ((*error = pointer_with_qualifiers_callback(&(yyval.pointer), (yyvsp[-1].type_qualifier_list), (yyvsp[0].pointer))))
			YYABORT;
	}
#line 3838 "parser/parser.c"
    break;

  case 149:
#line 901 "parser/parser.y"
                         {
		if ((*error = type_qualifier_list_head_callback(&(yyval.type_qualifier_list), (yyvsp[0].type_qualifier))))
			YYABORT;
	}
#line 3847 "parser/parser.c"
    break;

  case 150:
#line 904 "parser/parser.y"
                                               {
		if ((*error = type_qualifier_list_append_callback(&(yyval.type_qualifier_list), (yyvsp[-1].type_qualifier_list), (yyvsp[0].type_qualifier))))
			YYABORT;
	}
#line 3856 "parser/parser.c"
    break;

  case 151:
#line 910 "parser/parser.y"
                         {
		(yyval.parameter_ll) = (yyvsp[0].parameter_ll);
	}
#line 3864 "parser/parser.c"
    break;

  case 152:
#line 912 "parser/parser.y"
                                        {
		parameter_type_list_ellipsis(&(yyval.parameter_ll), (yyvsp[-2].parameter_ll));
	}
#line 3872 "parser/parser.c"
    break;

  case 153:
#line 917 "parser/parser.y"
                                {
		if ((*error = parameter_list_head_callback(&(yyval.parameter_ll), (yyvsp[0].parameter))))
			YYABORT;
	}
#line 3881 "parser/parser.c"
    break;

  case 154:
#line 920 "parser/parser.y"
                                                     {
		if ((*error = parameter_list_append_callback(&(yyval.parameter_ll), (yyvsp[-2].parameter_ll), (yyvsp[0].parameter))))
			YYABORT;
	}
#line 3890 "parser/parser.c"
    break;

  case 155:
#line 926 "parser/parser.y"
                                            {
		if ((*error = parameter_declaration_declarator_callback(&(yyval.parameter), (yyvsp[-1].declaration_specifiers), (yyvsp[0].declarator))))
			YYABORT;
	}
#line 3899 "parser/parser.c"
    break;

  case 156:
#line 929 "parser/parser.y"
                                                       {
		if ((*error = parameter_declaration_abstract_declarator_callback(&(yyval.parameter), (yyvsp[-1].declaration_specifiers), (yyvsp[0].declarator))))
			YYABORT;
	}
#line 3908 "parser/parser.c"
    break;

  case 157:
#line 932 "parser/parser.y"
                                   {
		if ((*error = parameter_declaration_just_specifiers_callback(&(yyval.parameter), (yyvsp[0].declaration_specifiers))))
			YYABORT;
	}
#line 3917 "parser/parser.c"
    break;

  case 158:
#line 938 "parser/parser.y"
                     {
		if ((*error = identifier_list_head_callback(&(yyval.identifier_ll), (yyvsp[0].identifier))))
			YYABORT;
	}
#line 3926 "parser/parser.c"
    break;

  case 159:
#line 941 "parser/parser.y"
                                           {
		if ((*error = identifier_list_append_callback(&(yyval.identifier_ll), (yyvsp[-2].identifier_ll), (yyvsp[0].identifier))))
			YYABORT;
	}
#line 3935 "parser/parser.c"
    break;

  case 160:
#line 947 "parser/parser.y"
                                   {
		if ((*error = type_name_just_qualifier_list(&(yyval.type), (yyvsp[0].specifier_qualifiers))))
			YYABORT;
	}
#line 3944 "parser/parser.c"
    break;

  case 161:
#line 950 "parser/parser.y"
                                                         {
		if ((*error = type_name_qualifier_list_and_abstract_declarator(&(yyval.type), (yyvsp[-1].specifier_qualifiers), (yyvsp[0].declarator))))
			YYABORT;
	}
#line 3953 "parser/parser.c"
    break;

  case 162:
#line 956 "parser/parser.y"
                  {
		if ((*error = abstract_declarator_pointer_callback(&(yyval.declarator), (yyvsp[0].pointer), NULL)))
			YYABORT;
	}
#line 3962 "parser/parser.c"
    break;

  case 163:
#line 959 "parser/parser.y"
                                       {
		(yyval.declarator) = (yyvsp[0].declarator);
	}
#line 3970 "parser/parser.c"
    break;

  case 164:
#line 961 "parser/parser.y"
                                               {
		if ((*error = abstract_declarator_pointer_callback(&(yyval.declarator), (yyvsp[-1].pointer), (yyvsp[0].declarator))))
			YYABORT;
	}
#line 3979 "parser/parser.c"
    break;

  case 165:
#line 967 "parser/parser.y"
                                      {
		(yyval.declarator) = (yyvsp[-1].declarator);
	}
#line 3987 "parser/parser.c"
    break;

  case 166:
#line 969 "parser/parser.y"
                    {
		if ((*error = direct_abstract_declarator_sizeless_array(&(yyval.declarator))))
			YYABORT;
	}
#line 3996 "parser/parser.c"
    break;

  case 167:
#line 972 "parser/parser.y"
                                        {
		if ((*error = direct_abstract_declarator_array(&(yyval.declarator), (yyvsp[-1].expression))))
			YYABORT;
	}
#line 4005 "parser/parser.c"
    break;

  case 168:
#line 975 "parser/parser.y"
                                               {
		if ((*error = direct_abstract_declarator_sizeless_array(&(yyval.declarator), (yyvsp[-2].declarator))))
			YYABORT;
	}
#line 4014 "parser/parser.c"
    break;

  case 169:
#line 978 "parser/parser.y"
                                                                   {
		if ((*error = direct_abstract_declarator_array(&(yyval.declarator), (yyvsp[-3].declarator), (yyvsp[-1].expression))))
			YYABORT;
	}
#line 4023 "parser/parser.c"
    break;

  case 170:
#line 981 "parser/parser.y"
                    {
		if ((*error = direct_abstract_declarator_empty_function(&(yyval.declarator), NULL)))
			YYABORT;
	}
#line 4032 "parser/parser.c"
    break;

  case 171:
#line 984 "parser/parser.y"
                                        {
		if ((*error = direct_abstract_declarator_function(&(yyval.declarator), NULL, (yyvsp[-1].parameter_ll))))
			YYABORT;
	}
#line 4041 "parser/parser.c"
    break;

  case 172:
#line 987 "parser/parser.y"
                                               {
		if ((*error = direct_abstract_declarator_empty_function(&(yyval.declarator), (yyvsp[-2].declarator))))
			YYABORT;
	}
#line 4050 "parser/parser.c"
    break;

  case 173:
#line 990 "parser/parser.y"
                                                                   {
		if ((*error = direct_abstract_declarator_function(&(yyval.declarator), (yyvsp[-3].declarator), (yyvsp[-1].parameter_ll))))
			YYABORT;
	}
#line 4059 "parser/parser.c"
    break;

  case 174:
#line 996 "parser/parser.y"
                                {
		if ((*error = initializer_expression_callback(&(yyval.initializer), (yyvsp[0].expression))))
			YYABORT;
	}
#line 4068 "parser/parser.c"
    break;

  case 175:
#line 999 "parser/parser.y"
                                     {
		if ((*error = initializer_initializer_list_callback(&(yyval.initializer), (yyvsp[-1].initializer))))
			YYABORT;
	}
#line 4077 "parser/parser.c"
    break;

  case 176:
#line 1002 "parser/parser.y"
                                         {
		if ((*error = initializer_initializer_list_callback(&(yyval.initializer), (yyvsp[-2].initializer))))
			YYABORT;
	}
#line 4086 "parser/parser.c"
    break;

  case 177:
#line 1008 "parser/parser.y"
                      {
		if ((*error = initializer_list_head_callback(&(yyval.initializer), (yyvsp[0].initializer))))
			YYABORT;
	}
#line 4095 "parser/parser.c"
    break;

  case 178:
#line 1011 "parser/parser.y"
                                             {
		if ((*error = initializer_list_append_callback(&(yyval.initializer), (yyvsp[-2].initializer), (yyvsp[0].initializer))))
			YYABORT;
	}
#line 4104 "parser/parser.c"
    break;

  case 179:
#line 1017 "parser/parser.y"
                            { (yyval.statement) = (yyvsp[0].statement); }
#line 4110 "parser/parser.c"
    break;

  case 180:
#line 1018 "parser/parser.y"
                             { (yyval.statement) = (struct statement*) (yyvsp[0].compound_statement); }
#line 4116 "parser/parser.c"
    break;

  case 181:
#line 1019 "parser/parser.y"
                               { (yyval.statement) = (yyvsp[0].statement); }
#line 4122 "parser/parser.c"
    break;

  case 182:
#line 1020 "parser/parser.y"
                              { (yyval.statement) = (yyvsp[0].statement); }
#line 4128 "parser/parser.c"
    break;

  case 183:
#line 1021 "parser/parser.y"
                              { (yyval.statement) = (yyvsp[0].statement); }
#line 4134 "parser/parser.c"
    break;

  case 184:
#line 1022 "parser/parser.y"
                         { (yyval.statement) = (yyvsp[0].statement); }
#line 4140 "parser/parser.c"
    break;

  case 185:
#line 1026 "parser/parser.y"
                                   {
		if ((*error = labeled_statement_label_callback(&(yyval.statement), (yyvsp[-2].identifier), (yyvsp[0].statement))))
			YYABORT;
	}
#line 4149 "parser/parser.c"
    break;

  case 186:
#line 1029 "parser/parser.y"
                                                   {
		if ((*error = labeled_statement_case_callback(&(yyval.statement), (yyvsp[-2].expression), (yyvsp[0].statement))))
			YYABORT;
	}
#line 4158 "parser/parser.c"
    break;

  case 187:
#line 1032 "parser/parser.y"
                                  {
		if ((*error = labeled_statement_default_callback(&(yyval.statement), (yyvsp[0].statement))))
			YYABORT;
	}
#line 4167 "parser/parser.c"
    break;

  case 188:
#line 1038 "parser/parser.y"
                 {
		(yyval.statement_ll) = NULL;
	}
#line 4175 "parser/parser.c"
    break;

  case 189:
#line 1040 "parser/parser.y"
                             {
		(yyval.statement_ll) = (yyvsp[0].statement_ll);
	}
#line 4183 "parser/parser.c"
    break;

  case 190:
#line 1045 "parser/parser.y"
                 {
		(yyval.statement_ll) = NULL;
	}
#line 4191 "parser/parser.c"
    break;

  case 191:
#line 1047 "parser/parser.y"
                           {
		(yyval.statement_ll) = (yyvsp[0].statement_ll);
	}
#line 4199 "parser/parser.c"
    break;

  case 192:
#line 1052 "parser/parser.y"
              {
		if ((*error = compound_statement_open_callback(scope)))
			YYABORT;
	}
#line 4208 "parser/parser.c"
    break;

  case 193:
#line 1055 "parser/parser.y"
                                                            {
		compound_statement_close_callback(scope);
	}
#line 4216 "parser/parser.c"
    break;

  case 194:
#line 1057 "parser/parser.y"
              {
		if ((*error = compound_statement_statements_callback(&(yyval.compound_statement),
			(yyloc).first_line, (yyloc).first_column,
			(yyloc).last_line, (yyloc).last_column,
			(yyvsp[-3].statement_ll), (yyvsp[-2].statement_ll))))
			YYABORT;
	}
#line 4228 "parser/parser.c"
    break;

  case 195:
#line 1066 "parser/parser.y"
                      {
		(yyval.statement_ll) = (yyvsp[0].statement_ll);
	}
#line 4236 "parser/parser.c"
    break;

  case 196:
#line 1068 "parser/parser.y"
                                         {
		declaration_list_merge_callback(&(yyval.statement_ll), (yyvsp[-1].statement_ll), (yyvsp[0].statement_ll));
	}
#line 4244 "parser/parser.c"
    break;

  case 197:
#line 1073 "parser/parser.y"
                    {
		if ((*error = statement_list_head_callback(&(yyval.statement_ll), (yyvsp[0].statement))))
			YYABORT;
	}
#line 4253 "parser/parser.c"
    break;

  case 198:
#line 1076 "parser/parser.y"
                                     {
		if ((*error = statement_list_append_callback(&(yyval.statement_ll), (yyvsp[-1].statement_ll), (yyvsp[0].statement))))
			YYABORT;
	}
#line 4262 "parser/parser.c"
    break;

  case 199:
#line 1082 "parser/parser.y"
              {
		if ((*error = expression_statement_expression_callback(&(yyval.statement),
			(yyloc).first_line, (yyloc).first_column,
			(yyloc).last_line, (yyloc).last_column, NULL)))
			YYABORT;
	}
#line 4273 "parser/parser.c"
    break;

  case 200:
#line 1087 "parser/parser.y"
                           {
		if ((*error = expression_statement_expression_callback(&(yyval.statement),
			(yyloc).first_line, (yyloc).first_column,
			(yyloc).last_line, (yyloc).last_column, (yyvsp[-1].expression))))
			YYABORT;
	}
#line 4284 "parser/parser.c"
    break;

  case 201:
#line 1095 "parser/parser.y"
                                                       {
		if ((*error = selection_statement_if_callback(&(yyval.statement), (yyvsp[-2].expression), (yyvsp[0].statement), NULL, types)))
			YYABORT;
	}
#line 4293 "parser/parser.c"
    break;

  case 202:
#line 1098 "parser/parser.y"
                                                           {
		if ((*error = selection_statement_if_callback(&(yyval.statement), (yyvsp[-4].expression), (yyvsp[-2].statement), (yyvsp[0].statement), types)))
			YYABORT;
	}
#line 4302 "parser/parser.c"
    break;

  case 203:
#line 1101 "parser/parser.y"
                                                {
		if ((*error = selection_statement_switch_callback(&(yyval.statement), (yyvsp[-2].expression), (yyvsp[0].statement))))
			YYABORT;
	}
#line 4311 "parser/parser.c"
    break;

  case 204:
#line 1107 "parser/parser.y"
                                             {
		if ((*error = iteration_statement_while_callback(&(yyval.statement), (yyvsp[-2].expression), (yyvsp[0].statement), types)))
			YYABORT;
	}
#line 4320 "parser/parser.c"
    break;

  case 205:
#line 1110 "parser/parser.y"
                                                      {
		if ((*error = iteration_statement_dowhile_callback(&(yyval.statement), (yyvsp[-5].statement), (yyvsp[-2].expression))))
			YYABORT;
	}
#line 4329 "parser/parser.c"
    break;

  case 206:
#line 1113 "parser/parser.y"
                                                                            {
		if ((*error = iteration_statement_for_callback(&(yyval.statement), (yyvsp[-3].statement), (yyvsp[-2].statement), NULL, (yyvsp[0].statement))))
			YYABORT;
	}
#line 4338 "parser/parser.c"
    break;

  case 207:
#line 1116 "parser/parser.y"
                                                                                       {
		if ((*error = iteration_statement_for_callback(&(yyval.statement), (yyvsp[-4].statement), (yyvsp[-3].statement), (yyvsp[-2].expression), (yyvsp[0].statement))))
			YYABORT;
	}
#line 4347 "parser/parser.c"
    break;

  case 208:
#line 1122 "parser/parser.y"
                              {
		if ((*error = jump_statement_goto_callback(&(yyval.statement), (yyvsp[-1].identifier))))
			YYABORT;
	}
#line 4356 "parser/parser.c"
    break;

  case 209:
#line 1125 "parser/parser.y"
                         {
		if ((*error = jump_statement_continue_callback(&(yyval.statement))))
			YYABORT;
	}
#line 4365 "parser/parser.c"
    break;

  case 210:
#line 1128 "parser/parser.y"
                      {
		if ((*error = jump_statement_break_callback(&(yyval.statement))))
			YYABORT;
	}
#line 4374 "parser/parser.c"
    break;

  case 211:
#line 1131 "parser/parser.y"
                       {
		if ((*error = jump_statement_return_callback(&(yyval.statement),
			(yyloc).first_line, (yyloc).first_column,
			(yyloc).last_line, (yyloc).last_column,
			NULL, NULL, NULL, funcname)))
			YYABORT;
	}
#line 4386 "parser/parser.c"
    break;

  case 212:
#line 1137 "parser/parser.y"
                                  {
		if ((*error = jump_statement_return_callback(&(yyval.statement),
			(yyloc).first_line, (yyloc).first_column,
			(yyloc).last_line, (yyloc).last_column,
			rettype, (yyvsp[-1].expression), types, funcname)))
			YYABORT;
	}
#line 4398 "parser/parser.c"
    break;

  case 213:
#line 1145 "parser/parser.y"
                        {
		HERE;
	}
#line 4406 "parser/parser.c"
    break;

  case 214:
#line 1150 "parser/parser.y"
                               {
		HERE;
	}
#line 4414 "parser/parser.c"
    break;

  case 215:
#line 1152 "parser/parser.y"
                                                  {
		HERE;
	}
#line 4422 "parser/parser.c"
    break;

  case 216:
#line 1157 "parser/parser.y"
                              {
		if ((*error = external_declaration_function_callback((yyvsp[0].function_definition), asm_writer)))
			YYABORT;
	}
#line 4431 "parser/parser.c"
    break;

  case 217:
#line 1160 "parser/parser.y"
                        {
		if ((*error = external_declaration_global_callback((yyvsp[0].statement_ll))))
			YYABORT;
	}
#line 4440 "parser/parser.c"
    break;

  case 218:
#line 1166 "parser/parser.y"
                                                                  {
		if ((*error = function_definition_prebody(&(yyval.function_definition), (yyvsp[-1].declaration_specifiers), (yyvsp[0].declarator), scope, &rettype, &funcname)))
			YYABORT;
	}
#line 4449 "parser/parser.c"
    break;

  case 219:
#line 1169 "parser/parser.y"
                             {
		if ((*error = function_definition_postbody((yyvsp[-1].function_definition), scope)))
			YYABORT;
	}
#line 4458 "parser/parser.c"
    break;

  case 220:
#line 1172 "parser/parser.y"
          {
		if ((*error = function_definition_with_specifiers_and_declarator(&(yyval.function_definition), (yyvsp[-2].function_definition), (yyvsp[-1].compound_statement))))
			YYABORT;
		tfree((yyvsp[-4].declaration_specifiers)), tfree((yyvsp[-3].declarator));
	}
#line 4468 "parser/parser.c"
    break;

  case 221:
#line 1176 "parser/parser.y"
                                                                                 {
		CHECK;
		if ((*error = function_definition_with_declarator(&(yyval.function_definition), NULL, (yyvsp[-1].declarator), NULL, (yyvsp[0].compound_statement))))
			YYABORT;
	}
#line 4478 "parser/parser.c"
    break;


#line 4482 "parser/parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (error, scope, types, asm_writer, file, section_counter, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (error, scope, types, asm_writer, file, section_counter, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, error, scope, types, asm_writer, file, section_counter);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, error, scope, types, asm_writer, file, section_counter);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (error, scope, types, asm_writer, file, section_counter, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, error, scope, types, asm_writer, file, section_counter);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp, error, scope, types, asm_writer, file, section_counter);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1182 "parser/parser.y"


























