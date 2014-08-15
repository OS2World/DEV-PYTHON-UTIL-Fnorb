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
  File:         $Source: /units/arch/src/Fnorb/src/RCS/grammar.y,v $
  Version:      @(#)$RCSfile: grammar.y,v $ $Revision: 1.9 $


  Description:	Bison grammar for OMG IDL.

****************************************************************/

#include "Python.h"
#include "bisonmodule.h"

/* Forward declarations. */
void yyerror(char*);
void yywarning(char*);

/* The lexer function that returns tokens. */
int yylex();

/* The lexer returns all semantic values as Python objects! */
#define YYSTYPE PyObject*

/* This hack is required to use the generated parser on Win95/NT. */
#ifdef WIN32
#define MSDOS
#endif

%}

/* Keywords. */
%token IDL_ANY
%token ATTRIBUTE
%token BOOLEAN
%token CASE
%token CHAR
%token CONST
%token CONTEXT
%token DEFAULT
%token DOUBLE
%token ENUM
%token EXCEPTION
%token IDENTIFIER
%token IN
%token INOUT
%token INTERFACE
%token IDL_FALSE
%token FIXED
%token FLOAT
%token LONG
%token MODULE
%token NATIVE
%token OBJECT
%token OCTET
%token ONEWAY
%token OUT
%token PRAGMA
%token RAISES
%token READONLY
%token SCOPE_DELIMITER
%token SEQUENCE
%token SHORT
%token STRING
%token STRUCT
%token SWITCH
%token IDL_TRUE
%token TYPEDEF
%token UNION
%token UNSIGNED
%token VOID
%token WCHAR
%token WSTRING

/* Literals. */
%token CHARACTER_LITERAL
%token WIDE_CHARACTER_LITERAL
%token FLOATING_PT_LITERAL
%token INTEGER_LITERAL
%token STRING_LITERAL
%token WIDE_STRING_LITERAL
%token FIXED_PT_LITERAL

/* Operators. */
%token LEFT_SHIFT
%token RIGHT_SHIFT

%%

start:			/* empty */
                        |
                        specification
;

specification:          {
			    CALL_0("specification_start");
			    CHECK_EXCEPTION;
                        }
                        definition_PLUS
                        {
			    CALL_0("specification_end");
			    CHECK_EXCEPTION;
                        }
;

definition_PLUS:	definition
			|
			definition definition_PLUS
;

definition:	        type_dcl ';'
                        |
                        const_dcl ';'
                        |
                        except_dcl ';'
                        |
                        interface ';'
                        |
                        module ';'
                        |
                        PRAGMA
                        {
			    CALL_1("pragma", $1);
			    CHECK_EXCEPTION;
                        }
;

module:			MODULE IDENTIFIER
                        {
			    CALL_1("module_header", $2);
			    CHECK_EXCEPTION;
			}
                        '{' definition_PLUS '}'
                        {
			    CALL_0("module_body");
			    CHECK_EXCEPTION;
			}
;

interface:              interface_dcl
                        |
                        forward_dcl
;

interface_dcl:          INTERFACE IDENTIFIER inheritance_spec
                        {
			    $$ = CALL_2("interface_dcl_header", $2, $3);
			    CHECK_EXCEPTION;
			}
                        '{' export_STAR '}'
                        {
			    CALL_1("interface_dcl_body", $4);
			    CHECK_EXCEPTION;
			}
;

forward_dcl:		INTERFACE IDENTIFIER
                        {
			    CALL_1("foward_dcl", $2);
			    CHECK_EXCEPTION;
			}
;

export_STAR:		/* empty */
                        |
                        export export_STAR
;

export:			type_dcl ';'
                        |
                        const_dcl ';'
                        |
                        except_dcl ';'
                        |
                        attr_dcl ';'
                        |
                        op_dcl ';'
                        |
                        PRAGMA
                        {
			    CALL_1("pragma", $1);
			    CHECK_EXCEPTION;
                        }
;

inheritance_spec:       /* empty */
                        {
			    $$ = CALL_0("inheritance_spec_empty");
			    CHECK_EXCEPTION;
                        }
                        |
			':' scoped_name_CSV_PLUS
                        {
			    $$ = CALL_1("inheritance_spec_full", $2);
			    CHECK_EXCEPTION;
			}
;

scoped_name_CSV_PLUS:   scoped_name scoped_name_CSV
                        {
			    $$ = CALL_2("list_insert", $1, $2);
			    CHECK_EXCEPTION;
			}
