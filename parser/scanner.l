
D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%{

#include <stdio.h>

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
static int handle_cpp_linemarkers(char** file, unsigned* line);
static int process_integer_literal(int*);
static int process_character_literal(int*);
static int process_float_literal(int*);
static int process_string_literal(int*);

#define YY_DECL int yylex(int* error, struct scope *scope, char** file, unsigned* line)

%}

%x COMMENT

%option nounput
%option noinput

%%

 // From http://westes.github.io/flex/manual/Start-Conditions.html: //

"/*"                    BEGIN(COMMENT);
<COMMENT>[^*\n]*        /* eat anything that's not a '*' */
<COMMENT>"*"+[^*/\n]*   /* eat up '*'s not followed by '/'s */
<COMMENT>\n             ;
<COMMENT>"*"+"/"        BEGIN(INITIAL);

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
	if ((*error = handle_cpp_linemarkers(file, line)))
		return 0;
}

\n	{ (*line)++; }

[ \t\v\n\f]	{ }

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

static int handle_cpp_linemarkers(char** out_file, unsigned* out_line)
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
		*out_line = line;
	}
	
	EXIT;
	return error;
}

static int process_integer_literal(int* error)
{
	int retval = SINT_LITERAL;
	char* m;
	ENTER;
	
	errno = 0, yylval.sintegerlit = strtoul(yytext, &m, 0);
	
	if (errno || *m)
	{
		fprintf(stderr, "%s: strtoul(\"%s\"): %m\n", argv0, yytext),
		*error = e_bad_input_file;
	}
	else
	{
		// check for suffix? maybe limit the type?
		// literals could then have various-sized types,
		// not just {unsigned,} long
		
		if (*m && index("uU", *m))
			retval = UINT_LITERAL, m++,
			yylval.uintegerlit = yylval.sintegerlit;
		
		if (*m && index("lL", *m))
		{
			TODO;
		}
		
		if (*m && index("lL", *m))
		{
			TODO;
		}
		
		if (*m)
		{
			TODO; // "unknown integer suffix!"
			*error = 1;
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
		yylval.sintegerlit = yytext[1];
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



















