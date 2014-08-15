
/*  A Bison parser, made from grammar.y
 by  GNU Bison version 1.25
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	IDL_ANY	258
#define	ATTRIBUTE	259
#define	BOOLEAN	260
#define	CASE	261
#define	CHAR	262
#define	CONST	263
#define	CONTEXT	264
#define	DEFAULT	265
#define	DOUBLE	266
#define	ENUM	267
#define	EXCEPTION	268
#define	IDENTIFIER	269
#define	IN	270
#define	INOUT	271
#define	INTERFACE	272
#define	IDL_FALSE	273
#define	FIXED	274
#define	FLOAT	275
#define	LONG	276
#define	MODULE	277
#define	NATIVE	278
#define	OBJECT	279
#define	OCTET	280
#define	ONEWAY	281
#define	OUT	282
#define	PRAGMA	283
#define	RAISES	284
#define	READONLY	285
#define	SCOPE_DELIMITER	286
#define	SEQUENCE	287
#define	SHORT	288
#define	STRING	289
#define	STRUCT	290
#define	SWITCH	291
#define	IDL_TRUE	292
#define	TYPEDEF	293
#define	UNION	294
#define	UNSIGNED	295
#define	VOID	296
#define	WCHAR	297
#define	WSTRING	298
#define	CHARACTER_LITERAL	299
#define	WIDE_CHARACTER_LITERAL	300
#define	FLOATING_PT_LITERAL	301
#define	INTEGER_LITERAL	302
#define	STRING_LITERAL	303
#define	WIDE_STRING_LITERAL	304
#define	FIXED_PT_LITERAL	305
#define	LEFT_SHIFT	306
#define	RIGHT_SHIFT	307

#line 1 "grammar.y"


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

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		334
#define	YYFLAG		-32768
#define	YYNTBASE	74

#define YYTRANSLATE(x) ((unsigned)(x) <= 307 ? yytranslate[x] : 184)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,    66,    61,     2,    68,
    69,    64,    62,    57,    63,     2,    65,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    56,    53,    70,
    58,    71,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    72,     2,    73,    60,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    54,    59,    55,    67,     2,     2,     2,     2,
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
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     1,     3,     4,     7,     9,    12,    15,    18,    21,
    24,    27,    29,    30,    37,    39,    41,    42,    50,    53,
    54,    57,    60,    63,    66,    69,    72,    74,    75,    78,
    81,    82,    86,    88,    91,    95,   101,   103,   105,   107,
   109,   111,   113,   115,   117,   119,   121,   123,   127,   129,
   133,   135,   139,   141,   145,   149,   151,   155,   159,   161,
   165,   169,   173,   176,   179,   182,   184,   186,   188,   192,
   194,   196,   198,   200,   202,   204,   206,   208,   210,   212,
   215,   217,   219,   221,   224,   227,   229,   231,   233,   235,
   237,   239,   241,   243,   245,   247,   249,   251,   253,   255,
   257,   259,   261,   263,   265,   267,   270,   271,   275,   277,
   279,   281,   283,   285,   288,   290,   292,   294,   296,   298,
   300,   302,   305,   307,   309,   311,   314,   317,   321,   323,
   325,   327,   329,   331,   333,   334,   341,   344,   345,   348,
   352,   353,   364,   366,   368,   370,   372,   374,   377,   378,
   381,   385,   388,   389,   392,   396,   399,   402,   403,   410,
   413,   414,   418,   420,   427,   432,   437,   439,   444,   446,
   449,   452,   453,   456,   460,   465,   466,   468,   471,   472,
   476,   477,   484,   485,   493,   494,   496,   498,   500,   504,
   507,   510,   511,   515,   519,   521,   523,   525,   526,   528,
   533,   534,   536,   541,   544,   545,   549,   551,   553,   555,
   557,   559,   566
};

static const short yyrhs[] = {    -1,
    75,     0,     0,    76,    77,     0,    78,     0,    78,    77,
     0,   106,    53,     0,    91,    53,     0,   164,    53,     0,
    81,    53,     0,    79,    53,     0,    28,     0,     0,    22,
    14,    80,    54,    77,    55,     0,    82,     0,    84,     0,
     0,    17,    14,    87,    83,    54,    85,    55,     0,    17,
    14,     0,     0,    86,    85,     0,   106,    53,     0,    91,
    53,     0,   164,    53,     0,   160,    53,     0,   166,    53,
     0,    28,     0,     0,    56,    88,     0,    90,    89,     0,
     0,    57,    90,    89,     0,    14,     0,    31,    14,     0,
    90,    31,    14,     0,     8,    92,    14,    58,    93,     0,
   118,     0,   127,     0,   128,     0,   129,     0,   117,     0,
   154,     0,   155,     0,   183,     0,    90,     0,    94,     0,
    95,     0,    94,    59,    95,     0,    96,     0,    95,    60,
    96,     0,    97,     0,    96,    61,    97,     0,    98,     0,
    97,    52,    98,     0,    97,    51,    98,     0,    99,     0,
    98,    62,    99,     0,    98,    63,    99,     0,   100,     0,
    99,    64,   100,     0,    99,    65,   100,     0,    99,    66,
   100,     0,    63,   101,     0,    62,   101,     0,    67,   101,
     0,   101,     0,    90,     0,   102,     0,    68,    93,    69,
     0,   103,     0,    48,     0,    44,     0,    50,     0,    46,
     0,   104,     0,    47,     0,    37,     0,    18,     0,    93,
     0,    38,   107,     0,   133,     0,   138,     0,   148,     0,
    23,   116,     0,   108,   113,     0,   109,     0,   112,     0,
   110,     0,   111,     0,    90,     0,   117,     0,   118,     0,
   127,     0,   128,     0,   129,     0,   130,     0,   131,     0,
   132,     0,   153,     0,   154,     0,   155,     0,   182,     0,
   133,     0,   138,     0,   148,     0,   115,   114,     0,     0,
    57,   115,   114,     0,   116,     0,   156,     0,    14,     0,
    20,     0,    11,     0,    21,    11,     0,   119,     0,   123,
     0,   120,     0,   121,     0,   122,     0,    33,     0,    21,
     0,    21,    21,     0,   124,     0,   125,     0,   126,     0,
    40,    33,     0,    40,    21,     0,    40,    21,    21,     0,
     7,     0,    42,     0,     5,     0,    25,     0,     3,     0,
    24,     0,     0,    35,    14,   134,    54,   135,    55,     0,
   137,   136,     0,     0,   137,   136,     0,   108,   113,    53,
     0,     0,    39,    14,    36,    68,   140,    69,   139,    54,
   141,    55,     0,   118,     0,   127,     0,   129,     0,   148,
     0,    90,     0,   143,   142,     0,     0,   143,   142,     0,
   144,   147,    53,     0,   146,   145,     0,     0,   146,   145,
     0,     6,    93,    56,     0,    10,    56,     0,   108,   115,
     0,     0,    12,    14,   149,    54,   150,    55,     0,   152,
   151,     0,     0,    57,   152,   151,     0,    14,     0,    32,
    70,   109,    57,   105,    71,     0,    32,    70,   109,    71,
     0,    34,    70,   105,    71,     0,    34,     0,    43,    70,
   105,    71,     0,    43,     0,    14,   157,     0,   159,   158,
     0,     0,   159,   158,     0,    72,   105,    73,     0,   161,
     4,   181,   162,     0,     0,    30,     0,   116,   163,     0,
     0,    57,   116,   163,     0,     0,    13,    14,   165,    54,
   136,    55,     0,     0,   168,   169,    14,   167,   170,   175,
   177,     0,     0,    26,     0,   181,     0,    41,     0,    68,
   171,    69,     0,    68,    69,     0,   173,   172,     0,     0,
    57,   173,   172,     0,   174,   181,   116,     0,    15,     0,
    27,     0,    16,     0,     0,   176,     0,    29,    68,    88,
    69,     0,     0,   178,     0,     9,    68,   179,    69,     0,
    48,   180,     0,     0,    57,    48,   180,     0,   110,     0,
   154,     0,   155,     0,   182,     0,    90,     0,    19,    70,
   105,    57,   103,    71,     0,    19,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   119,   120,   124,   129,   135,   136,   140,   141,   143,   145,
   147,   149,   157,   162,   169,   170,   174,   179,   186,   193,
   194,   198,   199,   201,   203,   205,   207,   215,   220,   228,
   235,   240,   248,   249,   255,   263,   270,   271,   273,   275,
   277,   279,   281,   283,   285,   293,   296,   297,   305,   306,
   314,   315,   323,   324,   330,   338,   339,   345,   353,   354,
   360,   366,   374,   379,   385,   391,   395,   400,   402,   406,
   407,   413,   419,   425,   431,   435,   442,   447,   455,   462,
   463,   465,   467,   469,   477,   484,   485,   489,   490,   492,
   500,   501,   503,   505,   507,   509,   511,   513,   517,   518,
   520,   522,   526,   527,   529,   533,   540,   545,   553,   554,
   558,   565,   570,   576,   584,   585,   589,   590,   592,   596,
   603,   610,   617,   618,   620,   624,   631,   638,   645,   652,
   659,   666,   673,   680,   687,   692,   699,   706,   711,   719,
   727,   732,   739,   740,   742,   744,   746,   754,   761,   766,
   774,   781,   788,   793,   801,   805,   813,   820,   825,   832,
   839,   844,   852,   855,   860,   868,   873,   881,   886,   894,
   901,   908,   913,   921,   928,   935,   940,   948,   955,   960,
   968,   973,   980,   985,   992,   997,  1005,  1006,  1014,  1018,
  1026,  1032,  1037,  1045,  1052,  1057,  1063,  1071,  1076,  1080,
  1087,  1092,  1096,  1103,  1109,  1114,  1122,  1123,  1125,  1127,
  1129,  1137,  1144
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","IDL_ANY",
"ATTRIBUTE","BOOLEAN","CASE","CHAR","CONST","CONTEXT","DEFAULT","DOUBLE","ENUM",
"EXCEPTION","IDENTIFIER","IN","INOUT","INTERFACE","IDL_FALSE","FIXED","FLOAT",
"LONG","MODULE","NATIVE","OBJECT","OCTET","ONEWAY","OUT","PRAGMA","RAISES","READONLY",
"SCOPE_DELIMITER","SEQUENCE","SHORT","STRING","STRUCT","SWITCH","IDL_TRUE","TYPEDEF",
"UNION","UNSIGNED","VOID","WCHAR","WSTRING","CHARACTER_LITERAL","WIDE_CHARACTER_LITERAL",
"FLOATING_PT_LITERAL","INTEGER_LITERAL","STRING_LITERAL","WIDE_STRING_LITERAL",
"FIXED_PT_LITERAL","LEFT_SHIFT","RIGHT_SHIFT","';'","'{'","'}'","':'","','",
"'='","'|'","'^'","'&'","'+'","'-'","'*'","'/'","'%'","'~'","'('","')'","'<'",
"'>'","'['","']'","start","specification","@1","definition_PLUS","definition",
"module","@2","interface","interface_dcl","@3","forward_dcl","export_STAR","export",
"inheritance_spec","scoped_name_CSV_PLUS","scoped_name_CSV","scoped_name","const_dcl",
"const_type","const_expr","or_expr","xor_expr","and_expr","shift_expr","add_expr",
"mult_expr","unary_expr","primary_expr","literal","integer_literal","boolean_literal",
"positive_int_const","type_dcl","type_declarator","type_spec","simple_type_spec",
"base_type_spec","template_type_spec","constr_type_spec","declarator_CSV_PLUS",
"declarator_CSV","declarator","simple_declarator","floating_pt_type","integer_type",
"signed_int","signed_short_int","signed_long_int","signed_longlong_int","unsigned_int",
"unsigned_short_int","unsigned_long_int","unsigned_longlong_int","char_type",
"wide_char_type","boolean_type","octet_type","any_type","object_type","struct_type",
"@4","member_PLUS","member_STAR","member","union_type","@5","switch_type_spec",
"case_PLUS","case_STAR","case","case_label_PLUS","case_label_STAR","case_label",
"element_spec","enum_type","@6","enumerator_CSV_PLUS","enumerator_CSV_STAR",
"enumerator","sequence_type","string_type","wide_string_type","array_declarator",
"fixed_array_size_PLUS","fixed_array_size_STAR","fixed_array_size","attr_dcl",
"readonly_OPT","simple_declarator_CSV_PLUS","simple_declarator_CSV_STAR","except_dcl",
"@7","op_dcl","@8","op_attribute_OPT","op_type_spec","parameter_dcls","param_dcl_CSV_PLUS",
"param_dcl_CSV_STAR","param_dcl","param_attribute","raises_expr_OPT","raises_expr",
"context_expr_OPT","context_expr","string_literal_CSV_PLUS","string_literal_CSV_STAR",
"param_type_spec","fixed_pt_type","fixed_pt_const_type", NULL
};
#endif

static const short yyr1[] = {     0,
    74,    74,    76,    75,    77,    77,    78,    78,    78,    78,
    78,    78,    80,    79,    81,    81,    83,    82,    84,    85,
    85,    86,    86,    86,    86,    86,    86,    87,    87,    88,
    89,    89,    90,    90,    90,    91,    92,    92,    92,    92,
    92,    92,    92,    92,    92,    93,    94,    94,    95,    95,
    96,    96,    97,    97,    97,    98,    98,    98,    99,    99,
    99,    99,   100,   100,   100,   100,   101,   101,   101,   102,
   102,   102,   102,   102,   102,   103,   104,   104,   105,   106,
   106,   106,   106,   106,   107,   108,   108,   109,   109,   109,
   110,   110,   110,   110,   110,   110,   110,   110,   111,   111,
   111,   111,   112,   112,   112,   113,   114,   114,   115,   115,
   116,   117,   117,   117,   118,   118,   119,   119,   119,   120,
   121,   122,   123,   123,   123,   124,   125,   126,   127,   128,
   129,   130,   131,   132,   134,   133,   135,   136,   136,   137,
   139,   138,   140,   140,   140,   140,   140,   141,   142,   142,
   143,   144,   145,   145,   146,   146,   147,   149,   148,   150,
   151,   151,   152,   153,   153,   154,   154,   155,   155,   156,
   157,   158,   158,   159,   160,   161,   161,   162,   163,   163,
   165,   164,   167,   166,   168,   168,   169,   169,   170,   170,
   171,   172,   172,   173,   174,   174,   174,   175,   175,   176,
   177,   177,   178,   179,   180,   180,   181,   181,   181,   181,
   181,   182,   183
};

static const short yyr2[] = {     0,
     0,     1,     0,     2,     1,     2,     2,     2,     2,     2,
     2,     1,     0,     6,     1,     1,     0,     7,     2,     0,
     2,     2,     2,     2,     2,     2,     1,     0,     2,     2,
     0,     3,     1,     2,     3,     5,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     3,     1,     3,
     1,     3,     1,     3,     3,     1,     3,     3,     1,     3,
     3,     3,     2,     2,     2,     1,     1,     1,     3,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
     1,     1,     1,     2,     2,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     2,     0,     3,     1,     1,
     1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
     1,     2,     1,     1,     1,     2,     2,     3,     1,     1,
     1,     1,     1,     1,     0,     6,     2,     0,     2,     3,
     0,    10,     1,     1,     1,     1,     1,     2,     0,     2,
     3,     2,     0,     2,     3,     2,     2,     0,     6,     2,
     0,     3,     1,     6,     4,     4,     1,     4,     1,     2,
     2,     0,     2,     3,     4,     0,     1,     2,     0,     3,
     0,     6,     0,     7,     0,     1,     1,     1,     3,     2,
     2,     0,     3,     3,     1,     1,     1,     0,     1,     4,
     0,     1,     4,     2,     0,     3,     1,     1,     1,     1,
     1,     6,     1
};

static const short yydefact[] = {     3,
     2,     0,     0,     0,     0,     0,     0,     0,    12,     0,
     0,     0,     4,     5,     0,     0,    15,    16,     0,     0,
    81,    82,    83,     0,   131,   129,   113,    33,   213,   112,
   121,     0,   120,   167,     0,   130,   169,    45,     0,    41,
    37,   115,   117,   118,   119,   116,   123,   124,   125,    38,
    39,    40,    42,    43,    44,   158,   181,    19,    13,   111,
    84,   135,   133,     0,   134,   132,     0,    90,    80,     0,
    86,    88,    89,    87,    91,    92,    93,    94,    95,    96,
    97,    98,   103,   104,   105,    99,   100,   101,   102,     0,
     6,    11,    10,     8,     7,     9,   114,   122,    34,     0,
   127,   126,     0,     0,     0,     0,     0,     0,    17,     0,
     0,     0,     0,   111,    85,   107,   109,   110,     0,    78,
    77,    72,    74,    76,    71,    73,     0,     0,     0,     0,
    67,    79,    46,    47,    49,    51,    53,    56,    59,    66,
    68,    70,    75,     0,   128,     0,    35,     0,     0,   138,
    29,    31,     0,     0,     0,     0,     0,     0,   170,   172,
     0,   106,     0,    64,    63,    65,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   166,   168,    36,
   163,     0,   161,     0,     0,   138,     0,    30,   185,     0,
     0,   138,     0,     0,   165,     0,   171,   172,   107,   121,
   147,   143,   144,   145,     0,   146,    69,    48,    50,    52,
    55,    54,    57,    58,    60,    61,    62,   159,     0,   160,
     0,   182,   139,    31,   186,    27,   177,     0,   185,     0,
     0,     0,     0,     0,     0,     0,    14,   136,   137,     0,
     0,   174,   173,   108,   141,   161,   140,    32,    18,    21,
    23,    22,    25,     0,    24,    26,   188,   211,   207,   208,
   209,     0,   187,   210,   212,   164,     0,   162,     0,   183,
     0,   179,   175,     0,     0,     0,     0,   149,     0,   153,
     0,   178,     0,   198,     0,   156,   142,   148,   149,     0,
     0,   152,   153,   179,   195,   197,   196,   190,     0,   192,
     0,     0,   201,   199,   155,   150,   157,   151,   154,   180,
   189,     0,   191,     0,     0,     0,   184,   202,   192,   194,
     0,     0,   193,   200,   205,     0,     0,   204,   203,   205,
   206,     0,     0,     0
};

static const short yydefgoto[] = {   332,
     1,     2,    13,    14,    15,   110,    16,    17,   153,    18,
   228,   229,   109,   151,   188,   131,    19,    39,   132,   133,
   134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
   144,    20,    69,   184,    71,    72,    73,    74,   115,   162,
   116,   117,    75,    76,    42,    43,    44,    45,    46,    47,
    48,    49,    77,    78,    79,    80,    81,    82,    83,   111,
   191,   185,   186,    84,   267,   205,   277,   288,   289,   279,
   292,   280,   291,    85,   106,   182,   220,   183,    86,    87,
    88,   118,   159,   197,   198,   232,   233,   273,   282,    24,
   107,   235,   274,   236,   262,   284,   299,   313,   300,   301,
   303,   304,   317,   318,   326,   328,   263,    89,    55
};

static const short yypact[] = {    39,
-32768,   375,   238,    28,    33,    52,    59,    92,-32768,   100,
   285,   104,-32768,   375,    68,    70,-32768,-32768,    74,    77,
-32768,-32768,-32768,    79,-32768,-32768,-32768,-32768,-32768,-32768,
    29,   119,-32768,    64,    16,-32768,    65,   106,   124,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,    47,-32768,-32768,
-32768,-32768,-32768,    69,-32768,-32768,    72,   106,-32768,   130,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   109,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,     7,
   125,-32768,     7,   134,    91,    97,    99,    15,-32768,   103,
   107,     7,   185,    82,-32768,   111,-32768,-32768,    95,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,    34,    34,    34,     7,
   106,-32768,   105,   113,   114,    40,    50,    31,-32768,-32768,
-32768,-32768,-32768,    96,-32768,   108,-32768,     7,   156,   285,
-32768,     4,   117,   375,   285,   120,   -30,     7,-32768,    82,
   130,-32768,   110,-32768,-32768,-32768,   112,     7,     7,     7,
     7,     7,     7,     7,     7,     7,     7,-32768,-32768,-32768,
-32768,   121,   123,   130,   127,   285,    15,-32768,    81,   131,
   132,   285,   138,     7,-32768,   101,-32768,    82,   111,   157,
   106,-32768,-32768,-32768,   126,-32768,-32768,   113,   114,    40,
    50,    50,    31,    31,-32768,-32768,-32768,-32768,   156,-32768,
   140,-32768,-32768,     4,-32768,-32768,-32768,   143,    81,   147,
   148,   149,   199,   154,   155,   326,-32768,-32768,-32768,   141,
   142,-32768,-32768,-32768,-32768,   123,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,   351,-32768,-32768,-32768,   106,-32768,-32768,
-32768,   197,-32768,-32768,-32768,-32768,   160,-32768,    92,-32768,
    80,   158,-32768,   152,     7,   165,   167,    80,   285,    80,
    92,-32768,    18,   194,   168,-32768,-32768,-32768,    80,   130,
   173,-32768,    80,   158,-32768,-32768,-32768,-32768,   161,   172,
   351,   164,   229,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,    61,-32768,    92,    15,   171,-32768,-32768,   172,-32768,
   175,   192,-32768,-32768,   184,   177,   200,-32768,-32768,   184,
-32768,   242,   247,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,     1,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
    21,-32768,-32768,   -60,    32,    -3,  -166,-32768,  -117,-32768,
    93,    94,    90,   -46,   -45,   -77,   -69,-32768,    71,-32768,
   -86,  -165,-32768,    -6,   153,  -222,-32768,-32768,    83,    66,
  -150,    -7,   265,     3,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,     6,   267,     9,-32768,-32768,-32768,     5,-32768,
-32768,  -130,   122,     8,-32768,-32768,-32768,   -14,    11,-32768,
   -10,  -250,-32768,     2,-32768,-32768,    38,    60,-32768,    -1,
     0,-32768,-32768,    87,   179,-32768,-32768,-32768,    -8,  -161,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,   -32,   -23,-32768,
-32768,-32768,-32768,-32768,-32768,   -39,  -234,  -218,-32768
};


#define	YYLAST		414


static const short yytable[] = {    38,
    61,    53,    54,    23,    70,    41,    21,    68,    50,    22,
   199,    52,   167,   259,    91,    23,   146,   264,    21,   269,
    28,    22,   230,   231,   120,   156,   194,   234,    28,   293,
   180,   259,   295,   296,   104,   264,   101,    32,    -1,    97,
   195,    56,   293,   121,   297,    32,    57,    28,   102,    98,
   122,   120,   123,   124,   125,   223,   126,   164,   165,   166,
   187,   239,   230,   231,    32,    58,   314,   234,   127,   128,
   121,   196,    59,   129,   130,   295,   296,   122,   259,   123,
   124,   125,   264,   126,  -176,   275,   298,   297,     3,   276,
   171,   172,     4,     5,   175,   176,   177,   215,   216,   217,
   -28,   130,   108,     8,   152,    60,   225,   241,   226,    68,
   227,   173,   174,    62,    25,    10,    26,    90,    11,    12,
    92,     4,    93,    28,   211,   212,    94,   213,   214,    95,
   200,    96,    99,   100,   103,   -20,   104,   105,   112,   307,
    32,   113,    33,   114,   119,   145,    68,   147,   148,    35,
   149,    68,   150,   158,   190,    23,   154,   285,    21,   201,
   155,    22,   163,   168,   206,   202,   178,   161,   203,   181,
   189,   204,   169,   242,   170,   218,   193,    98,   179,   219,
   207,   222,    68,   224,   124,   237,   238,    63,    68,    25,
    23,    26,   247,    21,   245,    27,    22,   249,    28,   251,
   252,   253,   254,    64,    30,    31,   255,   256,    65,    66,
   270,   265,   266,   271,   281,    32,    67,    33,    34,   283,
   286,   287,   302,   305,    35,   308,    36,    37,   312,   311,
    23,   315,   258,    21,   260,   261,    22,   316,   322,   325,
   327,   333,    25,   324,    26,   329,   334,   330,    27,   250,
   258,    28,   260,   261,   321,   248,    29,    30,    31,   210,
   208,   272,   209,   240,   244,   157,   221,    40,    32,    51,
    33,    34,   290,   294,   306,    68,   192,    35,   246,    36,
    37,   278,   309,   268,   243,   310,   323,    63,   319,    25,
   331,    26,   160,     0,     0,    27,     4,   258,    28,   260,
   261,     0,     0,    64,    30,    31,   320,     0,    65,    66,
     0,   152,     0,     0,     0,    32,    67,    33,    34,    10,
     0,     0,     0,    12,    35,     0,    36,    37,    63,     0,
    25,     0,    26,     0,     0,     0,    27,     0,     0,    28,
     0,     0,     0,     0,    64,    30,    31,     0,     0,    65,
    66,     0,     0,    63,     0,    25,    32,    26,    33,    34,
     0,    27,     0,     0,    28,    35,   257,    36,    37,    64,
    30,    31,     0,     0,    65,    66,     0,     0,     0,     0,
     0,    32,     3,    33,    34,     0,     4,     5,     0,     0,
    35,     6,    36,    37,     0,     0,     7,     8,     0,     0,
     0,     0,     9,     0,     0,     0,     0,     0,     0,    10,
     0,     0,    11,    12
};

static const short yycheck[] = {     3,
     8,     3,     3,     2,    11,     3,     2,    11,     3,     2,
   161,     3,   130,   236,    14,    14,   103,   236,    14,   254,
    14,    14,   189,   189,    18,   112,    57,   189,    14,   280,
   148,   254,    15,    16,    31,   254,    21,    31,     0,    11,
    71,    14,   293,    37,    27,    31,    14,    14,    33,    21,
    44,    18,    46,    47,    48,   186,    50,   127,   128,   129,
    57,   192,   229,   229,    31,    14,   301,   229,    62,    63,
    37,   158,    14,    67,    68,    15,    16,    44,   301,    46,
    47,    48,   301,    50,     4,     6,    69,    27,     8,    10,
    51,    52,    12,    13,    64,    65,    66,   175,   176,   177,
    54,    68,    56,    23,   108,    14,    26,   194,    28,   113,
    30,    62,    63,    14,     5,    35,     7,    14,    38,    39,
    53,    12,    53,    14,   171,   172,    53,   173,   174,    53,
    21,    53,    14,    70,    70,    55,    31,    14,    70,   290,
    31,    70,    33,    14,    36,    21,   150,    14,    58,    40,
    54,   155,    54,    72,   154,   154,    54,   275,   154,   163,
    54,   154,    68,    59,   163,   163,    71,    57,   163,    14,
    54,   163,    60,    73,    61,    55,    57,    21,    71,    57,
    69,    55,   186,   187,    47,    55,    55,     3,   192,     5,
   189,     7,    53,   189,    69,    11,   189,    55,    14,    53,
    53,    53,     4,    19,    20,    21,    53,    53,    24,    25,
    14,    71,    71,    54,    57,    31,    32,    33,    34,    68,
    56,    55,    29,    56,    40,    53,    42,    43,    57,    69,
   229,    68,   236,   229,   236,   236,   229,     9,    68,    48,
    57,     0,     5,    69,     7,    69,     0,    48,    11,   229,
   254,    14,   254,   254,   315,   224,    19,    20,    21,   170,
   168,   269,   169,   193,   199,   113,   184,     3,    31,     3,
    33,    34,   279,   281,   289,   279,   155,    40,   219,    42,
    43,   271,   293,   246,   198,   294,   319,     3,   312,     5,
   330,     7,   114,    -1,    -1,    11,    12,   301,    14,   301,
   301,    -1,    -1,    19,    20,    21,   314,    -1,    24,    25,
    -1,   315,    -1,    -1,    -1,    31,    32,    33,    34,    35,
    -1,    -1,    -1,    39,    40,    -1,    42,    43,     3,    -1,
     5,    -1,     7,    -1,    -1,    -1,    11,    -1,    -1,    14,
    -1,    -1,    -1,    -1,    19,    20,    21,    -1,    -1,    24,
    25,    -1,    -1,     3,    -1,     5,    31,     7,    33,    34,
    -1,    11,    -1,    -1,    14,    40,    41,    42,    43,    19,
    20,    21,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,
    -1,    31,     8,    33,    34,    -1,    12,    13,    -1,    -1,
    40,    17,    42,    43,    -1,    -1,    22,    23,    -1,    -1,
    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    35,
    -1,    -1,    38,    39
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/opt/local/share/bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 196 "/opt/local/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 3:
#line 124 "grammar.y"
{
			    CALL_0("specification_start");
			    CHECK_EXCEPTION;
                        ;
    break;}
case 4:
#line 129 "grammar.y"
{
			    CALL_0("specification_end");
			    CHECK_EXCEPTION;
                        ;
    break;}
case 12:
#line 151 "grammar.y"
{
			    CALL_1("pragma", yyvsp[0]);
			    CHECK_EXCEPTION;
                        ;
    break;}
case 13:
#line 158 "grammar.y"
{
			    CALL_1("module_header", yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 14:
#line 163 "grammar.y"
{
			    CALL_0("module_body");
			    CHECK_EXCEPTION;
			;
    break;}
case 17:
#line 175 "grammar.y"
{
			    yyval = CALL_2("interface_dcl_header", yyvsp[-1], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 18:
#line 180 "grammar.y"
{
			    CALL_1("interface_dcl_body", yyvsp[-3]);
			    CHECK_EXCEPTION;
			;
    break;}
case 19:
#line 187 "grammar.y"
{
			    CALL_1("foward_dcl", yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 27:
#line 209 "grammar.y"
{
			    CALL_1("pragma", yyvsp[0]);
			    CHECK_EXCEPTION;
                        ;
    break;}
case 28:
#line 216 "grammar.y"
{
			    yyval = CALL_0("inheritance_spec_empty");
			    CHECK_EXCEPTION;
                        ;
    break;}
case 29:
#line 222 "grammar.y"
{
			    yyval = CALL_1("inheritance_spec_full", yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 30:
#line 229 "grammar.y"
{
			    yyval = CALL_2("list_insert", yyvsp[-1], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 31:
#line 236 "grammar.y"
{
			    yyval = CALL_0("list_empty");
			    CHECK_EXCEPTION;
			;
    break;}
case 32:
#line 242 "grammar.y"
{
			    yyval = CALL_2("list_insert", yyvsp[-1], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 34:
#line 251 "grammar.y"
{
			    yyval = CALL_1("scoped_name_absolute", yyvsp[0]);
			    CHECK_EXCEPTION;
                        ;
    break;}
case 35:
#line 257 "grammar.y"
{
			    yyval = CALL_2("scoped_name_relative", yyvsp[-2], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 36:
#line 264 "grammar.y"
{
			    yyval = CALL_3("const_dcl", yyvsp[-3], yyvsp[-2], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 45:
#line 287 "grammar.y"
{
			    yyval = CALL_1("const_type_scoped_name", yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 48:
#line 299 "grammar.y"
{
			    yyval = CALL_2("or_expr", yyvsp[-2], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 50:
#line 308 "grammar.y"
{
			    yyval = CALL_2("xor_expr", yyvsp[-2], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 52:
#line 317 "grammar.y"
{
			    yyval = CALL_2("and_expr", yyvsp[-2], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 54:
#line 326 "grammar.y"
{
			    yyval = CALL_2("shift_expr_right", yyvsp[-2], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 55:
#line 332 "grammar.y"
{
			    yyval = CALL_2("shift_expr_left", yyvsp[-2], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 57:
#line 341 "grammar.y"
{
			    yyval = CALL_2("add_expr_add", yyvsp[-2], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 58:
#line 347 "grammar.y"
{
			    yyval = CALL_2("add_expr_subtract", yyvsp[-2], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 60:
#line 356 "grammar.y"
{
			    yyval = CALL_2("mult_expr_multiply", yyvsp[-2], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 61:
#line 362 "grammar.y"
{
			    yyval = CALL_2("mult_expr_divide", yyvsp[-2], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 62:
#line 368 "grammar.y"
{
			    yyval = CALL_2("mult_expr_mod", yyvsp[-2], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 63:
#line 375 "grammar.y"
{
			    yyval = CALL_1("unary_expr_neg", yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 64:
#line 381 "grammar.y"
{
			    yyval = CALL_1("unary_expr_pos", yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 65:
#line 387 "grammar.y"
{
			    yyval = CALL_1("unary_expr_invert", yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 67:
#line 396 "grammar.y"
{
			    yyval = CALL_1("primary_expr_scoped_name", yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 71:
#line 409 "grammar.y"
{
			    yyval = CALL_1("literal_string_literal", yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 72:
#line 415 "grammar.y"
{
			    yyval = CALL_1("literal_character_literal", yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 73:
#line 421 "grammar.y"
{
			    yyval = CALL_1("literal_fixed_pt_literal", yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 74:
#line 427 "grammar.y"
{
			    yyval = CALL_1("literal_floating_pt_literal", yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 76:
#line 436 "grammar.y"
{
			    yyval = CALL_1("literal_integer_literal", yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 77:
#line 443 "grammar.y"
{
			    yyval = CALL_0("boolean_literal_true");
			    CHECK_EXCEPTION;
			;
    break;}
case 78:
#line 449 "grammar.y"
{
			    yyval = CALL_0("boolean_literal_false");
			    CHECK_EXCEPTION;
			;
    break;}
case 79:
#line 456 "grammar.y"
{
			    yyval = CALL_1("positive_int_const", yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 84:
#line 471 "grammar.y"
{
			    yyval = CALL_1("native_type_dcl", yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 85:
#line 478 "grammar.y"
{
			    CALL_2("type_declarator", yyvsp[-1], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 90:
#line 494 "grammar.y"
{
			    yyval = CALL_1("idl_type_scoped_name", yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 106:
#line 534 "grammar.y"
{
			    yyval = CALL_2("list_insert", yyvsp[-1], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 107:
#line 541 "grammar.y"
{
			    yyval = CALL_0("list_empty");
			    CHECK_EXCEPTION;
			;
    break;}
case 108:
#line 547 "grammar.y"
{
			    yyval = CALL_2("list_insert", yyvsp[-1], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 111:
#line 559 "grammar.y"
{
			    yyval = CALL_1("simple_declarator", yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 112:
#line 566 "grammar.y"
{
			    yyval = CALL_0("float_type");
			    CHECK_EXCEPTION;
			;
    break;}
case 113:
#line 572 "grammar.y"
{
			    yyval = CALL_0("double_type");
			    CHECK_EXCEPTION;
			;
    break;}
case 114:
#line 578 "grammar.y"
{
			    yyval = CALL_0("longdouble_type");
			    CHECK_EXCEPTION;
			;
    break;}
case 120:
#line 597 "grammar.y"
{
			    yyval = CALL_0("signed_short_int");
			    CHECK_EXCEPTION;
			;
    break;}
case 121:
#line 604 "grammar.y"
{
			    yyval = CALL_0("signed_long_int");
			    CHECK_EXCEPTION;
			;
    break;}
case 122:
#line 611 "grammar.y"
{
			    yyval = CALL_0("signed_longlong_int");
			    CHECK_EXCEPTION;
			;
    break;}
case 126:
#line 625 "grammar.y"
{
			    yyval = CALL_0("unsigned_short_int");
			    CHECK_EXCEPTION;
			;
    break;}
case 127:
#line 632 "grammar.y"
{
			    yyval = CALL_0("unsigned_long_int");
			    CHECK_EXCEPTION;
			;
    break;}
case 128:
#line 639 "grammar.y"
{
			    yyval = CALL_0("unsigned_longlong_int");
			    CHECK_EXCEPTION;
			;
    break;}
case 129:
#line 646 "grammar.y"
{
			    yyval = CALL_0("char_type");
			    CHECK_EXCEPTION;
			;
    break;}
case 130:
#line 653 "grammar.y"
{
			    yyval = CALL_0("wide_char_type");
			    CHECK_EXCEPTION;
			;
    break;}
case 131:
#line 660 "grammar.y"
{
			    yyval = CALL_0("boolean_type");
			    CHECK_EXCEPTION;
			;
    break;}
case 132:
#line 667 "grammar.y"
{
			    yyval = CALL_0("octet_type");
			    CHECK_EXCEPTION;
			;
    break;}
case 133:
#line 674 "grammar.y"
{
			    yyval = CALL_0("any_type");
			    CHECK_EXCEPTION;
			;
    break;}
case 134:
#line 681 "grammar.y"
{
			    yyval = CALL_0("object_type");
			    CHECK_EXCEPTION;
			;
    break;}
case 135:
#line 688 "grammar.y"
{
			    yyval = CALL_1("struct_type_header", yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 136:
#line 693 "grammar.y"
{
			    yyval = CALL_2("struct_type_body", yyvsp[-3], yyvsp[-1]);
			    CHECK_EXCEPTION;
			;
    break;}
case 137:
#line 700 "grammar.y"
{
			    yyval = CALL_2("list_insert", yyvsp[-1], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 138:
#line 707 "grammar.y"
{
			    yyval = CALL_0("list_empty");
			    CHECK_EXCEPTION;
			;
    break;}
case 139:
#line 713 "grammar.y"
{
			    yyval = CALL_2("list_insert", yyvsp[-1], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 140:
#line 720 "grammar.y"
{
			    yyval = CALL_2("member", yyvsp[-2], yyvsp[-1]);
			    CHECK_EXCEPTION;
			;
    break;}
case 141:
#line 728 "grammar.y"
{
			    yyval = CALL_2("union_type_header", yyvsp[-4], yyvsp[-1]);
			    CHECK_EXCEPTION;
			;
    break;}
case 142:
#line 733 "grammar.y"
{
			    yyval = CALL_2("union_type_body", yyvsp[-3], yyvsp[-1]);
			    CHECK_EXCEPTION;
			;
    break;}
case 147:
#line 748 "grammar.y"
{
			    yyval = CALL_1("switch_type_spec_scoped_name", yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 148:
#line 755 "grammar.y"
{
			    yyval = CALL_2("list_insert", yyvsp[-1], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 149:
#line 762 "grammar.y"
{
			    yyval = CALL_0("list_empty");
			    CHECK_EXCEPTION;
			;
    break;}
case 150:
#line 768 "grammar.y"
{
			    yyval = CALL_2("list_insert", yyvsp[-1], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 151:
#line 775 "grammar.y"
{
			    yyval = CALL_2("case", yyvsp[-2], yyvsp[-1]);
			    CHECK_EXCEPTION;
			;
    break;}
case 152:
#line 782 "grammar.y"
{
			    yyval = CALL_2("list_insert", yyvsp[-1], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 153:
#line 789 "grammar.y"
{
			    yyval = CALL_0("list_empty");
			    CHECK_EXCEPTION;
			;
    break;}
case 154:
#line 795 "grammar.y"
{
			    yyval = CALL_2("list_insert", yyvsp[-1], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 155:
#line 802 "grammar.y"
{
			    yyval = yyvsp[-1];
			;
    break;}
case 156:
#line 807 "grammar.y"
{
			    yyval = CALL_0("case_label_default");
			    CHECK_EXCEPTION;
			;
    break;}
case 157:
#line 814 "grammar.y"
{
			    yyval = CALL_2("element_spec", yyvsp[-1], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 158:
#line 821 "grammar.y"
{
			    yyval = CALL_1("enum_type_header", yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 159:
#line 826 "grammar.y"
{
			    yyval = CALL_2("enum_type_body", yyvsp[-3], yyvsp[-1]);
			    CHECK_EXCEPTION;
			;
    break;}
case 160:
#line 833 "grammar.y"
{
			    yyval = CALL_2("list_insert", yyvsp[-1], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 161:
#line 840 "grammar.y"
{
			    yyval = CALL_0("list_empty");
			    CHECK_EXCEPTION;
			;
    break;}
case 162:
#line 846 "grammar.y"
{
			    yyval = CALL_2("list_insert", yyvsp[-1], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 164:
#line 856 "grammar.y"
{
			    yyval = CALL_2("sequence_type", yyvsp[-3], yyvsp[-1]);
			    CHECK_EXCEPTION;
			;
    break;}
case 165:
#line 862 "grammar.y"
{
			    yyval = CALL_1("sequence_type", yyvsp[-1]);
			    CHECK_EXCEPTION;
			;
    break;}
case 166:
#line 869 "grammar.y"
{
			    yyval = CALL_1("string_type", yyvsp[-1]);
			    CHECK_EXCEPTION;
			;
    break;}
case 167:
#line 875 "grammar.y"
{
			    yyval = CALL_0("string_type");
			    CHECK_EXCEPTION;
			;
    break;}
case 168:
#line 882 "grammar.y"
{
			    yyval = CALL_1("wide_string_type", yyvsp[-1]);
			    CHECK_EXCEPTION;
			;
    break;}
case 169:
#line 888 "grammar.y"
{
			    yyval = CALL_0("wide_string_type");
			    CHECK_EXCEPTION;
			;
    break;}
case 170:
#line 895 "grammar.y"
{
			    yyval = CALL_2("array_declarator", yyvsp[-1], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 171:
#line 902 "grammar.y"
{
			    yyval = CALL_2("list_insert", yyvsp[-1], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 172:
#line 909 "grammar.y"
{
			    yyval = CALL_0("list_empty");
			    CHECK_EXCEPTION;
			;
    break;}
case 173:
#line 915 "grammar.y"
{
			    yyval = CALL_2("list_insert", yyvsp[-1], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 174:
#line 922 "grammar.y"
{
			    yyval = CALL_1("fixed_array_size", yyvsp[-1]);
			    CHECK_EXCEPTION;
			;
    break;}
case 175:
#line 930 "grammar.y"
{
			    CALL_3("attr_dcl", yyvsp[-3], yyvsp[-1], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 176:
#line 936 "grammar.y"
{
			    yyval = CALL_0("readonly_OPT_normal");
			    CHECK_EXCEPTION;
			;
    break;}
case 177:
#line 942 "grammar.y"
{
			    yyval = CALL_0("readonly_OPT_readonly");
			    CHECK_EXCEPTION;
			;
    break;}
case 178:
#line 949 "grammar.y"
{
			      yyval = CALL_2("list_insert", yyvsp[-1], yyvsp[0]);
			      CHECK_EXCEPTION;
			  ;
    break;}
case 179:
#line 956 "grammar.y"
{
			      yyval = CALL_0("list_empty");
			      CHECK_EXCEPTION;
			  ;
    break;}
case 180:
#line 962 "grammar.y"
{
			      yyval = CALL_2("list_insert",yyvsp[-2], yyvsp[-1]);
			      CHECK_EXCEPTION;
			  ;
    break;}
case 181:
#line 969 "grammar.y"
{
			    yyval = CALL_1("except_dcl_header", yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 182:
#line 974 "grammar.y"
{
			    CALL_2("except_dcl_body", yyvsp[-3], yyvsp[-1]);
			    CHECK_EXCEPTION;
			;
    break;}
case 183:
#line 981 "grammar.y"
{
			    yyval = CALL_3("op_dcl_header", yyvsp[-2], yyvsp[-1], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 184:
#line 986 "grammar.y"
{
			    CALL_4("op_dcl_body", yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 185:
#line 993 "grammar.y"
{
			    yyval = CALL_0("op_attribute_OPT_empty");
			    CHECK_EXCEPTION;
			;
    break;}
case 186:
#line 999 "grammar.y"
{
			    yyval = CALL_0("op_attribute_OPT_oneway");
			    CHECK_EXCEPTION;
			;
    break;}
case 188:
#line 1008 "grammar.y"
{
			    yyval = CALL_0("op_type_spec_void");
			    CHECK_EXCEPTION;
			;
    break;}
case 189:
#line 1015 "grammar.y"
{
			    yyval = yyvsp[-1];
			;
    break;}
case 190:
#line 1020 "grammar.y"
{
			    yyval = CALL_0("parameter_dcls_empty");
			    CHECK_EXCEPTION;
			;
    break;}
case 191:
#line 1027 "grammar.y"
{
			    yyval = CALL_2("list_insert", yyvsp[-1], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 192:
#line 1033 "grammar.y"
{
			    yyval = CALL_0("list_empty");
			    CHECK_EXCEPTION;
			;
    break;}
case 193:
#line 1039 "grammar.y"
{
			    yyval = CALL_2("list_insert", yyvsp[-1], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 194:
#line 1046 "grammar.y"
{
			    yyval = CALL_3("param_dcl", yyvsp[-2], yyvsp[-1], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 195:
#line 1053 "grammar.y"
{
			    yyval = CALL_0("param_attribute_in");
			    CHECK_EXCEPTION;
			;
    break;}
case 196:
#line 1059 "grammar.y"
{
			    yyval = CALL_0("param_attribute_out");
			    CHECK_EXCEPTION;
			;
    break;}
case 197:
#line 1065 "grammar.y"
{
			    yyval = CALL_0("param_attribute_inout");
			    CHECK_EXCEPTION;
			;
    break;}
case 198:
#line 1072 "grammar.y"
{
			    yyval = CALL_0("raises_expr_OPT_empty");
			    CHECK_EXCEPTION;
			;
    break;}
case 200:
#line 1081 "grammar.y"
{
			    yyval = CALL_1("raises_expr", yyvsp[-1]);
			    CHECK_EXCEPTION;
			;
    break;}
case 201:
#line 1088 "grammar.y"
{
			    yyval = CALL_0("context_expr_OPT_empty");
			    CHECK_EXCEPTION;
			;
    break;}
case 203:
#line 1097 "grammar.y"
{
			    yyval = CALL_1("context_expr", yyvsp[-1]);
			    CHECK_EXCEPTION;
                        ;
    break;}
case 204:
#line 1104 "grammar.y"
{
			    yyval = CALL_2("list_insert", yyvsp[-1], yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 205:
#line 1110 "grammar.y"
{
			    yyval = CALL_0("list_empty");
			    CHECK_EXCEPTION;
			;
    break;}
case 206:
#line 1116 "grammar.y"
{
			    yyval = CALL_2("list_insert", yyvsp[-1], yyvsp[0]);
			    CHECK_EXCEPTION;
		        ;
    break;}
case 211:
#line 1131 "grammar.y"
{
			    yyval = CALL_1("idl_type_scoped_name", yyvsp[0]);
			    CHECK_EXCEPTION;
			;
    break;}
case 212:
#line 1138 "grammar.y"
{
			    yyval = CALL_2("fixed_pt_type", yyvsp[-3], yyvsp[-1]);
			    CHECK_EXCEPTION;
			;
    break;}
case 213:
#line 1145 "grammar.y"
{
			    yyval = CALL_0("fixed_pt_const_type");
			    CHECK_EXCEPTION;
			;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 498 "/opt/local/share/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 1151 "grammar.y"


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