;

scoped_name_CSV:	/* empty */
                        {
			    $$ = CALL_0("list_empty");
			    CHECK_EXCEPTION;
			}
                        |
			',' scoped_name scoped_name_CSV
                        {
			    $$ = CALL_2("list_insert", $2, $3);
			    CHECK_EXCEPTION;
			}
;

scoped_name:		IDENTIFIER
                        |
                        SCOPE_DELIMITER IDENTIFIER
                        {
			    $$ = CALL_1("scoped_name_absolute", $2);
			    CHECK_EXCEPTION;
                        }
                        |
                        scoped_name SCOPE_DELIMITER IDENTIFIER
                        {
			    $$ = CALL_2("scoped_name_relative", $1, $3);
			    CHECK_EXCEPTION;
			}
;

const_dcl:		CONST const_type IDENTIFIER '=' const_expr
                        {
			    $$ = CALL_3("const_dcl", $2, $3, $5);
			    CHECK_EXCEPTION;
			}
;

const_type:		integer_type
                        |
                        char_type
                        |
                        wide_char_type
                        |
                        boolean_type
                        |
                        floating_pt_type
                        |
                        string_type
                        |
                        wide_string_type
                        |
                        fixed_pt_const_type
                        |
                        scoped_name
                        {
			    $$ = CALL_1("const_type_scoped_name", $1);
			    CHECK_EXCEPTION;
			}
;

const_expr:             or_expr
;

or_expr:                xor_expr
                        |
                        or_expr '|' xor_expr
                        {
			    $$ = CALL_2("or_expr", $1, $3);
			    CHECK_EXCEPTION;
			}
;

xor_expr:               and_expr
                        |
                        xor_expr '^' and_expr
                        {
			    $$ = CALL_2("xor_expr", $1, $3);
			    CHECK_EXCEPTION;
			}
;

and_expr:		shift_expr
                        |
                        and_expr '&' shift_expr
                        {
			    $$ = CALL_2("and_expr", $1, $3);
			    CHECK_EXCEPTION;
			}
;

shift_expr:		add_expr
                        |
                        shift_expr RIGHT_SHIFT add_expr
                        {
			    $$ = CALL_2("shift_expr_right", $1, $3);
			    CHECK_EXCEPTION;
			}
                        |
                        shift_expr LEFT_SHIFT add_expr
                        {
			    $$ = CALL_2("shift_expr_left", $1, $3);
			    CHECK_EXCEPTION;
			}
;

add_expr: 		mult_expr
                        |
                        add_expr '+' mult_expr
                        {
			    $$ = CALL_2("add_expr_add", $1, $3);
			    CHECK_EXCEPTION;
			}
                        |
                        add_expr '-' mult_expr
                        {
			    $$ = CALL_2("add_expr_subtract", $1, $3);
			    CHECK_EXCEPTION;
			}
;

mult_expr:              unary_expr
                        |
                        mult_expr '*' unary_expr
                        {
			    $$ = CALL_2("mult_expr_multiply", $1, $3);
			    CHECK_EXCEPTION;
			}
                        |
                        mult_expr '/' unary_expr
                        {
			    $$ = CALL_2("mult_expr_divide", $1, $3);
			    CHECK_EXCEPTION;
			}
                        |
                        mult_expr '%' unary_expr
                        {
			    $$ = CALL_2("mult_expr_mod", $1, $3);
			    CHECK_EXCEPTION;
			}
;

unary_expr:             '-' primary_expr
                        {
			    $$ = CALL_1("unary_expr_neg", $2);
			    CHECK_EXCEPTION;
			}
                        |
                        '+' primary_expr 
                        {
			    $$ = CALL_1("unary_expr_pos", $2);
			    CHECK_EXCEPTION;
			}
                        |
                        '~' primary_expr
                        {
			    $$ = CALL_1("unary_expr_invert", $2);
			    CHECK_EXCEPTION;
			}
                        |
                        primary_expr
;

primary_expr:		scoped_name
                        {
			    $$ = CALL_1("primary_expr_scoped_name", $1);
			    CHECK_EXCEPTION;
			}
                        |
                        literal
                        |
                        '(' const_expr ')'
;

