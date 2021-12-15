/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 64 "parser/parser.h"

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

#line 197 "parser/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (int *error, struct scope *scope, struct types *types, struct asm_writer* asm_writer, unsigned *line, size_t *string_counter);

#endif /* !YY_YY_PARSER_PARSER_H_INCLUDED  */
