
D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*


%{

#include <stdio.h>
#include <limits.h>

#include <debug.h>

#include <enums/error.h>

#include <defines/argv0.h>

#include <memory/tmalloc.h>
#include <memory/tstrdup.h>
#include <memory/tstrndup.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

#include <scope/lookup/type.h>

#include "parser.h"

static int check_type(int*, struct scope*);
static int handle_cpp_linemarkers(char** file);
static int process_integer_literal(int*);
static int process_character_literal(int*);
static int process_float_literal(int*);
static int process_string_literal(int*);

#define YY_DECL \
	int yylex(\
		int* error, \
		struct scope *scope, \
		char** file)

#define YY_USER_ACTION \
	yylloc.first_line = yylloc.last_line; \
	yylloc.first_column = yylloc.last_column; \
	for (char* i = yytext; *i; i++) { \
		switch (*i) { \
			case '\n':  \
				yylloc.last_line++; \
				yylloc.last_column = 0; \
				break; \
			case '\t': \
				yylloc.last_column += 8; \
				break; \
			case '\v': \
			case '\f': \
				yylloc.last_line++; \
				break; \
			case ' ': \
			default: \
				yylloc.last_column++; \
				break; \
		} \
	}

%}

%option nounput
%option noinput

%option yylineno

%%

 // From http://westes.github.io/flex/manual/Start-Conditions.html: //

 /* https://www.lysator.liu.se/c/ANSI-C-grammar-l.html */

"auto"			{ return (AUTO); }
"break"			{ return (BREAK); }
"case"			{ return (CASE); }
"char"			{ return (CHAR); }
"const"			{ return (CONST); }
"continue"		{ return (CONTINUE); }
"default"		{ return (DEFAULT); }
"do"			{ return (DO); }
"double"		{ return (DOUBLE); }
"else"			{ return (ELSE); }
"enum"			{ return (ENUM); }
"extern"		{ return (EXTERN); }
"float"			{ return (FLOAT); }
"for"			{ return (FOR); }
"goto"			{ return (GOTO); }
"if"			{ return (IF); }
"int"			{ return (INT); }
"long"			{ return (LONG); }
"register"		{ return (REGISTER); }
"return"		{ return (RETURN); }
"short"			{ return (SHORT); }
"signed"		{ return (SIGNED); }
"sizeof"		{ return (SIZEOF); }
"static"		{ return (STATIC); }
"struct"		{ return (STRUCT); }
"switch"		{ return (SWITCH); }
"typedef"		{ return (TYPEDEF); }
"union"			{ return (UNION); }
"unsigned"		{ return (UNSIGNED); }
"void"			{ return (VOID); }
"volatile"		{ return (VOLATILE); }
"while"			{ return (WHILE); }

{L}({L}|{D})*		{ return check_type(error, scope); }

0[xX]{H}+{IS}?		{ return (process_integer_literal(error)); }
0{D}+{IS}?			{ return (process_integer_literal(error)); }
{D}+{IS}?			{ return (process_integer_literal(error)); }
L?'(\\.|[^\\'])'	{ return (process_character_literal(error)); }

{D}+{E}{FS}?			{ return (process_float_literal(error)); }
{D}*"."{D}+({E})?{FS}?	{ return (process_float_literal(error)); }
{D}+"."{D}*({E})?{FS}?	{ return (process_float_literal(error)); }

L?\"(\\.|[^\\"])*\"	{ return (process_string_literal(error)); }

"..."		{ return (ELLIPSIS); }
">>="		{ return (RIGHT_ASSIGN); }
"<<="		{ return (LEFT_ASSIGN); }
"+="		{ return (ADD_ASSIGN); }
"-="		{ return (SUB_ASSIGN); }
"*="		{ return (MUL_ASSIGN); }
"/="		{ return (DIV_ASSIGN); }
"%="		{ return (MOD_ASSIGN); }
"&="		{ return (AND_ASSIGN); }
"^="		{ return (XOR_ASSIGN); }
"|="		{ return (OR_ASSIGN); }
">>"		{ return (RIGHT_OP); }
"<<"		{ return (LEFT_OP); }
"++"		{ return (INC_OP); }
"--"		{ return (DEC_OP); }
"->"		{ return (PTR_OP); }
"&&"		{ return (AND_OP); }
"||"		{ return (OR_OP); }
"<="		{ return (LE_OP); }
">="		{ return (GE_OP); }
"=="		{ return (EQ_OP); }
"!="		{ return (NE_OP); }
";"			{ return (';'); }
("{"|"<%")	{ return ('{'); }
("}"|"%>")	{ return ('}'); }
","			{ return (','); }
":"			{ return (':'); }
"="			{ return ('='); }
"("			{ return ('('); }
")"			{ return (')'); }
("["|"<:")	{ return ('['); }
("]"|":>")	{ return (']'); }
"."			{ return ('.'); }
"&"			{ return ('&'); }
"!"			{ return ('!'); }
"~"			{ return ('~'); }
"-"			{ return ('-'); }
"+"			{ return ('+'); }
"*"			{ return ('*'); }
"/"			{ return ('/'); }
"%"			{ return ('%'); }
"<"			{ return ('<'); }
">"			{ return ('>'); }
"^"			{ return ('^'); }
"|"			{ return ('|'); }
"?"			{ return ('?'); }

"#"\ {D}+\ \"([^\\"])*\"(\ [1234])* {
	if ((*error = handle_cpp_linemarkers(file)))
		return 0;
		
	dpv(yylloc.last_line);
	dpv(yylloc.last_column);
//	CHECK_NTH(5);
}