literal:		integer_literal
                        |
                        STRING_LITERAL
                        {
			    $$ = CALL_1("literal_string_literal", $1);
			    CHECK_EXCEPTION;
			}
                        |
                        CHARACTER_LITERAL
                        {
			    $$ = CALL_1("literal_character_literal", $1);
			    CHECK_EXCEPTION;
			}
                        |
                        FIXED_PT_LITERAL
                        {
			    $$ = CALL_1("literal_fixed_pt_literal", $1);
			    CHECK_EXCEPTION;
			}
                        |
                        FLOATING_PT_LITERAL
                        {
			    $$ = CALL_1("literal_floating_pt_literal", $1);
			    CHECK_EXCEPTION;
			}
                        |
                        boolean_literal
;

integer_literal:        INTEGER_LITERAL
                        {
			    $$ = CALL_1("literal_integer_literal", $1);
			    CHECK_EXCEPTION;
			}
;

boolean_literal:	IDL_TRUE
                        {
			    $$ = CALL_0("boolean_literal_true");
			    CHECK_EXCEPTION;
			}
                        |
                        IDL_FALSE
                        {
			    $$ = CALL_0("boolean_literal_false");
			    CHECK_EXCEPTION;
			}
;

positive_int_const:     const_expr
                        {
			    $$ = CALL_1("positive_int_const", $1);
			    CHECK_EXCEPTION;
			}
;

type_dcl:		TYPEDEF type_declarator
                        |
                        struct_type
                        |
                        union_type
                        |
                        enum_type
                        |
                        NATIVE simple_declarator
                        {
			    $$ = CALL_1("native_type_dcl", $2);
			    CHECK_EXCEPTION;
			}
;

type_declarator:	type_spec declarator_CSV_PLUS
                        {
			    CALL_2("type_declarator", $1, $2);
			    CHECK_EXCEPTION;
			}
;

type_spec:		simple_type_spec
                        |
                        constr_type_spec
;

simple_type_spec:	base_type_spec
                        |
                        template_type_spec
                        |
                        scoped_name
                        {
			    $$ = CALL_1("idl_type_scoped_name", $1);
			    CHECK_EXCEPTION;
			}
;

base_type_spec:	        floating_pt_type
                        |
                        integer_type
                        |
                        char_type
                        |
                        wide_char_type
                        |
                        boolean_type
                        |
                        octet_type
                        |
                        any_type
                        |
                        object_type
;

template_type_spec:	sequence_type
                        |
                        string_type
                        |
                        wide_string_type
                        |
                        fixed_pt_type
;

constr_type_spec:       struct_type
                        |
                        union_type
                        |
                        enum_type
;

declarator_CSV_PLUS:	declarator declarator_CSV
                        {
			    $$ = CALL_2("list_insert", $1, $2);
			    CHECK_EXCEPTION;
			}
;

declarator_CSV:		/* empty */
                        {
			    $$ = CALL_0("list_empty");
			    CHECK_EXCEPTION;
			}
                        |
                        ',' declarator declarator_CSV
                        {
			    $$ = CALL_2("list_insert", $2, $3);
			    CHECK_EXCEPTION;
			}
;

declarator:		simple_declarator
                        |
                        array_declarator
;

simple_declarator:      IDENTIFIER
                        {
			    $$ = CALL_1("simple_declarator", $1);
			    CHECK_EXCEPTION;
			}
;

floating_pt_type:	FLOAT
                        {
			    $$ = CALL_0("float_type");
			    CHECK_EXCEPTION;
			}
                        |
			DOUBLE
                        {
			    $$ = CALL_0("double_type");
			    CHECK_EXCEPTION;
			}
                        |
			LONG DOUBLE
                        {
			    $$ = CALL_0("longdouble_type");
			    CHECK_EXCEPTION;
			}
;

integer_type:		signed_int
                        |
			unsigned_int
;

signed_int:		signed_short_int
                        |
                        signed_long_int
                        |
                        signed_longlong_int
;

signed_short_int:	SHORT
                        {
			    $$ = CALL_0("signed_short_int");
			    CHECK_EXCEPTION;
			}
;

signed_long_int:	LONG
                        {
			    $$ = CALL_0("signed_long_int");
			    CHECK_EXCEPTION;
			}
;

signed_longlong_int:	LONG LONG
                        {
			    $$ = CALL_0("signed_longlong_int");
			    CHECK_EXCEPTION;
			}
;

unsigned_int:	        unsigned_short_int
                        |
                        unsigned_long_int
                        |
                        unsigned_longlong_int
;

unsigned_short_int:	UNSIGNED SHORT
                        {
			    $$ = CALL_0("unsigned_short_int");
			    CHECK_EXCEPTION;
			}
