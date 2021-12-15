
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
#include <memory/tinc.h>
#include <memory/tfree.h>

#include <scope/lookup/type.h>

#include "parser.h"

static int check_type();
static int process_integer_literal();
static int process_character_literal();
static int process_float_literal();
static int process_string_literal();

#define YY_DECL int yylex(struct scope *scope, unsigned* line)

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

{L}({L}|{D})*		{ return (check_type(scope)); }

0[xX]{H}+{IS}?		{ return (process_integer_literal()); }
0{D}+{IS}?			{ return (process_integer_literal()); }
{D}+{IS}?			{ return (process_integer_literal()); }
L?'(\\.|[^\\'])'	{ return (process_character_literal()); }

{D}+{E}{FS}?			{ return (process_float_literal()); }
{D}*"."{D}+({E})?{FS}?	{ return (process_float_literal()); }
{D}+"."{D}*({E})?{FS}?	{ return (process_float_literal()); }

L?\"(\\.|[^\\"])*\"	{ return (process_string_literal()); }

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

\n	{ (*line)++; }
[ \t\v\n\f]	{ }
.			{ /* ignore bad characters */ }

%%

int yywrap()
{
	return(1);
}


static int check_type(struct scope *scope)
{
	struct type* type = NULL;
	int retval;
	int error = 0;
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
		
		error = tstrdup(&yylval.identifier, yytext);
		
		retval = IDENTIFIER;
	}
	
	if (error)
	{
		// how do I pass this back?
		printf("error == %i\n", error);
		abort();
	}
	
	tfree(type);
	
	EXIT;
	return retval;
}

static int process_integer_literal()
{
	int retval = SINT_LITERAL;
	int error = 0;
	char* m;
	ENTER;
	
	errno = 0, yylval.sintegerlit = strtoul(yytext, &m, 0);
	
	if (errno) {
		fprintf(stderr, "%s: strtoul(\"%s\"): %m\n", argv0, yytext),
		error = e_bad_input_file;
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
			error = 1;
		}
	}
	
	if (error)
	{
		// how do I pass this back?
		printf("error == %i\n", error);
		abort();
	}
	
	EXIT;
	return retval;
}

static int process_character_literal()
{
	int retval = SINT_LITERAL;
	int error = 0;
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
	
	if (error)
	{
		// how do I pass this back?
		printf("error == %i\n", error);
		abort();
	}
	
	EXIT;
	return retval;
}

static int process_float_literal()
{
	int retval = FLOAT_LITERAL;
	int error = 0;
	char* m;
	ENTER;
	
	errno = 0, yylval.doublelit = strtod(yytext, &m);
	
	if (errno || *m)
		fprintf(stderr, "%s: strtold(\"%s\"): %m\n", argv0, yytext),
		error = e_bad_input_file;
	
	if (error)
	{
		// how do I pass this back?
		printf("error == %i\n", error);
		abort();
	}
	
	EXIT;
	return retval;
}

static int process_string_literal()
{
	int retval = STRING_LITERAL;
	int error = 0;
	char *read;
	char *write;
	char* data = NULL;
	ENTER;
	
	dpvs(yytext);
	
	error = tmalloc((void**) &data, strlen(yytext) + 1, NULL);
	
	for (read = yytext + 1, write = data; !error && *read != '\"'; )
		if (*read != '\\')
			*write++ = *read++;
		else switch (*++read)
		{
			case 'n':
				*write++ = '\n', read++;
				break;
			
			default:
				TODO;
				error = e_bad_input_file;
				break;
		}
	
	if (!error)
		*write++ = '\0';
	
	if (error)
	{
		// how do I pass this back?
		printf("error == %i\n", error);
		abort();
	}
	else
	{
		dpvs(data);
		
		yylval.string.data = tinc(data);
		yylval.string.strlen = write - data;
	}
	
	tfree(data);
	
	EXIT;
	return retval;
}



















