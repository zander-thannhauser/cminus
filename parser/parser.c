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
#line 58 "parser/parser.y"

	#include <memory/tfree.h>

#line 71 "parser/parser.c"




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
#line 42 "parser/parser.y"

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

#line 133 "parser/parser.c"

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
#line 62 "parser/parser.y"

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

#line 266 "parser/parser.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (int *error, struct scope *scope, struct types *types, struct asm_writer* asm_writer, unsigned *line, size_t *string_counter);

#endif /* !YY_YY_PARSER_PARSER_H_INCLUDED  */

/* Second part of user prologue.  */
#line 133 "parser/parser.y"


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


#line 439 "parser/parser.c"


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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   995

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  74
/* YYNRULES -- Number of rules.  */
#define YYNRULES  224
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  357

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
       0,   356,   356,   359,   362,   365,   368,   371,   374,   377,
     380,   386,   388,   391,   394,   397,   400,   403,   406,   412,
     415,   421,   423,   426,   429,   432,   435,   441,   442,   443,
     444,   445,   446,   450,   452,   458,   460,   463,   466,   472,
     474,   477,   483,   485,   488,   494,   496,   499,   502,   505,
     511,   513,   516,   522,   524,   530,   532,   538,   540,   546,
     548,   554,   556,   562,   564,   570,   572,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   592,   594,
     600,   605,   609,   617,   620,   623,   626,   629,   632,   638,
     641,   647,   650,   657,   658,   659,   660,   661,   666,   667,
     668,   669,   670,   671,   672,   673,   674,   675,   676,   677,
     682,   685,   688,   694,   695,   700,   702,   709,   716,   719,
     722,   726,   734,   737,   745,   748,   752,   759,   762,   765,
     771,   774,   780,   783,   790,   791,   795,   798,   803,   806,
     808,   811,   815,   819,   824,   830,   833,   836,   839,   845,
     848,   854,   856,   861,   864,   870,   873,   876,   882,   885,
     891,   894,   900,   903,   905,   911,   913,   916,   919,   922,
     925,   928,   931,   934,   940,   943,   946,   952,   955,   961,
     962,   963,   964,   965,   966,   970,   973,   976,   982,   984,
     989,   991,   996,  1000,   996,  1009,  1011,  1016,  1019,  1025,
    1027,  1027,  1033,  1036,  1039,  1045,  1048,  1051,  1054,  1060,
    1063,  1066,  1069,  1069,  1072,  1072,  1077,  1082,  1084,  1089,
    1092,  1098,  1101,  1098,  1108
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
  "compound_statement", "@1", "$@2", "declaration_list", "statement_list",
  "expression_statement", "@3", "selection_statement",
  "iteration_statement", "jump_statement", "@4", "@5", "start",
  "translation_unit", "external_declaration", "function_definition", "@6",
  "$@7", YY_NULLPTR
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

#define YYPACT_NINF (-278)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-222)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     789,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,     5,    73,   102,  -278,    12,   943,   943,  -278,     8,
    -278,   943,   -75,    -9,    40,    21,   789,  -278,  -278,     4,
     100,     1,  -278,  -278,   102,  -278,   -46,  -278,    82,  -278,
    -278,    50,   854,  -278,  -278,  -278,   839,   479,    -9,  -278,
    -278,   100,    56,   -49,  -278,  -278,  -278,  -278,    73,  -278,
     346,   -75,   854,   854,   352,  -278,   103,   854,   943,  -278,
    -278,   132,    30,    76,  -278,   -44,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,   605,   681,   681,   466,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,  -278,   229,  -278,   694,  -278,
     128,   207,   241,    71,   264,    84,   105,   119,   203,   -11,
    -278,   157,   -42,   694,   100,  -278,  -278,   153,   346,   206,
    -278,  -278,  -278,  -278,   414,  -278,  -278,  -278,   694,    94,
    -278,   167,  -278,  -278,    12,   259,   943,   739,   516,  -278,
      43,  -278,   126,  -278,   923,  -278,   256,   466,  -278,   694,
    -278,  -278,  -278,   112,   118,   202,   269,  -278,  -278,   555,
     694,   272,  -278,   694,   694,   694,   694,   694,   694,   694,
     694,   694,   694,   694,   694,   694,   694,   694,   694,   694,
     694,   694,  -278,  -278,  -278,  -278,  -278,    66,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,   694,
    -278,  -278,  -278,   103,  -278,   694,   194,   694,   200,   230,
     232,   240,   259,   242,   305,   222,   223,   224,  -278,   244,
    -278,  -278,  -278,  -278,   259,  -278,  -278,  -278,  -278,  -278,
    -278,   257,   260,  -278,   261,   126,   683,   570,  -278,  -278,
    -278,   262,  -278,   694,   881,   145,  -278,   694,  -278,  -278,
     141,  -278,   109,  -278,  -278,  -278,  -278,   128,   128,   207,
     207,   241,   241,   241,   241,    71,    71,   264,    84,   105,
     119,   203,   -59,   214,  -278,  -278,  -278,  -278,   259,   243,
     259,   694,   694,   694,   268,   363,   250,  -278,  -278,   251,
     694,   252,   253,  -278,  -278,  -278,  -278,  -278,   273,  -278,
     274,  -278,  -278,  -278,  -278,   694,  -278,   694,  -278,  -278,
    -278,   259,  -278,   143,   177,   182,   275,   363,  -278,  -278,
      95,  -278,  -278,  -278,  -278,  -278,  -278,  -278,   259,   259,
     259,   694,   592,  -278,   288,  -278,  -278,   183,   259,   184,
     259,   258,  -278,   259,  -278,  -278,  -278
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   138,   109,    93,    94,    95,    96,    97,    99,   100,
     101,   102,   105,   106,   103,   104,   134,   135,    98,   113,
     114,     0,     0,   145,   220,     0,    83,    85,   107,     0,
     108,    87,     0,   137,     0,     0,   216,   217,   219,   129,
       0,     0,   149,   147,   146,    81,     0,    89,    91,    84,
      86,   112,     0,    88,   192,   224,     0,     0,   136,     1,
     218,     0,   132,     0,   130,   139,   150,   148,     0,    82,
       0,     0,     0,   119,     0,   115,     0,   121,   188,   158,
     144,   157,     0,   151,   153,     0,     2,     3,     4,     5,
       6,     7,     8,     9,     0,     0,     0,     0,   141,    27,
      28,    29,    30,    31,    32,    11,    21,    33,     0,    35,
      39,    42,    45,    50,    53,    55,    57,    59,    61,    63,
      80,     0,     0,     0,     0,   127,    90,    91,     0,    33,
      65,   174,    92,   222,     0,   118,   111,   116,     0,     0,
     122,   124,   120,   195,     0,   190,   189,     0,     0,   155,
     162,   156,   163,   142,     0,   143,     0,     0,    25,     0,
      22,    23,    78,     0,   160,     0,     0,    17,    18,     0,
       0,     0,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   140,   128,   133,   131,   177,     0,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    67,     0,
     223,   110,   125,     0,   117,     0,     2,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   214,   199,   200,
     197,   179,   193,   180,   191,   181,   182,   183,   184,   196,
     170,     0,     0,   166,     0,   164,     0,     0,   152,   154,
     159,     0,    10,     0,     0,   162,   161,     0,    16,    13,
       0,    19,     0,    15,    36,    37,    38,    40,    41,    43,
      44,    48,    49,    46,    47,    51,    52,    54,    56,    58,
      60,    62,     0,     0,   175,    66,   123,   126,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   210,   211,     0,
       0,     0,     0,   198,   171,   165,   167,   172,     0,   168,
       0,    26,    79,    34,    14,     0,    12,     0,   176,   178,
     185,     0,   187,     0,     0,     0,     0,     0,   209,   213,
       0,   201,   194,   173,   169,    20,    64,   186,     0,     0,
       0,     0,     0,   215,   202,   204,   205,     0,     0,     0,
       0,     0,   207,     0,   203,   206,   208
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -278,  -278,  -278,  -278,   -57,  -278,  -103,   125,   116,    96,
     121,   171,   172,   174,   175,   186,  -278,   -56,   -67,  -278,
     -95,   -43,   -45,     9,  -278,   297,  -278,   -20,  -278,  -278,
     302,   -30,   -48,  -278,   166,  -278,   319,   263,    11,    -3,
     -14,   -13,  -278,   -52,  -278,   227,  -278,   225,   -65,  -144,
    -121,  -278,  -175,  -278,  -278,  -278,   -15,  -278,  -278,  -278,
    -278,  -277,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
     347,  -278,  -278,  -278
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
     234,   235,   301,   236,   237,   238,   299,   300,    35,    36,
      37,    38,    71,   210
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     107,   120,   163,   131,    82,   172,   245,   196,    39,    25,
      43,    51,   190,   253,    54,     1,   151,    55,   327,    41,
      58,    59,    48,   124,   155,   135,    68,   317,   156,   142,
     124,    67,    73,   143,    42,    49,    50,   158,   160,   161,
      53,   125,    69,     1,   137,    25,     1,   294,   193,   164,
     342,   107,    73,    73,    73,    66,   133,    73,    56,   303,
      57,   131,   163,    77,   163,   127,   107,   120,   150,    65,
     264,   265,   266,   141,   191,   262,     1,    73,   149,    22,
     194,   107,   120,    77,    77,    77,    23,   144,    77,   180,
     181,   107,   120,    61,    40,   212,   282,    52,   153,   256,
      45,   239,   261,    62,   137,   244,     1,    22,    77,   164,
     147,   245,   148,   320,    73,   322,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   150,     1,    58,    73,   283,    72,
      22,   127,   285,   123,    41,    77,   337,    23,   154,    16,
      17,   255,   182,   183,   313,   144,   284,   186,   107,   120,
     107,   120,   319,   344,   345,   346,   213,   253,    77,    70,
      22,  -221,   287,   352,   289,   354,    23,    23,   356,   316,
     252,   253,   214,   343,   253,   254,   312,   148,   187,   138,
     107,   120,    23,   246,   308,   247,   323,   324,   325,   147,
     107,   148,   173,   188,   310,   330,    23,   174,   175,   314,
     141,   338,   254,   315,   148,   253,   131,    86,    87,    88,
      89,    90,    91,    92,    93,   189,    94,   192,    95,    96,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      70,   255,   166,   167,   168,   339,   347,   349,   335,   253,
     340,   351,   353,   215,   253,   253,   253,   178,   179,   250,
     107,   336,   216,    87,    88,    89,    90,    91,    92,    93,
     257,    94,   258,    95,    96,   263,   271,   272,   273,   274,
     288,    97,   176,   177,   184,   185,   290,    99,   100,   101,
     102,   103,   104,   208,   269,   270,   169,   291,   170,   292,
     171,   267,   268,   128,   318,   275,   276,   293,   296,   295,
     297,   298,  -212,   217,   218,   219,   253,   220,   221,   222,
     223,   224,   225,   226,   227,   304,    97,   326,   305,   321,
     311,   306,    99,   100,   101,   102,   103,   104,   328,   329,
     331,   333,   341,   332,   334,   350,   355,   228,    54,    86,
      87,    88,    89,    90,    91,    92,    93,   277,    94,   278,
      95,    96,   279,     2,   280,   126,    86,    87,    88,    89,
      90,    91,    92,    93,   134,    94,   281,    95,    96,   286,
     122,   249,   251,    60,     0,     0,     0,   195,     0,     0,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,    97,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,     2,     0,     0,     0,     0,
      97,     0,     0,     0,     0,   128,    99,   100,   101,   102,
     103,   104,   136,     0,     0,     0,     0,     0,     0,     0,
       0,   228,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,     0,    86,
      87,    88,    89,    90,    91,    92,    93,     2,    94,     0,
      95,    96,    86,    87,    88,    89,    90,    91,    92,    93,
       0,    94,     0,    95,    96,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   211,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    86,
      87,    88,    89,    90,    91,    92,    93,     0,    94,     0,
      95,    96,     0,    97,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,     0,    97,     0,     0,    98,
       0,     0,    99,   100,   101,   102,   103,   104,    86,    87,
      88,    89,    90,    91,    92,    93,     0,    94,     0,    95,
      96,     0,     0,    86,    87,    88,    89,    90,    91,    92,
      93,     0,    94,    97,    95,    96,   243,     0,     0,    99,
     100,   101,   102,   103,   104,    86,    87,    88,    89,    90,
      91,    92,    93,     0,    94,     0,    95,    96,    86,    87,
      88,    89,    90,    91,    92,    93,     0,    94,     0,    95,
      96,     0,    97,   259,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,     0,     0,     0,    97,     0,     0,
     309,     0,     0,    99,   100,   101,   102,   103,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    97,
     348,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,     0,   157,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,    86,    87,    88,    89,    90,    91,
      92,    93,     0,    94,     2,    95,    96,    86,    87,    88,
      89,    90,    91,    92,    93,     0,    94,     0,    95,    96,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,     0,   159,     0,
       2,   307,     0,     0,    99,   100,   101,   102,   103,   104,
       0,    97,     0,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     1,     0,     0,     0,     0,     0,     0,     0,
       2,     0,     0,     0,     0,     0,   147,   240,   148,     0,
       0,     0,     0,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    79,     0,     0,     0,     0,     0,     0,     0,
       2,     0,     0,     0,     0,     0,    22,     0,     0,     0,
       0,     0,     0,    23,     0,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     2,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    80,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     2,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   254,   240,
     148,     0,     0,     0,     2,    23,     0,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,   248,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21
};