;

unsigned_long_int:	UNSIGNED LONG
                        {
			    $$ = CALL_0("unsigned_long_int");
			    CHECK_EXCEPTION;
			}
;

unsigned_longlong_int:	UNSIGNED LONG LONG
                        {
			    $$ = CALL_0("unsigned_longlong_int");
			    CHECK_EXCEPTION;
			}
;

char_type:		CHAR
                        {
			    $$ = CALL_0("char_type");
			    CHECK_EXCEPTION;
			}
;

wide_char_type:		WCHAR
                        {
			    $$ = CALL_0("wide_char_type");
			    CHECK_EXCEPTION;
			}
;

boolean_type:		BOOLEAN
                        {
			    $$ = CALL_0("boolean_type");
			    CHECK_EXCEPTION;
			}
;

octet_type:		OCTET
                        {
			    $$ = CALL_0("octet_type");
			    CHECK_EXCEPTION;
			}
;

any_type:		IDL_ANY
                        {
			    $$ = CALL_0("any_type");
			    CHECK_EXCEPTION;
			}
;

object_type:		OBJECT
                        {
			    $$ = CALL_0("object_type");
			    CHECK_EXCEPTION;
			}
;

struct_type:		STRUCT IDENTIFIER
                        {
			    $$ = CALL_1("struct_type_header", $2);
			    CHECK_EXCEPTION;
			}
                        '{' member_PLUS '}'
                        {
			    $$ = CALL_2("struct_type_body", $3, $5);
			    CHECK_EXCEPTION;
			}
;

member_PLUS:		member member_STAR
                        {
			    $$ = CALL_2("list_insert", $1, $2);
			    CHECK_EXCEPTION;
			}
;

member_STAR:		/* empty */
                        {
			    $$ = CALL_0("list_empty");
			    CHECK_EXCEPTION;
			}
                        |
                        member member_STAR
                        {
			    $$ = CALL_2("list_insert", $1, $2);
			    CHECK_EXCEPTION;
			}
;

member:			type_spec declarator_CSV_PLUS ';'
                        {
			    $$ = CALL_2("member", $1, $2);
			    CHECK_EXCEPTION;
			}

;

union_type:		UNION IDENTIFIER SWITCH '(' switch_type_spec ')'
                        {
			    $$ = CALL_2("union_type_header", $2, $5);
			    CHECK_EXCEPTION;
			}
                        '{' case_PLUS '}'
                        {
			    $$ = CALL_2("union_type_body", $7, $9);
			    CHECK_EXCEPTION;
			}
;

switch_type_spec:	integer_type
                        |
                        char_type
                        |
                        boolean_type
                        |
                        enum_type
                        |
                        scoped_name
                        {
			    $$ = CALL_1("switch_type_spec_scoped_name", $1);
			    CHECK_EXCEPTION;
			}
;

case_PLUS:		case case_STAR
                        {
			    $$ = CALL_2("list_insert", $1, $2);
			    CHECK_EXCEPTION;
			}
;

case_STAR:		/* empty */
                        {
			    $$ = CALL_0("list_empty");
			    CHECK_EXCEPTION;
			}
                        |
                        case case_STAR
                        {
			    $$ = CALL_2("list_insert", $1, $2);
			    CHECK_EXCEPTION;
			}
;              

case:                   case_label_PLUS element_spec ';'
                        {
			    $$ = CALL_2("case", $1, $2);
			    CHECK_EXCEPTION;
			}
;

case_label_PLUS:	case_label case_label_STAR
                        {
			    $$ = CALL_2("list_insert", $1, $2);
			    CHECK_EXCEPTION;
			}
;

case_label_STAR:	/* empty */
                        {
			    $$ = CALL_0("list_empty");
			    CHECK_EXCEPTION;
			}
                        |
                        case_label case_label_STAR
                        {
			    $$ = CALL_2("list_insert", $1, $2);
			    CHECK_EXCEPTION;
			}
;

case_label:		CASE const_expr ':'
                        {
			    $$ = $2;
			}
                        |
                        DEFAULT ':'
                        {
			    $$ = CALL_0("case_label_default");
			    CHECK_EXCEPTION;
			}
;

element_spec:           type_spec declarator
                        {
			    $$ = CALL_2("element_spec", $1, $2);
			    CHECK_EXCEPTION;
			}
;

