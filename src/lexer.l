%{

/***************************************************************

  Copyright (C) DSTC Pty Ltd (ACN 052 372 577) 1997, 1998, 1999
  Unpublished work.  All Rights Reserved.

  The software contained on this media is the property of the
  DSTC Pty Ltd.  Use of this software is strictly in accordance
  with the license agreement in the accompanying LICENSE.HTML
  file.  If your distribution of this software does not contain
  a LICENSE.HTML file then you have no rights to use this
  software in any manner and should contact DSTC at the address
  below to determine an appropriate licensing arrangement.

     DSTC Pty Ltd
     Level 7, GP South
     Staff House Road
     University of Queensland
     St Lucia, 4072
     Australia
     Tel: +61 7 3365 4310
     Fax: +61 7 3365 4311
     Email: enquiries@dstc.edu.au

  This software is being provided "AS IS" without warranty of
  any kind.  In no event shall DSTC Pty Ltd be liable for
  damage of any kind arising out of or in connection with
  the use or performance of this software.


  Project:      Fnorb
  File:         $Source: /units/arch/src/Fnorb/src/RCS/lexer.l,v $
  Version:      @(#)$RCSfile: lexer.l,v $ $Revision: 1.7 $


  Description:	Flex lexer for OMG IDL.

****************************************************************/

#include <stdlib.h>
#include <errno.h>
#include "Python.h"

/* The lexer returns all semantic values as Python objects! */
#define YYSTYPE PyObject*

/* Convenience macro to return 'yytext' as a Python string object. */
#define PY_YYTEXT PyString_FromString(yytext)

#include "grammar.h"
#include "bisonmodule.h"

/* Function defined in 'grammar.y'. */
void yywarning(char*);

/* Forward declarations. */
/*PyObject* integer_literal(const char*, const int);*/
PyObject* floating_point_literal(const char*);

%}

%option noyywrap
%option yylineno

WHITESPACE	([ \t\v\n\f])
SPACE           ([ \t])

LETTER		([a-zA-Z])
DIGIT		([0-9])
ALPHA		([a-zA-Z0-9_])
IDENT		({LETTER}{ALPHA}*)

HEX             ([a-fA-F0-9])
OCT             ([0-7])
EXPONENT        ([Ee][+-]?{DIGIT}+)
FS              ([lLfF])
IS              ([lLuU])
FX              ([dD])

%% 

"#"{SPACE}*"ident".*\n {
    /*
     * '#ident' directive.
     */
}

"#"{SPACE}*"pragma".*\n	{
    /*
     * '#pragma' directive.
     *
     * e.g. "# pragma prefix "dstc.edu.au"
     */
    yylval = PY_YYTEXT;
    return PRAGMA;
}

"#"{SPACE}*{DIGIT}+{SPACE}+"$pragma".*\n {
    /*
     * '#pragma' directive.
     *
     * e.g. "# 1 pragma prefix "dstc.edu.au"
     */
    yylval = PY_YYTEXT;
    return PRAGMA;
}

"#"{SPACE}*{DIGIT}+{SPACE}*\n {
    /*
     * Line/file directive.
     *
     * e.g. "# 1"
     */
    CALL_1("line_directive", PY_YYTEXT);
}