static const yytype_int16 yycheck[] =
{
      57,    57,    97,    70,    56,   108,   150,   128,     3,     0,
      23,     3,    23,    72,    89,     3,    81,    32,   295,    22,
      34,     0,    25,    72,    68,    73,    72,    86,    72,    77,
      72,    44,    52,    78,    23,    26,    27,    94,    95,    96,
      31,    90,    88,     3,    74,    36,     3,   222,    90,    97,
     327,   108,    72,    73,    74,    44,    71,    77,    67,   234,
      69,   128,   157,    52,   159,    68,   123,   123,    81,    68,
     173,   174,   175,    76,    85,   170,     3,    97,    81,    67,
     123,   138,   138,    72,    73,    74,    74,    78,    77,    18,
      19,   148,   148,    89,    89,   138,   191,    89,    68,   164,
      88,   146,   169,     3,   134,   148,     3,    67,    97,   157,
      67,   255,    69,   288,   134,   290,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   147,     3,   150,   157,    72,    89,
      67,   144,   209,    87,   147,   134,   321,    74,    72,    47,
      48,   164,    81,    82,   257,   146,    90,    73,   215,   215,
     217,   217,   283,   338,   339,   340,    72,    72,   157,    87,
      67,    89,   215,   348,   217,   350,    74,    74,   353,    70,
      68,    72,    88,    88,    72,    67,   253,    69,    83,    86,
     247,   247,    74,    67,   246,    69,   291,   292,   293,    67,
     257,    69,    74,    84,   247,   300,    74,    79,    80,    68,
     213,    68,    67,    72,    69,    72,   283,     3,     4,     5,
       6,     7,     8,     9,    10,    22,    12,    70,    14,    15,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      87,   254,    13,    14,    15,    68,   341,   342,   315,    72,
      68,    68,    68,    86,    72,    72,    72,    16,    17,     3,
     317,   317,     3,     4,     5,     6,     7,     8,     9,    10,
      68,    12,     3,    14,    15,     3,   180,   181,   182,   183,
      86,    67,    75,    76,    20,    21,    86,    73,    74,    75,
      76,    77,    78,    87,   178,   179,    67,    67,    69,    67,
      71,   176,   177,    89,    90,   184,   185,    67,     3,    67,
      88,    88,    88,    54,    55,    56,    72,    58,    59,    60,
      61,    62,    63,    64,    65,    68,    67,    59,    68,    86,
      68,    70,    73,    74,    75,    76,    77,    78,    88,    88,
      88,    68,    67,    90,    70,    57,    88,    88,    89,     3,
       4,     5,     6,     7,     8,     9,    10,   186,    12,   187,
      14,    15,   188,    11,   189,    68,     3,     4,     5,     6,
       7,     8,     9,    10,    72,    12,   190,    14,    15,   213,
      61,   154,   157,    36,    -1,    -1,    -1,   124,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    73,
      74,    75,    76,    77,    78,    11,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    89,    73,    74,    75,    76,
      77,    78,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    15,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    -1,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    -1,
      14,    15,    -1,    67,    -1,    -1,    -1,    -1,    -1,    73,
      74,    75,    76,    77,    78,    -1,    67,    -1,    -1,    70,
      -1,    -1,    73,    74,    75,    76,    77,    78,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    -1,    14,
      15,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    67,    14,    15,    70,    -1,    -1,    73,
      74,    75,    76,    77,    78,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    -1,    14,    15,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    -1,    14,
      15,    -1,    67,    68,    -1,    -1,    -1,    -1,    73,    74,
      75,    76,    77,    78,    -1,    -1,    -1,    67,    -1,    -1,
      70,    -1,    -1,    73,    74,    75,    76,    77,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,
      78,    -1,    67,    -1,    -1,    -1,    -1,    -1,    73,    74,
      75,    76,    77,    78,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    11,    14,    15,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    -1,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      11,    68,    -1,    -1,    73,    74,    75,    76,    77,    78,
      -1,    67,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    78,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    11,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    -1,    11,    74,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    11,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    67,    74,   113,   114,   117,   118,   119,   120,
     126,   129,   130,   131,   132,   159,   160,   161,   162,     3,
      89,   130,   129,   132,   133,    88,   115,   116,   130,   114,
     114,     3,    89,   114,    89,   147,    67,    69,   131,     0,
     161,    89,     3,   127,   128,    68,   129,   132,    72,    88,
      87,   163,    89,   118,   121,   122,   123,   129,   148,     3,
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
     164,    90,   112,    72,    88,    86,     3,    54,    55,    56,
      58,    59,    60,    61,    62,    63,    64,    65,    88,   111,
     143,   144,   146,   147,   151,   152,   154,   155,   156,   113,
      68,   134,   139,    70,   112,   140,    67,    69,    53,   136,
       3,   138,    68,    72,    67,   132,   139,    68,     3,    68,
      94,   109,   111,     3,    97,    97,    97,    98,    98,    99,
      99,   100,   100,   100,   100,   101,   101,   102,   103,   104,
     105,   106,   111,    72,    90,   109,   125,   112,    86,   112,
      86,    67,    67,    67,   143,    67,     3,    88,    88,   157,
     158,   153,   149,   143,    68,    68,    70,    68,   134,    70,
     112,    68,   109,    97,    68,    72,    70,    86,    90,   141,
     143,    86,   143,   111,   111,   111,    59,   152,    88,    88,
     111,    88,    90,    68,    70,   109,   108,   143,    68,    68,
      68,    67,   152,    88,   143,   143,   143,   111,    68,   111,
      57,    68,   143,    68,   143,    88,   143
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
     153,   152,   154,   154,   154,   155,   155,   155,   155,   156,
     156,   156,   157,   156,   158,   156,   159,   160,   160,   161,
     161,   163,   164,   162,   162
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
       0,     3,     5,     7,     5,     5,     7,     6,     7,     3,
       2,     2,     0,     3,     0,     4,     1,     1,     2,     1,
       1,     0,     0,     5,     2
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
        yyerror (error, scope, types, asm_writer, line, string_counter, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, error, scope, types, asm_writer, line, string_counter); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, int *error, struct scope *scope, struct types *types, struct asm_writer* asm_writer, unsigned *line, size_t *string_counter)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (error);
  YYUSE (scope);
  YYUSE (types);
  YYUSE (asm_writer);
  YYUSE (line);
  YYUSE (string_counter);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, int *error, struct scope *scope, struct types *types, struct asm_writer* asm_writer, unsigned *line, size_t *string_counter)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, error, scope, types, asm_writer, line, string_counter);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule, int *error, struct scope *scope, struct types *types, struct asm_writer* asm_writer, unsigned *line, size_t *string_counter)
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
                                              , error, scope, types, asm_writer, line, string_counter);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, error, scope, types, asm_writer, line, string_counter); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, int *error, struct scope *scope, struct types *types, struct asm_writer* asm_writer, unsigned *line, size_t *string_counter)
{
  YYUSE (yyvaluep);
  YYUSE (error);
  YYUSE (scope);
  YYUSE (types);
  YYUSE (asm_writer);
  YYUSE (line);
  YYUSE (string_counter);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
    case 3: /* IDENTIFIER  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).identifier)); }
#line 1774 "parser/parser.c"
        break;

    case 4: /* SINT_LITERAL  */
#line 120 "parser/parser.y"
            {  }
#line 1780 "parser/parser.c"
        break;

    case 5: /* UINT_LITERAL  */
#line 121 "parser/parser.y"
            {  }
#line 1786 "parser/parser.c"
        break;

    case 6: /* SLONG_LITERAL  */
#line 122 "parser/parser.y"
            {  }
#line 1792 "parser/parser.c"
        break;

    case 7: /* ULONG_LITERAL  */
#line 123 "parser/parser.y"
            {  }
#line 1798 "parser/parser.c"
        break;

    case 8: /* FLOAT_LITERAL  */
#line 124 "parser/parser.y"
            {  }
#line 1804 "parser/parser.c"
        break;

    case 9: /* DOUBLE_LITERAL  */
#line 125 "parser/parser.y"
            {  }
#line 1810 "parser/parser.c"
        break;

    case 10: /* STRING_LITERAL  */
#line 119 "parser/parser.y"
            { tfree(((*yyvaluep).string).data); }
#line 1816 "parser/parser.c"
        break;

    case 11: /* TYPE_NAME  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).type)); }
#line 1822 "parser/parser.c"
        break;

    case 92: /* primary_expression  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1828 "parser/parser.c"
        break;

    case 93: /* postfix_expression  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1834 "parser/parser.c"
        break;

    case 94: /* argument_expression_list  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).expression_ll)); }
#line 1840 "parser/parser.c"
        break;

    case 95: /* unary_expression  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1846 "parser/parser.c"
        break;

    case 96: /* unary_operator  */
#line 130 "parser/parser.y"
            {  }
#line 1852 "parser/parser.c"
        break;

    case 97: /* cast_expression  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1858 "parser/parser.c"
        break;

    case 98: /* multiplicative_expression  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1864 "parser/parser.c"
        break;

    case 99: /* additive_expression  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1870 "parser/parser.c"
        break;

    case 100: /* shift_expression  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1876 "parser/parser.c"
        break;

    case 101: /* relational_expression  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1882 "parser/parser.c"
        break;

    case 102: /* equality_expression  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1888 "parser/parser.c"
        break;

    case 103: /* and_expression  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1894 "parser/parser.c"
        break;

    case 104: /* exclusive_or_expression  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1900 "parser/parser.c"
        break;

    case 105: /* inclusive_or_expression  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1906 "parser/parser.c"
        break;

    case 106: /* logical_and_expression  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1912 "parser/parser.c"
        break;

    case 107: /* logical_or_expression  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1918 "parser/parser.c"
        break;

    case 108: /* conditional_expression  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1924 "parser/parser.c"
        break;

    case 109: /* assignment_expression  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1930 "parser/parser.c"
        break;

    case 110: /* assignment_operator  */
#line 131 "parser/parser.y"
            {  }
#line 1936 "parser/parser.c"
        break;

    case 111: /* expression  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1942 "parser/parser.c"
        break;

    case 112: /* constant_expression  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).expression)); }
#line 1948 "parser/parser.c"
        break;

    case 113: /* declaration  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).statement_ll)); }
#line 1954 "parser/parser.c"
        break;

    case 114: /* declaration_specifiers  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).declaration_specifiers)); }
#line 1960 "parser/parser.c"
        break;

    case 115: /* init_declarator_list  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).init_declarator_ll)); }
#line 1966 "parser/parser.c"
        break;

    case 116: /* init_declarator  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).init_declarator)); }
#line 1972 "parser/parser.c"
        break;

    case 117: /* storage_class_specifier  */
#line 128 "parser/parser.y"
            {  }
#line 1978 "parser/parser.c"
        break;

    case 118: /* type_specifier  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).type)); }
#line 1984 "parser/parser.c"
        break;

    case 119: /* struct_or_union_specifier  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).type)); }
#line 1990 "parser/parser.c"
        break;

    case 120: /* struct_or_union  */
#line 126 "parser/parser.y"
            {  }
#line 1996 "parser/parser.c"
        break;

    case 121: /* struct_declaration_list  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).struct_field_ll)); }
#line 2002 "parser/parser.c"
        break;

    case 122: /* struct_declaration  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).struct_field_ll)); }
#line 2008 "parser/parser.c"
        break;

    case 123: /* specifier_qualifier_list  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).specifier_qualifiers)); }
#line 2014 "parser/parser.c"
        break;

    case 124: /* struct_declarator_list  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).struct_declarator_ll)); }
#line 2020 "parser/parser.c"
        break;

    case 125: /* struct_declarator  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).struct_declarator)); }
#line 2026 "parser/parser.c"
        break;

    case 126: /* enum_specifier  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).type)); }
#line 2032 "parser/parser.c"
        break;

    case 127: /* enumerator_list  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).enumerator)); }
#line 2038 "parser/parser.c"
        break;

    case 128: /* enumerator  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).enumerator_entry)); }
#line 2044 "parser/parser.c"
        break;

    case 129: /* type_qualifier  */
#line 129 "parser/parser.y"
            {  }
#line 2050 "parser/parser.c"
        break;

    case 130: /* declarator  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).declarator)); }
#line 2056 "parser/parser.c"
        break;

    case 131: /* direct_declarator  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).declarator)); }
#line 2062 "parser/parser.c"
        break;

    case 132: /* pointer  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).pointer)); }
#line 2068 "parser/parser.c"
        break;

    case 133: /* type_qualifier_list  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).type_qualifier_list)); }
#line 2074 "parser/parser.c"
        break;

    case 134: /* parameter_type_list  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).parameter_ll)); }
#line 2080 "parser/parser.c"
        break;

    case 135: /* parameter_list  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).parameter_ll)); }
#line 2086 "parser/parser.c"
        break;

    case 136: /* parameter_declaration  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).parameter)); }
#line 2092 "parser/parser.c"
        break;

    case 137: /* identifier_list  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).identifier_ll)); }
#line 2098 "parser/parser.c"
        break;

    case 138: /* type_name  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).type)); }
#line 2104 "parser/parser.c"
        break;

    case 139: /* abstract_declarator  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).declarator)); }
#line 2110 "parser/parser.c"
        break;

    case 140: /* direct_abstract_declarator  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).declarator)); }
#line 2116 "parser/parser.c"
        break;

    case 141: /* initializer  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).initializer)); }
#line 2122 "parser/parser.c"
        break;

    case 142: /* initializer_list  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).initializer)); }
#line 2128 "parser/parser.c"
        break;

    case 143: /* statement  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).statement)); }
#line 2134 "parser/parser.c"
        break;

    case 144: /* labeled_statement  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).statement)); }
#line 2140 "parser/parser.c"
        break;

    case 145: /* optional_declaration_list  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).statement_ll)); }
#line 2146 "parser/parser.c"
        break;

    case 146: /* optional_statement_list  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).statement_ll)); }
#line 2152 "parser/parser.c"
        break;

    case 147: /* compound_statement  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).compound_statement)); }
#line 2158 "parser/parser.c"
        break;

    case 148: /* @1  */
#line 127 "parser/parser.y"
            {  }
#line 2164 "parser/parser.c"
        break;

    case 150: /* declaration_list  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).statement_ll)); }
#line 2170 "parser/parser.c"
        break;

    case 151: /* statement_list  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).statement_ll)); }
#line 2176 "parser/parser.c"
        break;

    case 152: /* expression_statement  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).statement)); }
#line 2182 "parser/parser.c"
        break;

    case 153: /* @3  */
#line 127 "parser/parser.y"
            {  }
#line 2188 "parser/parser.c"
        break;

    case 154: /* selection_statement  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).statement)); }
#line 2194 "parser/parser.c"
        break;

    case 155: /* iteration_statement  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).statement)); }
#line 2200 "parser/parser.c"
        break;

    case 156: /* jump_statement  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).statement)); }
#line 2206 "parser/parser.c"
        break;

    case 157: /* @4  */
#line 127 "parser/parser.y"
            {  }
#line 2212 "parser/parser.c"
        break;

    case 158: /* @5  */
#line 127 "parser/parser.y"
            {  }
#line 2218 "parser/parser.c"
        break;

    case 162: /* function_definition  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).function_definition)); }
#line 2224 "parser/parser.c"
        break;

    case 163: /* @6  */
#line 118 "parser/parser.y"
            { tfree(((*yyvaluep).function_definition)); }
#line 2230 "parser/parser.c"
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
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (int *error, struct scope *scope, struct types *types, struct asm_writer* asm_writer, unsigned *line, size_t *string_counter)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
      yychar = yylex (scope, line);
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 356 "parser/parser.y"
                     {
		if ((*error = primary_expression_identifier_callback(&(yyval.expression), scope, (yyvsp[0].identifier))))
			YYABORT;
	}
#line 2503 "parser/parser.c"
    break;

  case 3:
#line 359 "parser/parser.y"
                         {
		if ((*error = primary_expression_sinteger_callback(&(yyval.expression), types, (yyvsp[0].sintegerlit))))
			YYABORT;
	}
#line 2512 "parser/parser.c"
    break;

  case 4:
#line 362 "parser/parser.y"
                         {
		if ((*error = primary_expression_uinteger_callback(&(yyval.expression), types, (yyvsp[0].uintegerlit))))
			YYABORT;
	}
#line 2521 "parser/parser.c"
    break;

  case 5:
#line 365 "parser/parser.y"
                          {
		if ((*error = primary_expression_slong_callback(&(yyval.expression), types, (yyvsp[0].slonglit))))
			YYABORT;
	}
#line 2530 "parser/parser.c"
    break;

  case 6:
#line 368 "parser/parser.y"
                          {
		if ((*error = primary_expression_ulong_callback(&(yyval.expression), types, (yyvsp[0].ulonglit))))
			YYABORT;
	}
#line 2539 "parser/parser.c"
    break;

  case 7:
#line 371 "parser/parser.y"
                          {
		if ((*error = primary_expression_float_callback(&(yyval.expression), types, (yyvsp[0].floatlit))))
			YYABORT;
	}
#line 2548 "parser/parser.c"
    break;

  case 8:
#line 374 "parser/parser.y"
                           {
		if ((*error = primary_expression_double_callback(&(yyval.expression), types, (yyvsp[0].doublelit))))
			YYABORT;
	}
#line 2557 "parser/parser.c"
    break;

  case 9:
#line 377 "parser/parser.y"
                           {
		if ((*error = primary_expression_string_callback(&(yyval.expression), (yyvsp[0].string).data, (yyvsp[0].string).strlen, types, string_counter, asm_writer)))
			YYABORT;
	}
#line 2566 "parser/parser.c"
    break;

  case 10:
#line 380 "parser/parser.y"
                               {
		if ((*error = primary_expression_parentheses_callback(&(yyval.expression), (yyvsp[-1].expression))))
			YYABORT;
	}
#line 2575 "parser/parser.c"
    break;

  case 11:
#line 386 "parser/parser.y"
                             {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 2583 "parser/parser.c"
    break;

  case 12:
#line 388 "parser/parser.y"
                                                  {
		if ((*error = postfix_expression_array_index_callback(&(yyval.expression), (yyvsp[-3].expression), (yyvsp[-1].expression), types)))
			YYABORT;
	}
#line 2592 "parser/parser.c"
    break;

  case 13:
#line 391 "parser/parser.y"
                                       {
		if ((*error = postfix_expression_empty_function_call_callback(&(yyval.expression), (yyvsp[-2].expression), types)))
			YYABORT;
	}
#line 2601 "parser/parser.c"
    break;

  case 14:
#line 394 "parser/parser.y"
                                                                {
		if ((*error = postfix_expression_function_call_callback(&(yyval.expression), (yyvsp[-3].expression), (yyvsp[-1].expression_ll), types)))
			YYABORT;
	}
#line 2610 "parser/parser.c"
    break;

  case 15:
#line 397 "parser/parser.y"
                                              {
		if ((*error = postfix_expression_field_access_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].identifier))))
			YYABORT;
	}