enum_type:		ENUM IDENTIFIER
                        {
			    $$ = CALL_1("enum_type_header", $2);
			    CHECK_EXCEPTION;
			}
                        '{' enumerator_CSV_PLUS '}'
                        {
			    $$ = CALL_2("enum_type_body", $3, $5);
			    CHECK_EXCEPTION;
			}
;

enumerator_CSV_PLUS:	enumerator enumerator_CSV_STAR
                        {
			    $$ = CALL_2("list_insert", $1, $2);
			    CHECK_EXCEPTION;
			}
;

enumerator_CSV_STAR:	/* empty */
                        {
			    $$ = CALL_0("list_empty");
			    CHECK_EXCEPTION;
			}
                        |
                        ',' enumerator enumerator_CSV_STAR
                        {
			    $$ = CALL_2("list_insert", $2, $3);
			    CHECK_EXCEPTION;
			}
;

enumerator:		IDENTIFIER
;

sequence_type:	        SEQUENCE '<'simple_type_spec ',' positive_int_const'>'
                        {
			    $$ = CALL_2("sequence_type", $3, $5);
			    CHECK_EXCEPTION;
			}
                        |
                        SEQUENCE '<' simple_type_spec '>'
                        {
			    $$ = CALL_1("sequence_type", $3);
			    CHECK_EXCEPTION;
			}
;

string_type:		STRING '<' positive_int_const '>'
                        {
			    $$ = CALL_1("string_type", $3);
			    CHECK_EXCEPTION;
			}
                        |
                        STRING
                        {
			    $$ = CALL_0("string_type");
			    CHECK_EXCEPTION;
			}
;

wide_string_type:	WSTRING '<' positive_int_const '>'
                        {
			    $$ = CALL_1("wide_string_type", $3);
			    CHECK_EXCEPTION;
			}
                        |
                        WSTRING
                        {
			    $$ = CALL_0("wide_string_type");
			    CHECK_EXCEPTION;
			}
;

array_declarator:	IDENTIFIER fixed_array_size_PLUS
                        {
			    $$ = CALL_2("array_declarator", $1, $2);
			    CHECK_EXCEPTION;
			}
;

fixed_array_size_PLUS:	fixed_array_size fixed_array_size_STAR
                        {
			    $$ = CALL_2("list_insert", $1, $2);
			    CHECK_EXCEPTION;
			}
;

fixed_array_size_STAR:  /* empty */
                        {
			    $$ = CALL_0("list_empty");
			    CHECK_EXCEPTION;
			}
                        |
			fixed_array_size fixed_array_size_STAR
                        {
			    $$ = CALL_2("list_insert", $1, $2);
			    CHECK_EXCEPTION;
			}
;

fixed_array_size:	'[' positive_int_const ']'
                        {
			    $$ = CALL_1("fixed_array_size", $2);
			    CHECK_EXCEPTION;
			}
;

attr_dcl:		readonly_OPT ATTRIBUTE param_type_spec
                        simple_declarator_CSV_PLUS
                        {
			    CALL_3("attr_dcl", $1, $3, $4);
			    CHECK_EXCEPTION;
			}

readonly_OPT:		/* empty */
                        {
			    $$ = CALL_0("readonly_OPT_normal");
			    CHECK_EXCEPTION;
			}
                        |
                        READONLY
                        {
			    $$ = CALL_0("readonly_OPT_readonly");
			    CHECK_EXCEPTION;
			}
;

simple_declarator_CSV_PLUS: simple_declarator simple_declarator_CSV_STAR
                          {
			      $$ = CALL_2("list_insert", $1, $2);
			      CHECK_EXCEPTION;
			  }
;

simple_declarator_CSV_STAR: /* empty */
                          {
			      $$ = CALL_0("list_empty");
			      CHECK_EXCEPTION;
			  }
                          |
                          ',' simple_declarator simple_declarator_CSV_STAR
                          {
			      $$ = CALL_2("list_insert",$1, $2);
			      CHECK_EXCEPTION;
			  }
;

except_dcl:		EXCEPTION IDENTIFIER
                        {
			    $$ = CALL_1("except_dcl_header", $2);
			    CHECK_EXCEPTION;
			}
                        '{' member_STAR '}'
                        {
			    CALL_2("except_dcl_body", $3, $5);
			    CHECK_EXCEPTION;
			}
;

op_dcl:			op_attribute_OPT op_type_spec IDENTIFIER
                        {
			    $$ = CALL_3("op_dcl_header", $1, $2, $3);
			    CHECK_EXCEPTION;
			}
			parameter_dcls raises_expr_OPT context_expr_OPT
                        {
			    CALL_4("op_dcl_body", $4, $5, $6, $7);
			    CHECK_EXCEPTION;
			}