"#"{SPACE}*{DIGIT}+{SPACE}+"\""[^\"]*"\"".*\n {
    /*
     * Line/file directive.
     *
     * e.g. "# 1 filename.idl"
     */
    CALL_1("line_directive", PY_YYTEXT);
}

"#"{SPACE}*"line"{SPACE}+{DIGIT}+{SPACE}*\n {
    /*
     * '#line' directive.
     *
     * e.g. "# line 1"
     */
    CALL_1("line_directive", PY_YYTEXT);
}

"#"{SPACE}*"line"{SPACE}+{DIGIT}+{SPACE}+"\""[^\"]*"\"".*\n {
    /*
     * '#line' directive.
     *
     * e.g. "# line 1 "filename.idl"
     */
    CALL_1("line_directive", PY_YYTEXT);
}

"//".*\n {
    /*
     * C++ style comments.
     */
}

"/*" {
    /*
     * C style comments.
     */
    while (1)
    {
	int c = input();
	if (c == '*')
	{
	    int next = input();
	    if (next == '/')
	    {
		break;
	    }
	    else
	    {
		unput(next);
	    }
	}
	else if (c == EOF)
	{
	    yywarning("End of file in comment");
	    break;
	}
    }
}

any                     return IDL_ANY;
attribute               return ATTRIBUTE;
boolean                 return BOOLEAN;
case                    return CASE;
char                    return CHAR;
const                   return CONST;
context                 return CONTEXT;
default                 return DEFAULT;
double                  return DOUBLE;
enum                    return ENUM;
exception               return EXCEPTION;
fixed                   return FIXED;
float                   return FLOAT;
in                      return IN;
inout                   return INOUT;
interface               return INTERFACE;
long                    return LONG;
module		        return MODULE;
native                  return NATIVE;
Object                  return OBJECT;
octet                   return OCTET;
oneway                  return ONEWAY;
out                     return OUT;
raises                  return RAISES;
readonly                return READONLY;
sequence                return SEQUENCE;
short                   return SHORT;
string                  return STRING;
struct			return STRUCT;
switch                  return SWITCH;
typedef                 return TYPEDEF;
union                   return UNION;
unsigned                return UNSIGNED;
void                    return VOID;
wchar                   return WCHAR;
wstring                 return WSTRING;

FALSE			return IDL_FALSE;
TRUE			return IDL_TRUE;

"<<"                    return LEFT_SHIFT;
">>"                    return RIGHT_SHIFT;
::                      return SCOPE_DELIMITER;

{IDENT}                 {
                            yylval = PY_YYTEXT;
    			    return IDENTIFIER;
		        }

{DIGIT}+{IS}?		{
    /*                           
                           yylval = integer_literal(yytext, 10);
    */
                           yylval = PY_YYTEXT;
                           return INTEGER_LITERAL;
			}

0[xX]{HEX}+{IS}?	{
    /*
                            yylval = integer_literal(yytext + 2, 16);
    */
                            yylval = PY_YYTEXT;
                            return INTEGER_LITERAL;
                        }

0{OCT}+{IS}?		{
    /*
                            yylval = integer_literal(yytext + 1, 8);
    */
                            yylval = PY_YYTEXT;
                            return INTEGER_LITERAL;
			}

"'"\\({OCT}{1,3})"'"	{
			    yylval = PY_YYTEXT;
                            return CHARACTER_LITERAL;
			}

"'"\\x({HEX}{1,2})"'"	{
			    yylval = PY_YYTEXT;
                            return CHARACTER_LITERAL;
			}

"'"\\."'"		{
			    yylval = PY_YYTEXT;
                            return CHARACTER_LITERAL;
			}

"'"."'"			{
                            yylval = PY_YYTEXT;
                            return CHARACTER_LITERAL;
			}

{DIGIT}+{EXPONENT}{FS}?	{
                            yylval = floating_point_literal(yytext);
                            return FLOATING_PT_LITERAL;
			}

{DIGIT}*"."{DIGIT}+{EXPONENT}?{FS}? {
                            yylval = floating_point_literal(yytext);
                            return FLOATING_PT_LITERAL;
			}

{DIGIT}+"."{DIGIT}*{EXPONENT}?{FS}? {
                            yylval = floating_point_literal(yytext);
                            return FLOATING_PT_LITERAL;
			}

{DIGIT}+"."{DIGIT}*{FX} {
                            yylval = PY_YYTEXT;
                            return FIXED_PT_LITERAL;
			}

{DIGIT}*"."{DIGIT}+{FX} {
                            yylval = PY_YYTEXT;
                            return FIXED_PT_LITERAL;
			}

{DIGIT}+{FX}            {
                            yylval = PY_YYTEXT;
                            return FIXED_PT_LITERAL;
			}

"\""([^\"]|"\\\"")*"\""	{
			    yylval = PY_YYTEXT;
	                    return STRING_LITERAL;
			}

{WHITESPACE}		{
    			    /* Ignore whitespace. */
                        }

.			{
                            /* Single character tokens (e.g. '{', ';' etc) */
                            return yytext[0];
		        }

%%

/*
PyObject*
integer_literal(const char* str, const int base)
{
   long value = strtoul(str, NULL, base);
   if(errno == ERANGE)
    {
	yywarning("Integer literal out of range");
    }

    return PyInt_FromLong(value);
}
*/

PyObject*
floating_point_literal(const char* str)
{
    double value = strtod(str, NULL);
    if(errno == ERANGE)
    {
	yywarning("Floating point literal out of range");
    }

    return PyFloat_FromDouble(value);
}

/***************************************************************/
/* end of lexer.l */