#line 2619 "parser/parser.c"
    break;

  case 16:
#line 400 "parser/parser.y"
                                                 {
		if ((*error = postfix_expression_arrow_access_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].identifier))))
			YYABORT;
	}
#line 2628 "parser/parser.c"
    break;

  case 17:
#line 403 "parser/parser.y"
                                      {
		if ((*error = postfix_expression_increment_callback(&(yyval.expression), (yyvsp[-1].expression))))
			YYABORT;
	}
#line 2637 "parser/parser.c"
    break;

  case 18:
#line 406 "parser/parser.y"
                                      {
		if ((*error = postfix_expression_decrement_callback(&(yyval.expression), (yyvsp[-1].expression))))
			YYABORT;
	}
#line 2646 "parser/parser.c"
    break;

  case 19:
#line 412 "parser/parser.y"
                                {
		if ((*error = argument_expression_list_head_callback(&(yyval.expression_ll), (yyvsp[0].expression))))
			YYABORT;
	}
#line 2655 "parser/parser.c"
    break;

  case 20:
#line 415 "parser/parser.y"
                                                               {
		if ((*error = argument_expression_list_append_callback(&(yyval.expression_ll), (yyvsp[-2].expression_ll), (yyvsp[0].expression))))
			YYABORT;
	}
#line 2664 "parser/parser.c"
    break;

  case 21:
#line 421 "parser/parser.y"
                             {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 2672 "parser/parser.c"
    break;

  case 22:
#line 423 "parser/parser.y"
                                    {
		if ((*error = unary_expression_increment_callback(&(yyval.expression), (yyvsp[0].expression))))
			YYABORT;
	}
#line 2681 "parser/parser.c"
    break;

  case 23:
#line 426 "parser/parser.y"
                                    {
		if ((*error = unary_expression_decrement_callback(&(yyval.expression), (yyvsp[0].expression))))
			YYABORT;
	}
#line 2690 "parser/parser.c"
    break;

  case 24:
#line 429 "parser/parser.y"
                                           {
		if ((*error = unary_expression_operator(&(yyval.expression), (yyvsp[-1].unary_expression_kind), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 2699 "parser/parser.c"
    break;

  case 25:
#line 432 "parser/parser.y"
                                    {
		if ((*error = unary_expression_sizeof_expression_callback(&(yyval.expression), (yyvsp[0].expression))))
			YYABORT;
	}
#line 2708 "parser/parser.c"
    break;

  case 26:
#line 435 "parser/parser.y"
                                     {
		if ((*error = unary_expression_sizeof_type_callback(&(yyval.expression), (yyvsp[-1].type), types)))
			YYABORT;
	}
#line 2717 "parser/parser.c"
    break;

  case 27:
#line 441 "parser/parser.y"
              { (yyval.unary_expression_kind) = uek_address_of; }
#line 2723 "parser/parser.c"
    break;

  case 28:
#line 442 "parser/parser.y"
              { (yyval.unary_expression_kind) = uek_dereference; }
#line 2729 "parser/parser.c"
    break;

  case 29:
#line 443 "parser/parser.y"
              { (yyval.unary_expression_kind) = uek_numeric_plus; }
#line 2735 "parser/parser.c"
    break;

  case 30:
#line 444 "parser/parser.y"
              { (yyval.unary_expression_kind) = uek_numeric_negate; }
#line 2741 "parser/parser.c"
    break;

  case 31:
#line 445 "parser/parser.y"
              { (yyval.unary_expression_kind) = uek_bitwise_negate; }
#line 2747 "parser/parser.c"
    break;

  case 32:
#line 446 "parser/parser.y"
              { (yyval.unary_expression_kind) = uek_logical_negate; }
#line 2753 "parser/parser.c"
    break;

  case 33:
#line 450 "parser/parser.y"
                           {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 2761 "parser/parser.c"
    break;

  case 34:
#line 452 "parser/parser.y"
                                              {
		if ((*error = cast_expression_cast_callback(&(yyval.expression), (yyvsp[-2].type), (yyvsp[0].expression))))
			YYABORT;
	}
#line 2770 "parser/parser.c"
    break;

  case 35:
#line 458 "parser/parser.y"
                          {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 2778 "parser/parser.c"
    break;

  case 36:
#line 460 "parser/parser.y"
                                                          {
		if ((*error = multiplicative_expression_multiply_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 2787 "parser/parser.c"
    break;

  case 37:
#line 463 "parser/parser.y"
                                                          {
		if ((*error = multiplicative_expression_divide_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 2796 "parser/parser.c"
    break;

  case 38:
#line 466 "parser/parser.y"
                                                          {
		if ((*error = multiplicative_expression_rdivide_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression))))
			YYABORT;
	}
#line 2805 "parser/parser.c"
    break;

  case 39:
#line 472 "parser/parser.y"
                                    {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 2813 "parser/parser.c"
    break;

  case 40:
#line 474 "parser/parser.y"
                                                              {
		if ((*error = additive_expression_add_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 2822 "parser/parser.c"
    break;

  case 41:
#line 477 "parser/parser.y"
                                                              {
		if ((*error = additive_expression_subtract_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 2831 "parser/parser.c"
    break;

  case 42:
#line 483 "parser/parser.y"
                              {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 2839 "parser/parser.c"
    break;

  case 43:
#line 485 "parser/parser.y"
                                                         {
		if ((*error = shift_expression_leftshift_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression))))
			YYABORT;
	}
#line 2848 "parser/parser.c"
    break;

  case 44:
#line 488 "parser/parser.y"
                                                          {
		if ((*error = shift_expression_rightshift_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression))))
			YYABORT;
	}
#line 2857 "parser/parser.c"
    break;

  case 45:
#line 494 "parser/parser.y"
                           {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 2865 "parser/parser.c"
    break;

  case 46:
#line 496 "parser/parser.y"
                                                       {
		if ((*error = relational_expression_less_than_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 2874 "parser/parser.c"
    break;

  case 47:
#line 499 "parser/parser.y"
                                                       {
		if ((*error = relational_expression_greater_than_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 2883 "parser/parser.c"
    break;

  case 48:
#line 502 "parser/parser.y"
                                                         {
		if ((*error = relational_expression_less_than_equal_to_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 2892 "parser/parser.c"
    break;

  case 49:
#line 505 "parser/parser.y"
                                                         {
		if ((*error = relational_expression_greater_than_equal_to_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 2901 "parser/parser.c"
    break;

  case 50:
#line 511 "parser/parser.y"
                                {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 2909 "parser/parser.c"
    break;

  case 51:
#line 513 "parser/parser.y"
                                                            {
		if ((*error = equality_expression_equal_to_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 2918 "parser/parser.c"
    break;

  case 52:
#line 516 "parser/parser.y"
                                                            {
		if ((*error = equality_expression_not_equal_to_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 2927 "parser/parser.c"
    break;

  case 53:
#line 522 "parser/parser.y"
                              {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 2935 "parser/parser.c"
    break;

  case 54:
#line 524 "parser/parser.y"
                                                   {
		if ((*error = and_expression_and_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression))))
			YYABORT;
	}
#line 2944 "parser/parser.c"
    break;

  case 55:
#line 530 "parser/parser.y"
                         {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 2952 "parser/parser.c"
    break;

  case 56:
#line 532 "parser/parser.y"
                                                       {
		if ((*error = exclusive_or_expression_xor_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression))))
			YYABORT;
	}
#line 2961 "parser/parser.c"
    break;

  case 57:
#line 538 "parser/parser.y"
                                  {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 2969 "parser/parser.c"
    break;

  case 58:
#line 540 "parser/parser.y"
                                                                {
		if ((*error = inclusive_or_expression_or_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression))))
			YYABORT;
	}
#line 2978 "parser/parser.c"
    break;

  case 59:
#line 546 "parser/parser.y"
                                  {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 2986 "parser/parser.c"
    break;

  case 60:
#line 548 "parser/parser.y"
                                                                  {
		if ((*error = logical_and_expression_and_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 2995 "parser/parser.c"
    break;

  case 61:
#line 554 "parser/parser.y"
                                 {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 3003 "parser/parser.c"
    break;

  case 62:
#line 556 "parser/parser.y"
                                                               {
		if ((*error = logical_or_expression_or_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 3012 "parser/parser.c"
    break;

  case 63:
#line 562 "parser/parser.y"
                                {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 3020 "parser/parser.c"
    break;

  case 64:
#line 564 "parser/parser.y"
                                                                            {
		if ((*error = conditional_expression_ternary(&(yyval.expression), (yyvsp[-4].expression), (yyvsp[-2].expression), (yyvsp[0].expression))))
			YYABORT;
	}
#line 3029 "parser/parser.c"
    break;

  case 65:
#line 570 "parser/parser.y"
                                 {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 3037 "parser/parser.c"
    break;

  case 66:
#line 572 "parser/parser.y"
                                                                       {
		if ((*error = assignment_expression_assignment_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[-1].binary_expression_kind), (yyvsp[0].expression), types)))
			YYABORT;
	}
#line 3046 "parser/parser.c"
    break;

  case 67:
#line 578 "parser/parser.y"
              { (yyval.binary_expression_kind) = bek_regular_assign; }
#line 3052 "parser/parser.c"
    break;

  case 68:
#line 579 "parser/parser.y"
                     { (yyval.binary_expression_kind) = bek_multiply_assign; }
#line 3058 "parser/parser.c"
    break;

  case 69:
#line 580 "parser/parser.y"
                     { (yyval.binary_expression_kind) = bek_divide_assign; }
#line 3064 "parser/parser.c"
    break;

  case 70:
#line 581 "parser/parser.y"
                     { (yyval.binary_expression_kind) = bek_rdivide_assign; }
#line 3070 "parser/parser.c"
    break;

  case 71:
#line 582 "parser/parser.y"
                     { (yyval.binary_expression_kind) = bek_add_assign; }
#line 3076 "parser/parser.c"
    break;

  case 72:
#line 583 "parser/parser.y"
                     { (yyval.binary_expression_kind) = bek_subtract_assign; }
#line 3082 "parser/parser.c"
    break;

  case 73:
#line 584 "parser/parser.y"
                      { (yyval.binary_expression_kind) = bek_leftshift_assign; }
#line 3088 "parser/parser.c"
    break;

  case 74:
#line 585 "parser/parser.y"
                       { (yyval.binary_expression_kind) = bek_rightshift_assign; }
#line 3094 "parser/parser.c"
    break;

  case 75:
#line 586 "parser/parser.y"
                     { (yyval.binary_expression_kind) = bek_bitwise_and_assign; }
#line 3100 "parser/parser.c"
    break;

  case 76:
#line 587 "parser/parser.y"
                     { (yyval.binary_expression_kind) = bek_bitwise_xor_assign; }
#line 3106 "parser/parser.c"
    break;

  case 77:
#line 588 "parser/parser.y"
                    { (yyval.binary_expression_kind) = bek_bitwise_or_assign; }
#line 3112 "parser/parser.c"
    break;

  case 78:
#line 592 "parser/parser.y"
                                {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 3120 "parser/parser.c"
    break;

  case 79:
#line 594 "parser/parser.y"
                                                 {
		if ((*error = expression_comma_callback(&(yyval.expression), (yyvsp[-2].expression), (yyvsp[0].expression))))
			YYABORT;
	}
#line 3129 "parser/parser.c"
    break;

  case 80:
#line 600 "parser/parser.y"
                                 {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 3137 "parser/parser.c"
    break;

  case 81:
#line 605 "parser/parser.y"
                                     {
		// this could only be a struct declaration, right?
		if ((*error = declaration_just_specifiers_callback(&(yyval.statement_ll), (yyvsp[-1].declaration_specifiers))))
			YYABORT;
	}
#line 3147 "parser/parser.c"
    break;

  case 82:
#line 609 "parser/parser.y"
                                                            {
		// these two TODOs are gonna possibly push into type name.
		// is the point where the two sides that make up a type collide:
		if ((*error = declaration_specifiers_and_init_list_callback(&(yyval.statement_ll), (yyvsp[-2].declaration_specifiers), (yyvsp[-1].init_declarator_ll), scope)))
			YYABORT;
	}
#line 3158 "parser/parser.c"
    break;

  case 83:
#line 617 "parser/parser.y"
                                  {
		if ((*error = declaration_specifiers_storage_class_callback(&(yyval.declaration_specifiers), (yyvsp[0].storage_class), NULL)))
			YYABORT;
	}
#line 3167 "parser/parser.c"
    break;

  case 84:
#line 620 "parser/parser.y"
                                                           {
		if ((*error = declaration_specifiers_storage_class_callback(&(yyval.declaration_specifiers), (yyvsp[-1].storage_class), (yyvsp[0].declaration_specifiers))))
			YYABORT;
	}
#line 3176 "parser/parser.c"
    break;

  case 85:
#line 623 "parser/parser.y"
                           {
		if ((*error = declaration_specifiers_type_specifier_callback(&(yyval.declaration_specifiers), (yyvsp[0].type), NULL, types)))
			YYABORT;
	}
#line 3185 "parser/parser.c"
    break;

  case 86:
#line 626 "parser/parser.y"
                                                  {
		if ((*error = declaration_specifiers_type_specifier_callback(&(yyval.declaration_specifiers), (yyvsp[-1].type), (yyvsp[0].declaration_specifiers), types)))
			YYABORT;
	}
#line 3194 "parser/parser.c"
    break;

  case 87:
#line 629 "parser/parser.y"
                           {
		if ((*error = declaration_specifiers_type_qualifier_callback(&(yyval.declaration_specifiers), (yyvsp[0].type_qualifier), NULL)))
			YYABORT;
	}
#line 3203 "parser/parser.c"
    break;

  case 88:
#line 632 "parser/parser.y"
                                                  {
		if ((*error = declaration_specifiers_type_qualifier_callback(&(yyval.declaration_specifiers), (yyvsp[-1].type_qualifier), (yyvsp[0].declaration_specifiers))))
			YYABORT;
	}
#line 3212 "parser/parser.c"
    break;

  case 89:
#line 638 "parser/parser.y"
                          {
		if ((*error = init_declarator_ll_head_callback(&(yyval.init_declarator_ll), (yyvsp[0].init_declarator))))
			YYABORT;
	}
#line 3221 "parser/parser.c"
    break;

  case 90:
#line 641 "parser/parser.y"
                                                     {
		if ((*error = init_declarator_ll_append_callback(&(yyval.init_declarator_ll), (yyvsp[-2].init_declarator_ll), (yyvsp[0].init_declarator))))
			YYABORT;
	}
#line 3230 "parser/parser.c"
    break;

  case 91:
#line 647 "parser/parser.y"
                     {
		if ((*error = init_declarator_just_declarator_callback(&(yyval.init_declarator), (yyvsp[0].declarator))))
			YYABORT;
	}
#line 3239 "parser/parser.c"
    break;

  case 92:
#line 650 "parser/parser.y"
                                       {
		if ((*error = init_declarator_declarator_and_initializer_callback(&(yyval.init_declarator), (yyvsp[-2].declarator), (yyvsp[0].initializer))))
			YYABORT;
	}
#line 3248 "parser/parser.c"
    break;

  case 93:
#line 657 "parser/parser.y"
                  { (yyval.storage_class) = sc_typedef; }
#line 3254 "parser/parser.c"
    break;

  case 94:
#line 658 "parser/parser.y"
                 { (yyval.storage_class) = sc_extern; }
#line 3260 "parser/parser.c"
    break;

  case 95:
#line 659 "parser/parser.y"
                 { (yyval.storage_class) = sc_static; }
#line 3266 "parser/parser.c"
    break;

  case 96:
#line 660 "parser/parser.y"
               { (yyval.storage_class) = sc_auto; }
#line 3272 "parser/parser.c"
    break;

  case 97:
#line 661 "parser/parser.y"
                   { (yyval.storage_class) = sc_register; }
#line 3278 "parser/parser.c"
    break;

  case 98:
#line 666 "parser/parser.y"
               { (yyval.type) = type_specifier_void_callback(types); }
#line 3284 "parser/parser.c"
    break;

  case 99:
#line 667 "parser/parser.y"
               { (yyval.type) = type_specifier_char_callback(types); }
#line 3290 "parser/parser.c"
    break;

  case 100:
#line 668 "parser/parser.y"
                { (yyval.type) = type_specifier_short_callback(types); }
#line 3296 "parser/parser.c"
    break;

  case 101:
#line 669 "parser/parser.y"
              { (yyval.type) = type_specifier_int_callback(types); }
#line 3302 "parser/parser.c"
    break;

  case 102:
#line 670 "parser/parser.y"
               { (yyval.type) = type_specifier_long_callback(types); }
#line 3308 "parser/parser.c"
    break;

  case 103:
#line 671 "parser/parser.y"
                { (yyval.type) = type_specifier_float_callback(types); }
#line 3314 "parser/parser.c"
    break;

  case 104:
#line 672 "parser/parser.y"
                 { (yyval.type) = type_specifier_double_callback(types); }
#line 3320 "parser/parser.c"
    break;

  case 105:
#line 673 "parser/parser.y"
                 { (yyval.type) = type_specifier_signed_callback(types); }
#line 3326 "parser/parser.c"
    break;

  case 106:
#line 674 "parser/parser.y"
                   { (yyval.type) = type_specifier_unsigned_callback(types); }
#line 3332 "parser/parser.c"
    break;

  case 107:
#line 675 "parser/parser.y"
                                    { (yyval.type) = (yyvsp[0].type); }
#line 3338 "parser/parser.c"
    break;

  case 108:
#line 676 "parser/parser.y"
                         { (yyval.type) = (yyvsp[0].type); }
#line 3344 "parser/parser.c"
    break;

  case 109:
#line 677 "parser/parser.y"
                    { (yyval.type) = (yyvsp[0].type); }
#line 3350 "parser/parser.c"
    break;

  case 110:
#line 682 "parser/parser.y"
                                                                       {
		if ((*error = struct_or_union_specifier_declaration_list_callback(&(yyval.type), (yyvsp[-4].boolean), (yyvsp[-3].identifier), (yyvsp[-1].struct_field_ll), scope)))
			YYABORT;
	}
#line 3359 "parser/parser.c"
    break;

  case 111:
#line 685 "parser/parser.y"
                                                                       {
		if ((*error = struct_or_union_specifier_declaration_list_callback(&(yyval.type), (yyvsp[-3].boolean), NULL, (yyvsp[-1].struct_field_ll), scope)))
			YYABORT;
	}
#line 3368 "parser/parser.c"
    break;

  case 112:
#line 688 "parser/parser.y"
                                                                       {
		if ((*error = struct_or_union_specifier_just_identifier_callback(&(yyval.type), (yyvsp[-1].boolean), (yyvsp[0].identifier), scope)))
			YYABORT;
	}
#line 3377 "parser/parser.c"
    break;

  case 113:
#line 694 "parser/parser.y"
                 { (yyval.boolean) = true; }
#line 3383 "parser/parser.c"
    break;

  case 114:
#line 695 "parser/parser.y"
                { (yyval.boolean) = false; }
#line 3389 "parser/parser.c"
    break;

  case 115:
#line 700 "parser/parser.y"
                             {
		(yyval.struct_field_ll) = (yyvsp[0].struct_field_ll);
	}
#line 3397 "parser/parser.c"
    break;

  case 116:
#line 702 "parser/parser.y"
                                                       {
		if ((*error = struct_declaration_list_merge_callback(&(yyval.struct_field_ll), (yyvsp[-1].struct_field_ll), (yyvsp[0].struct_field_ll))))
			YYABORT;
	}
#line 3406 "parser/parser.c"
    break;

  case 117:
#line 709 "parser/parser.y"
                                                              {
		if ((*error = struct_declaration_declaration_callback(&(yyval.struct_field_ll), (yyvsp[-2].specifier_qualifiers), (yyvsp[-1].struct_declarator_ll))))
			YYABORT;
	}
#line 3415 "parser/parser.c"
    break;

  case 118:
#line 716 "parser/parser.y"
                                                  {
		if ((*error = specifier_qualifier_list_prepend_specifier(&(yyval.specifier_qualifiers), (yyvsp[-1].type), (yyvsp[0].specifier_qualifiers), types)))
			YYABORT;
	}
#line 3424 "parser/parser.c"
    break;

  case 119:
#line 719 "parser/parser.y"
                           {
		if ((*error = specifier_qualifier_list_head_specifier(&(yyval.specifier_qualifiers), (yyvsp[0].type), types)))
			YYABORT;
	}
#line 3433 "parser/parser.c"
    break;

  case 120:
#line 722 "parser/parser.y"
                                                    {
		TODO;
		if ((*error = specifier_qualifier_list_prepend_qualifier(&(yyval.specifier_qualifiers), (yyvsp[-1].type_qualifier), (yyvsp[0].specifier_qualifiers))))
			YYABORT;
	}
#line 3443 "parser/parser.c"
    break;

  case 121:
#line 726 "parser/parser.y"
                           {
		TODO;
		if ((*error = specifier_qualifier_list_head_qualifier(&(yyval.specifier_qualifiers), (yyvsp[0].type_qualifier))))
			YYABORT;
	}
#line 3453 "parser/parser.c"
    break;

  case 122:
#line 734 "parser/parser.y"
                            {
		if ((*error = struct_declarator_list_head_callback(&(yyval.struct_declarator_ll), (yyvsp[0].struct_declarator))))
			YYABORT;
	}
#line 3462 "parser/parser.c"
    break;

  case 123:
#line 737 "parser/parser.y"
                                                         {
		TODO;
		if ((*error = struct_declarator_list_append_callback(&(yyval.struct_declarator_ll), (yyvsp[-2].struct_declarator_ll), (yyvsp[0].struct_declarator))))
			YYABORT;
	}
#line 3472 "parser/parser.c"
    break;

  case 124:
#line 745 "parser/parser.y"
                     {
		if ((*error = struct_declarator_declarator(&(yyval.struct_declarator), (yyvsp[0].declarator))))
			YYABORT;
	}
#line 3481 "parser/parser.c"
    break;

  case 125:
#line 748 "parser/parser.y"
                                    {
		TODO;
		if ((*error = struct_declarator_bitfield(&(yyval.struct_declarator), NULL, (yyvsp[0].expression))))
			YYABORT;
	}
#line 3491 "parser/parser.c"
    break;

  case 126:
#line 752 "parser/parser.y"
                                               {
		TODO;
		if ((*error = struct_declarator_declarator_and_bitfield(&(yyval.struct_declarator), (yyvsp[-2].declarator), (yyvsp[0].expression))))
			YYABORT;
	}
#line 3501 "parser/parser.c"
    break;

  case 127:
#line 759 "parser/parser.y"
                                       {
		if ((*error = enum_specifier_just_list(&(yyval.type), NULL, (yyvsp[-1].enumerator))))
			YYABORT;
	}
#line 3510 "parser/parser.c"
    break;

  case 128:
#line 762 "parser/parser.y"
                                                    {
		if ((*error = enum_specifier_identifier_and_list(&(yyval.type), (yyvsp[-3].identifier), (yyvsp[-1].enumerator))))
			YYABORT;
	}
#line 3519 "parser/parser.c"
    break;

  case 129:
#line 765 "parser/parser.y"
                            {
		if ((*error = enum_specifier_just_identifier(&(yyval.type), (yyvsp[0].identifier), NULL)))
			YYABORT;
	}
#line 3528 "parser/parser.c"
    break;

  case 130:
#line 771 "parser/parser.y"
                     {
		if ((*error = enumerator_list_head_callback(&(yyval.enumerator), (yyvsp[0].enumerator_entry))))
			YYABORT;
	}
#line 3537 "parser/parser.c"
    break;

  case 131:
#line 774 "parser/parser.y"
                                           {
		if ((*error = enumerator_list_append_callback(&(yyval.enumerator), (yyvsp[-2].enumerator), (yyvsp[0].enumerator_entry))))
			YYABORT;
	}
#line 3546 "parser/parser.c"
    break;

  case 132:
#line 780 "parser/parser.y"
                     {
		if ((*error = enumerator_just_identifier_callback(&(yyval.enumerator_entry), (yyvsp[0].identifier), NULL)))
			YYABORT;
	}
#line 3555 "parser/parser.c"
    break;

  case 133:
#line 783 "parser/parser.y"
                                               {
		if ((*error = enumerator_identifier_and_expression_callback(&(yyval.enumerator_entry), (yyvsp[-2].identifier), (yyvsp[0].expression))))
			YYABORT;
	}
#line 3564 "parser/parser.c"
    break;

  case 134:
#line 790 "parser/parser.y"
                { (yyval.type_qualifier) = tq_constant; }
#line 3570 "parser/parser.c"
    break;

  case 135:
#line 791 "parser/parser.y"
                   { (yyval.type_qualifier) = tq_volatile; }
#line 3576 "parser/parser.c"
    break;

  case 136:
#line 795 "parser/parser.y"
                                    {
		if ((*error = declarator_pointer_callback(&(yyval.declarator), (yyvsp[-1].pointer), (yyvsp[0].declarator))))
			YYABORT;
	}
#line 3585 "parser/parser.c"
    break;

  case 137:
#line 798 "parser/parser.y"
                              {
		(yyval.declarator) = (yyvsp[0].declarator);
	}
#line 3593 "parser/parser.c"
    break;

  case 138:
#line 803 "parser/parser.y"
                     {
		if ((*error = direct_declarator_identifier_callback(&(yyval.declarator), (yyvsp[0].identifier))))
			YYABORT;
	}
#line 3602 "parser/parser.c"
    break;

  case 139:
#line 806 "parser/parser.y"
                               {
		(yyval.declarator) = (yyvsp[-1].declarator);
	}
#line 3610 "parser/parser.c"
    break;

  case 140:
#line 808 "parser/parser.y"
                                                          {
		if ((*error = direct_declarator_array_callback(&(yyval.declarator), (yyvsp[-3].declarator), (yyvsp[-1].expression))))
			YYABORT;
	}
#line 3619 "parser/parser.c"
    break;

  case 141:
#line 811 "parser/parser.y"
                                      {
		// can only be the outer-most brackets
		if ((*error = direct_declarator_sizeless_array_callback(&(yyval.declarator), (yyvsp[-2].declarator))))
			YYABORT;
	}
#line 3629 "parser/parser.c"
    break;

  case 142:
#line 815 "parser/parser.y"
                                                          {
		// parameter types and names
		if ((*error = direct_declarator_parameter_list_callback(&(yyval.declarator), (yyvsp[-3].declarator), (yyvsp[-1].parameter_ll))))
			YYABORT;
	}
#line 3639 "parser/parser.c"
    break;

  case 143:
#line 819 "parser/parser.y"
                                                      {
		// just the parameter names are given now,
		// types show up later
		if ((*error = direct_declarator_identifier_list_callback(&(yyval.declarator), (yyvsp[-3].declarator), (yyvsp[-1].identifier_ll))))
			YYABORT;
	}
#line 3650 "parser/parser.c"
    break;

  case 144:
#line 824 "parser/parser.y"
                                      {
		if ((*error = direct_declarator_function_callback(&(yyval.declarator), (yyvsp[-2].declarator))))
			YYABORT;
	}
#line 3659 "parser/parser.c"
    break;

  case 145:
#line 830 "parser/parser.y"
              {
		if ((*error = pointer_pointer_callback(&(yyval.pointer), NULL)))
			YYABORT;
	}
#line 3668 "parser/parser.c"
    break;

  case 146:
#line 833 "parser/parser.y"
                                            {
		if ((*error = pointer_with_qualifiers_callback(&(yyval.pointer), (yyvsp[0].type_qualifier_list), NULL)))
			YYABORT;
	}
#line 3677 "parser/parser.c"
    break;

  case 147:
#line 836 "parser/parser.y"
                                            {
		if ((*error = pointer_pointer_callback(&(yyval.pointer), (yyvsp[0].pointer))))
			YYABORT;
	}
#line 3686 "parser/parser.c"
    break;

  case 148:
#line 839 "parser/parser.y"
                                            {
		if ((*error = pointer_with_qualifiers_callback(&(yyval.pointer), (yyvsp[-1].type_qualifier_list), (yyvsp[0].pointer))))
			YYABORT;
	}
#line 3695 "parser/parser.c"
    break;

  case 149:
#line 845 "parser/parser.y"
                         {
		if ((*error = type_qualifier_list_head_callback(&(yyval.type_qualifier_list), (yyvsp[0].type_qualifier))))
			YYABORT;
	}
#line 3704 "parser/parser.c"
    break;

  case 150:
#line 848 "parser/parser.y"
                                               {
		if ((*error = type_qualifier_list_append_callback(&(yyval.type_qualifier_list), (yyvsp[-1].type_qualifier_list), (yyvsp[0].type_qualifier))))
			YYABORT;
	}
#line 3713 "parser/parser.c"
    break;

  case 151:
#line 854 "parser/parser.y"
                         {
		(yyval.parameter_ll) = (yyvsp[0].parameter_ll);
	}
#line 3721 "parser/parser.c"
    break;

  case 152:
#line 856 "parser/parser.y"
                                        {
		parameter_type_list_ellipsis(&(yyval.parameter_ll), (yyvsp[-2].parameter_ll));
	}
#line 3729 "parser/parser.c"
    break;

  case 153:
#line 861 "parser/parser.y"
                                {
		if ((*error = parameter_list_head_callback(&(yyval.parameter_ll), (yyvsp[0].parameter))))
			YYABORT;
	}
#line 3738 "parser/parser.c"
    break;

  case 154:
#line 864 "parser/parser.y"
                                                     {
		if ((*error = parameter_list_append_callback(&(yyval.parameter_ll), (yyvsp[-2].parameter_ll), (yyvsp[0].parameter))))
			YYABORT;
	}
#line 3747 "parser/parser.c"
    break;

  case 155:
#line 870 "parser/parser.y"
                                            {
		if ((*error = parameter_declaration_declarator_callback(&(yyval.parameter), (yyvsp[-1].declaration_specifiers), (yyvsp[0].declarator))))
			YYABORT;
	}
#line 3756 "parser/parser.c"
    break;

  case 156:
#line 873 "parser/parser.y"
                                                       {
		if ((*error = parameter_declaration_abstract_declarator_callback(&(yyval.parameter), (yyvsp[-1].declaration_specifiers), (yyvsp[0].declarator))))
			YYABORT;
	}
#line 3765 "parser/parser.c"
    break;

  case 157:
#line 876 "parser/parser.y"
                                   {
		if ((*error = parameter_declaration_just_specifiers_callback(&(yyval.parameter), (yyvsp[0].declaration_specifiers))))
			YYABORT;
	}
#line 3774 "parser/parser.c"
    break;

  case 158:
#line 882 "parser/parser.y"
                     {
		if ((*error = identifier_list_head_callback(&(yyval.identifier_ll), (yyvsp[0].identifier))))
			YYABORT;
	}
#line 3783 "parser/parser.c"
    break;

  case 159:
#line 885 "parser/parser.y"
                                           {
		if ((*error = identifier_list_append_callback(&(yyval.identifier_ll), (yyvsp[-2].identifier_ll), (yyvsp[0].identifier))))
			YYABORT;
	}
#line 3792 "parser/parser.c"
    break;

  case 160:
#line 891 "parser/parser.y"
                                   {
		if ((*error = type_name_just_qualifier_list(&(yyval.type), (yyvsp[0].specifier_qualifiers))))
			YYABORT;
	}
#line 3801 "parser/parser.c"
    break;

  case 161:
#line 894 "parser/parser.y"
                                                         {
		if ((*error = type_name_qualifier_list_and_abstract_declarator(&(yyval.type), (yyvsp[-1].specifier_qualifiers), (yyvsp[0].declarator))))
			YYABORT;
	}
#line 3810 "parser/parser.c"
    break;

  case 162:
#line 900 "parser/parser.y"
                  {
		if ((*error = abstract_declarator_pointer_callback(&(yyval.declarator), (yyvsp[0].pointer), NULL)))
			YYABORT;
	}
#line 3819 "parser/parser.c"
    break;

  case 163:
#line 903 "parser/parser.y"
                                       {
		(yyval.declarator) = (yyvsp[0].declarator);
	}
#line 3827 "parser/parser.c"
    break;

  case 164:
#line 905 "parser/parser.y"
                                               {
		if ((*error = abstract_declarator_pointer_callback(&(yyval.declarator), (yyvsp[-1].pointer), (yyvsp[0].declarator))))
			YYABORT;
	}
#line 3836 "parser/parser.c"
    break;

  case 165:
#line 911 "parser/parser.y"
                                      {
		(yyval.declarator) = (yyvsp[-1].declarator);
	}
#line 3844 "parser/parser.c"
    break;

  case 166:
#line 913 "parser/parser.y"
                    {
		if ((*error = direct_abstract_declarator_sizeless_array(&(yyval.declarator))))
			YYABORT;
	}
#line 3853 "parser/parser.c"
    break;

  case 167:
#line 916 "parser/parser.y"
                                        {
		if ((*error = direct_abstract_declarator_array(&(yyval.declarator), (yyvsp[-1].expression))))
			YYABORT;
	}
#line 3862 "parser/parser.c"
    break;

  case 168:
#line 919 "parser/parser.y"
                                               {
		if ((*error = direct_abstract_declarator_sizeless_array(&(yyval.declarator), (yyvsp[-2].declarator))))
			YYABORT;
	}
#line 3871 "parser/parser.c"
    break;

  case 169:
#line 922 "parser/parser.y"
                                                                   {
		if ((*error = direct_abstract_declarator_array(&(yyval.declarator), (yyvsp[-3].declarator), (yyvsp[-1].expression))))
			YYABORT;
	}
#line 3880 "parser/parser.c"
    break;

  case 170:
#line 925 "parser/parser.y"
                    {
		if ((*error = direct_abstract_declarator_empty_function(&(yyval.declarator), NULL)))
			YYABORT;
	}
#line 3889 "parser/parser.c"
    break;

  case 171:
#line 928 "parser/parser.y"
                                        {
		if ((*error = direct_abstract_declarator_function(&(yyval.declarator), NULL, (yyvsp[-1].parameter_ll))))
			YYABORT;
	}
#line 3898 "parser/parser.c"
    break;

  case 172:
#line 931 "parser/parser.y"
                                               {
		if ((*error = direct_abstract_declarator_empty_function(&(yyval.declarator), (yyvsp[-2].declarator))))
			YYABORT;
	}
#line 3907 "parser/parser.c"
    break;

  case 173:
#line 934 "parser/parser.y"
                                                                   {
		if ((*error = direct_abstract_declarator_function(&(yyval.declarator), (yyvsp[-3].declarator), (yyvsp[-1].parameter_ll))))
			YYABORT;
	}
#line 3916 "parser/parser.c"
    break;

  case 174:
#line 940 "parser/parser.y"
                                {
		if ((*error = initializer_expression_callback(&(yyval.initializer), (yyvsp[0].expression))))
			YYABORT;
	}
#line 3925 "parser/parser.c"
    break;

  case 175:
#line 943 "parser/parser.y"
                                     {
		if ((*error = initializer_initializer_list_callback(&(yyval.initializer), (yyvsp[-1].initializer))))
			YYABORT;
	}
#line 3934 "parser/parser.c"
    break;

  case 176:
#line 946 "parser/parser.y"
                                         {
		if ((*error = initializer_initializer_list_callback(&(yyval.initializer), (yyvsp[-2].initializer))))
			YYABORT;
	}
#line 3943 "parser/parser.c"
    break;

  case 177:
#line 952 "parser/parser.y"
                      {
		if ((*error = initializer_list_head_callback(&(yyval.initializer), (yyvsp[0].initializer))))
			YYABORT;
	}
#line 3952 "parser/parser.c"
    break;

  case 178:
#line 955 "parser/parser.y"
                                             {
		if ((*error = initializer_list_append_callback(&(yyval.initializer), (yyvsp[-2].initializer), (yyvsp[0].initializer))))
			YYABORT;
	}
#line 3961 "parser/parser.c"
    break;

  case 179:
#line 961 "parser/parser.y"
                            { (yyval.statement) = (yyvsp[0].statement); }
#line 3967 "parser/parser.c"
    break;

  case 180:
#line 962 "parser/parser.y"
                             { (yyval.statement) = (struct statement*) (yyvsp[0].compound_statement); }
#line 3973 "parser/parser.c"
    break;

  case 181:
#line 963 "parser/parser.y"
                               { (yyval.statement) = (yyvsp[0].statement); }
#line 3979 "parser/parser.c"
    break;

  case 182:
#line 964 "parser/parser.y"
                              { (yyval.statement) = (yyvsp[0].statement); }
#line 3985 "parser/parser.c"
    break;

  case 183:
#line 965 "parser/parser.y"
                              { (yyval.statement) = (yyvsp[0].statement); }
#line 3991 "parser/parser.c"
    break;

  case 184:
#line 966 "parser/parser.y"
                         { (yyval.statement) = (yyvsp[0].statement); }
#line 3997 "parser/parser.c"
    break;

  case 185:
#line 970 "parser/parser.y"
                                   {
		if ((*error = labeled_statement_label_callback(&(yyval.statement), (yyvsp[-2].identifier), (yyvsp[0].statement))))
			YYABORT;
	}
#line 4006 "parser/parser.c"
    break;

  case 186:
#line 973 "parser/parser.y"
                                                   {
		if ((*error = labeled_statement_case_callback(&(yyval.statement), (yyvsp[-2].expression), (yyvsp[0].statement))))
			YYABORT;
	}
#line 4015 "parser/parser.c"
    break;

  case 187:
#line 976 "parser/parser.y"
                                  {
		if ((*error = labeled_statement_default_callback(&(yyval.statement), (yyvsp[0].statement))))
			YYABORT;
	}
#line 4024 "parser/parser.c"
    break;

  case 188:
#line 982 "parser/parser.y"
                 {
		(yyval.statement_ll) = NULL;
	}
#line 4032 "parser/parser.c"
    break;

  case 189:
#line 984 "parser/parser.y"
                             {
		(yyval.statement_ll) = (yyvsp[0].statement_ll);
	}
#line 4040 "parser/parser.c"
    break;

  case 190:
#line 989 "parser/parser.y"
                 {
		(yyval.statement_ll) = NULL;
	}
#line 4048 "parser/parser.c"
    break;

  case 191:
#line 991 "parser/parser.y"
                           {
		(yyval.statement_ll) = (yyvsp[0].statement_ll);
	}
#line 4056 "parser/parser.c"
    break;

  case 192:
#line 996 "parser/parser.y"
                     {
			(yyval.line) = *line;
			if ((*error = compound_statement_open_callback(scope)))
				YYABORT;
		}
#line 4066 "parser/parser.c"
    break;

  case 193:
#line 1000 "parser/parser.y"
                                                                    {
			compound_statement_close_callback(scope);
		}
#line 4074 "parser/parser.c"
    break;

  case 194:
#line 1002 "parser/parser.y"
                      {
			if ((*error = compound_statement_statements_callback(&(yyval.compound_statement), (yyvsp[-4].line), (yyvsp[-3].statement_ll), (yyvsp[-2].statement_ll))))
				YYABORT;
		}
#line 4083 "parser/parser.c"
    break;

  case 195:
#line 1009 "parser/parser.y"
                      {
		(yyval.statement_ll) = (yyvsp[0].statement_ll);
	}
#line 4091 "parser/parser.c"
    break;

  case 196:
#line 1011 "parser/parser.y"
                                         {
		declaration_list_merge_callback(&(yyval.statement_ll), (yyvsp[-1].statement_ll), (yyvsp[0].statement_ll));
	}
#line 4099 "parser/parser.c"
    break;

  case 197:
#line 1016 "parser/parser.y"
                    {
		if ((*error = statement_list_head_callback(&(yyval.statement_ll), (yyvsp[0].statement))))
			YYABORT;
	}
#line 4108 "parser/parser.c"
    break;

  case 198:
#line 1019 "parser/parser.y"
                                     {
		if ((*error = statement_list_append_callback(&(yyval.statement_ll), (yyvsp[-1].statement_ll), (yyvsp[0].statement))))
			YYABORT;
	}
#line 4117 "parser/parser.c"
    break;

  case 199:
#line 1025 "parser/parser.y"
              {
		(yyval.statement) = NULL;
	}
#line 4125 "parser/parser.c"
    break;

  case 200:
#line 1027 "parser/parser.y"
                              { (yyval.line) = *line; }
#line 4131 "parser/parser.c"
    break;

  case 201:
#line 1027 "parser/parser.y"
                                                  {
		if ((*error = expression_statement_expression_callback(&(yyval.statement), (yyvsp[-1].line), (yyvsp[-2].expression))))
			YYABORT;
	}
#line 4140 "parser/parser.c"
    break;

  case 202:
#line 1033 "parser/parser.y"
                                                       {
		if ((*error = selection_statement_if_callback(&(yyval.statement), (yyvsp[-2].expression), (yyvsp[0].statement), NULL, types)))
			YYABORT;
	}
#line 4149 "parser/parser.c"
    break;

  case 203:
#line 1036 "parser/parser.y"
                                                           {
		if ((*error = selection_statement_if_callback(&(yyval.statement), (yyvsp[-4].expression), (yyvsp[-2].statement), (yyvsp[0].statement), types)))
			YYABORT;
	}
#line 4158 "parser/parser.c"
    break;

  case 204:
#line 1039 "parser/parser.y"
                                                {
		if ((*error = selection_statement_switch_callback(&(yyval.statement), (yyvsp[-2].expression), (yyvsp[0].statement))))
			YYABORT;
	}
#line 4167 "parser/parser.c"
    break;

  case 205:
#line 1045 "parser/parser.y"
                                             {
		if ((*error = iteration_statement_while_callback(&(yyval.statement), (yyvsp[-2].expression), (yyvsp[0].statement), types)))
			YYABORT;
	}
#line 4176 "parser/parser.c"
    break;

  case 206:
#line 1048 "parser/parser.y"
                                                      {
		if ((*error = iteration_statement_dowhile_callback(&(yyval.statement), (yyvsp[-5].statement), (yyvsp[-2].expression))))
			YYABORT;
	}
#line 4185 "parser/parser.c"
    break;

  case 207:
#line 1051 "parser/parser.y"
                                                                            {
		if ((*error = iteration_statement_for_callback(&(yyval.statement), (yyvsp[-3].statement), (yyvsp[-2].statement), NULL, (yyvsp[0].statement))))
			YYABORT;
	}
#line 4194 "parser/parser.c"
    break;

  case 208:
#line 1054 "parser/parser.y"
                                                                                       {
		if ((*error = iteration_statement_for_callback(&(yyval.statement), (yyvsp[-4].statement), (yyvsp[-3].statement), (yyvsp[-2].expression), (yyvsp[0].statement))))
			YYABORT;
	}
#line 4203 "parser/parser.c"
    break;

  case 209:
#line 1060 "parser/parser.y"
                              {
		if ((*error = jump_statement_goto_callback(&(yyval.statement), (yyvsp[-1].identifier))))
			YYABORT;
	}
#line 4212 "parser/parser.c"
    break;

  case 210:
#line 1063 "parser/parser.y"
                         {
		if ((*error = jump_statement_continue_callback(&(yyval.statement))))
			YYABORT;
	}
#line 4221 "parser/parser.c"
    break;

  case 211:
#line 1066 "parser/parser.y"
                      {
		if ((*error = jump_statement_break_callback(&(yyval.statement))))
			YYABORT;
	}
#line 4230 "parser/parser.c"
    break;

  case 212:
#line 1069 "parser/parser.y"
                          {(yyval.line) = *line; }
#line 4236 "parser/parser.c"
    break;

  case 213:
#line 1069 "parser/parser.y"
                                             {
		if ((*error = jump_statement_return_callback(&(yyval.statement), (yyvsp[-1].line), NULL)))
			YYABORT;
	}
#line 4245 "parser/parser.c"
    break;

  case 214:
#line 1072 "parser/parser.y"
                          {(yyval.line) = *line; }
#line 4251 "parser/parser.c"
    break;

  case 215:
#line 1072 "parser/parser.y"
                                                        {
		if ((*error = jump_statement_return_callback(&(yyval.statement), (yyvsp[-2].line), (yyvsp[-1].expression))))
			YYABORT;
	}
#line 4260 "parser/parser.c"
    break;

  case 216:
#line 1077 "parser/parser.y"
                        {
		HERE;
	}
#line 4268 "parser/parser.c"
    break;

  case 217:
#line 1082 "parser/parser.y"
                               {
		HERE;
	}
#line 4276 "parser/parser.c"
    break;

  case 218:
#line 1084 "parser/parser.y"
                                                  {
		HERE;
	}
#line 4284 "parser/parser.c"
    break;

  case 219:
#line 1089 "parser/parser.y"
                              {
		if ((*error = external_declaration_function_callback((yyvsp[0].function_definition), asm_writer)))
			YYABORT;
	}
#line 4293 "parser/parser.c"
    break;

  case 220:
#line 1092 "parser/parser.y"
                        {
		if ((*error = external_declaration_global_callback((yyvsp[0].statement_ll))))
			YYABORT;
	}
#line 4302 "parser/parser.c"
    break;

  case 221:
#line 1098 "parser/parser.y"
                                                                 {
		if ((*error = function_definition_prebody(&(yyval.function_definition), (yyvsp[-1].declaration_specifiers), (yyvsp[0].declarator), scope)))
			YYABORT;
	}
#line 4311 "parser/parser.c"
    break;

  case 222:
#line 1101 "parser/parser.y"
                             {
		if ((*error = function_definition_postbody((yyvsp[-1].function_definition), scope)))
			YYABORT;
	}
#line 4320 "parser/parser.c"
    break;

  case 223:
#line 1104 "parser/parser.y"
          {
		if ((*error = function_definition_with_specifiers_and_declarator(&(yyval.function_definition), (yyvsp[-2].function_definition), (yyvsp[-1].compound_statement))))
			YYABORT;
		tfree((yyvsp[-4].declaration_specifiers)), tfree((yyvsp[-3].declarator));
	}
#line 4330 "parser/parser.c"
    break;

  case 224:
#line 1108 "parser/parser.y"
                                                                                 {
		CHECK;
		if ((*error = function_definition_with_declarator(&(yyval.function_definition), NULL, (yyvsp[-1].declarator), NULL, (yyvsp[0].compound_statement))))
			YYABORT;
	}
#line 4340 "parser/parser.c"
    break;


#line 4344 "parser/parser.c"

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
      yyerror (error, scope, types, asm_writer, line, string_counter, YY_("syntax error"));
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
        yyerror (error, scope, types, asm_writer, line, string_counter, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval, error, scope, types, asm_writer, line, string_counter);
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, error, scope, types, asm_writer, line, string_counter);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  yyerror (error, scope, types, asm_writer, line, string_counter, YY_("memory exhausted"));
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
                  yytoken, &yylval, error, scope, types, asm_writer, line, string_counter);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, error, scope, types, asm_writer, line, string_counter);
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
#line 1114 "parser/parser.y"
