[\ \n\t\v\f] {}

. {
	fprintf(stderr, "%s: flex: unknown token starting with: '%s'!\n", argv0, yytext);
	return 0;
}

%%

int yywrap()
{
	return(1);
}


static int check_type(int* error, struct scope *scope)
{
	struct type* type = NULL;
	int retval;
	ENTER;
	
	dpvs(yytext);
	dpv(scope);
	
	if ((type = scope_lookup_type(scope, yytext)))
	{
		yylval.type = tinc(type);
		
		retval = TYPE_NAME;
	}
	else
	{
		dpvs(yytext);
		
		*error = tstrdup(&yylval.identifier, yytext);
		
		retval = IDENTIFIER;
	}
	
	tfree(type);
	
	EXIT;
	return *error ? 0 : retval;
}

static int handle_cpp_linemarkers(char** out_file)
{
	char* m;
	int error = 0;
	unsigned long line;
	char *start, *end;
	char* newfile;
	ENTER;
	
	dpvs(yytext);
	
	// extract line number:
	if (errno = 0, line = strtoul(yytext + 2, &m, 10),
		errno || *m != ' ' || line >= UINT_MAX)
	{
		fprintf(stderr, "%s: bad cpp #line!\n", argv0);
		error = e_bad_input_file;
	}
	else if (!(end = index((start = m + 2), '\"')))
	{
		fprintf(stderr, "%s: bad cpp #line!\n", argv0);
		error = e_bad_input_file;
	}
	
	if (!error)
		error = tstrndup(&newfile, start, end - start);
		
	if (!error)
	{
		dpv(line);
		dpvsn(start, end - start);
		
		char* oldfile = *out_file;
		dpvs(oldfile);
		tfree(oldfile);
		
		*out_file = newfile;
		
		yylloc.last_line = line - 1; // the '\n' right after will fix it
		yylloc.last_column = 1;
	}
	
	EXIT;
	return error;
}

static int process_integer_literal(int* error)
{
	int retval = 0;
	uintmax_t value;
	char* m;
	ENTER;
	
	errno = 0, value = strtoumax(yytext, &m, 0);
	
	dpv(value);
	
	// check for suffix? maybe limit the type?
	// literals could then have various-sized types,
	// not just {unsigned,} long
	
	bool is_unsigned = 0;
	int long_level = 0;
	
	for (; *m; m++)
	{
		switch (*m)
		{
			case 'u':
			case 'U':
				is_unsigned = 1;
				break;
				
			case 'l':
			case 'L':
				if (long_level++ == 1)
				{
					TODO; // "too many 'L's!"
					*error = 1;
				}
				break;
			
			default:
			{
				TODO; // "unknown integer suffix!"
				*error = 1;
			}
		}
	}
	
	if (errno)
	{
		fprintf(stderr, "%s: strtoumax(\"%s\"): %m\n", argv0, yytext),
		*error = e_bad_input_file;
	}
	
	static const int lookup[2][3] = {
		[0][0] = SINT_LITERAL,
		[0][1] = SLONG_LITERAL,
		[1][0] = UINT_LITERAL,
		[1][1] = ULONG_LITERAL,
	};
	
	if (!*error)
	{
		switch (retval = lookup[is_unsigned][long_level])
		{
			case  SINT_LITERAL: yylval.sintlit  = value; break;
			case  UINT_LITERAL: yylval.uintlit  = value; break;
			case SLONG_LITERAL: yylval.slonglit = value; break;
			case ULONG_LITERAL: yylval.ulonglit = value; break;
			
			default:
				TODO;
				break;
		}
	
	}
	
	EXIT;
	return *error ? 0 : retval;
}

static int process_character_literal(int* error)
{
	int retval = SINT_LITERAL;
	ENTER;
	
	dpvs(yytext);
	
	if (yytext[1] != '\\')
		yylval.sintlit = yytext[1];
	else switch (yytext[2])
	{
		default:
			TODO;
			break;
	}
	
	EXIT;
	return *error ? 0 : retval;
}

static int process_float_literal(int* error)
{
	int retval = DOUBLE_LITERAL;
	char* m;
	ENTER;
	
	errno = 0, yylval.doublelit = strtod(yytext, &m);
	
	if (errno || (*m != '\0' && *m != 'f'))
	{
		fprintf(stderr, "%s: strtold(\"%s\"): %m\n", argv0, yytext),
		*error = e_bad_input_file;
	}
	else if (*m == 'f')
	{
		retval = FLOAT_LITERAL;
		yylval.floatlit = yylval.doublelit;
	}
	
	EXIT;
	return *error ? 0 : retval;
}

static int process_string_literal(int* error)
{
	int retval = STRING_LITERAL;
	char *read;
	char *write;
	char* data = NULL;
	ENTER;
	
	dpvs(yytext);
	
	*error = tmalloc((void**) &data, strlen(yytext) + 1, NULL);
	
	for (read = yytext + 1, write = data; !*error && *read != '\"'; )
		if (*read != '\\')
			*write++ = *read++;
		else switch (*++read)
		{
			case 'n':
				*write++ = '\n', read++;
				break;
			
			case '\"':
				*write++ = '\"', read++;
				break;
			
			default:
				TODO;
				*error = e_bad_input_file;
				break;
		}
	
	if (!*error)
		*write++ = '\0';
	
	if (!*error)
	{
		dpvs(data);
		
		yylval.string.data = tinc(data);
		yylval.string.strlen = write - data;
	}
	
	tfree(data);
	
	EXIT;
	return *error ? 0 : retval;
}



