;

op_attribute_OPT:	/* empty */
                        {
			    $$ = CALL_0("op_attribute_OPT_empty");
			    CHECK_EXCEPTION;
			}
                        |
                        ONEWAY
                        {
			    $$ = CALL_0("op_attribute_OPT_oneway");
			    CHECK_EXCEPTION;
			}
;

op_type_spec:		param_type_spec
                        |
                        VOID
                        {
			    $$ = CALL_0("op_type_spec_void");
			    CHECK_EXCEPTION;
			}
;

parameter_dcls:		'(' param_dcl_CSV_PLUS ')'
                        {
			    $$ = $2;
			}
                        |
                        '(' ')'
                        {
			    $$ = CALL_0("parameter_dcls_empty");
			    CHECK_EXCEPTION;
			}
;

param_dcl_CSV_PLUS:	param_dcl param_dcl_CSV_STAR
                        {
			    $$ = CALL_2("list_insert", $1, $2);
			    CHECK_EXCEPTION;
			}

param_dcl_CSV_STAR:	/* empty */
                        {
			    $$ = CALL_0("list_empty");
			    CHECK_EXCEPTION;
			}
                        |
                        ',' param_dcl param_dcl_CSV_STAR
                        {
			    $$ = CALL_2("list_insert", $2, $3);
			    CHECK_EXCEPTION;
			}
;

param_dcl:		param_attribute param_type_spec simple_declarator
                        {
			    $$ = CALL_3("param_dcl", $1, $2, $3);
			    CHECK_EXCEPTION;
			}
;

param_attribute:	IN
                        {
			    $$ = CALL_0("param_attribute_in");
			    CHECK_EXCEPTION;
			}
                        |
                        OUT
                        {
			    $$ = CALL_0("param_attribute_out");
			    CHECK_EXCEPTION;
			}
                        |
                        INOUT
                        {
			    $$ = CALL_0("param_attribute_inout");
			    CHECK_EXCEPTION;
			}
;

raises_expr_OPT:	/* empty */
                        {
			    $$ = CALL_0("raises_expr_OPT_empty");
			    CHECK_EXCEPTION;
			}
                        |
                        raises_expr
;

raises_expr:		RAISES '(' scoped_name_CSV_PLUS ')'
                        {
			    $$ = CALL_1("raises_expr", $3);
			    CHECK_EXCEPTION;
			}
;

context_expr_OPT:	/* empty */
                        {
			    $$ = CALL_0("context_expr_OPT_empty");
			    CHECK_EXCEPTION;
			}
                        |
                        context_expr
;

context_expr:		CONTEXT '(' string_literal_CSV_PLUS ')'
                        {
			    $$ = CALL_1("context_expr", $3);
			    CHECK_EXCEPTION;
                        }
;

string_literal_CSV_PLUS:STRING_LITERAL string_literal_CSV_STAR
                        {
			    $$ = CALL_2("list_insert", $1, $2);
			    CHECK_EXCEPTION;
			}

string_literal_CSV_STAR:/* empty */
                        {
			    $$ = CALL_0("list_empty");
			    CHECK_EXCEPTION;
			}
                        |
                        ',' STRING_LITERAL string_literal_CSV_STAR
                        {
			    $$ = CALL_2("list_insert", $2, $3);
			    CHECK_EXCEPTION;
		        }
;

param_type_spec:        base_type_spec
                        |
                        string_type
                        |
                        wide_string_type
                        |
                        fixed_pt_type
                        |
                        scoped_name
                        {
			    $$ = CALL_1("idl_type_scoped_name", $1);
			    CHECK_EXCEPTION;
			}
;

fixed_pt_type:		FIXED '<' positive_int_const ',' integer_literal '>'
                        {
			    $$ = CALL_2("fixed_pt_type", $3, $5);
			    CHECK_EXCEPTION;
			}
;

fixed_pt_const_type:    FIXED
                        {
			    $$ = CALL_0("fixed_pt_const_type");
			    CHECK_EXCEPTION;
			}
;

%%

void
yyerror(char* s)
{
    CALL_1("yyerror", PyString_FromString(s));
}

void
yywarning(char* s)
{
    CALL_1("yywarning", PyString_FromString(s));
}

/***************************************************************/
/* end of grammar.y */
