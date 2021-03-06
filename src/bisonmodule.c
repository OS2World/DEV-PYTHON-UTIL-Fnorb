/***************************************************************

  Copyright (C) DSTC Pty Ltd (ACN 052 372 577) 1997, 1998. 1999
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
  File:         $Source: /units/arch/src/Fnorb/src/RCS/bisonmodule.c,v $
  Version:      @(#)$RCSfile: bisonmodule.c,v $ $Revision: 1.5 $


  Description:	Python interface to bison/flex parsing.

****************************************************************/

#if !defined(lint)
static const char rcsid[] = "@(#)$RCSfile: bisonmodule.c,v $ $Revision: 1.5 $";
#endif

/*
 * Standard library includes (e.g., stdio)
 */

/*
 * Application library includes (e.g., X, DCE)
 */
#include "Python.h"				/* Python API		*/

/*
 * DSTC library includes (e.g., dstc_stdlib.h)
 */

/*
 * Project library includes              
 */

/*
 * Local file includes
 */

/*
 * The lexer's input stream, and the current line number.
 */
extern FILE* yyin;
extern int yylineno;

/*
 * The Python instance that implements the parser's semantic actions.
 */
extern PyObject* py_parser;

/*
 * The parsing function generated by 'bison'.
 */
int yyparse(void);

/*
 * Exception types.
 */
PyObject* Py_YYERROR;
PyObject* Py_YYABORT;


static PyObject*
bison_yyparse(PyObject* self, PyObject* args)
{
    PyObject* py_yyin;			/* IDL input stream.		*/

    /* Make sure we that have the correct number and type of arguments (in this
     * case two Python objects ;^).
     *
     * The first argument is the Python instance that implements the parser's
     * semantic actions.
     *
     * The second argument is an open file object that is used as the lexer's
     * input stream.
     */
    if (!PyArg_ParseTuple(args, "OO!", &py_parser, &PyFile_Type, &py_yyin))
    {
	return NULL;
    }

    /* Set the input stream used by the lexer. */
    yyin = PyFile_AsFile(py_yyin);

    /* Parse it!
     *
     * 'yyparse' returns 0 if the parse was successful, 1 otherwise.
     */
    return PyInt_FromLong((long) yyparse());
}

static PyObject*
bison_yyin(PyObject* self, PyObject* args)
{
    PyObject* py_yyin;			/* Python value for 'yyin'.	*/
    PyObject* result;			/* Return value.		*/

    /* Make sure we that have the correct number and type of arguments (in this
     * case either none or one!).
     */
    if (PyTuple_Size(args) == 0)
    {
	/* Accessor.
	 *
	 * Create a Python file object from 'yyin'.
	 */
	result = PyFile_FromFile(yyin, "yyin", "rw", NULL);
    }
    else if (PyArg_ParseTuple(args, "O!", &PyFile_Type, &py_yyin))
    {
	/* Modifier.
	 *
	 * Set 'yyin'.
	 */
	yyin = PyFile_AsFile(py_yyin);
	
	Py_INCREF(Py_None);
	result = Py_None;
    }
    else
    {
	/* Invalid arguments. */
	result = NULL;
    }

    return result;
}

static PyObject*
bison_yylineno(PyObject* self, PyObject* args)
{
    PyObject* py_yylineno;		/* Python value for 'yylineno'.	*/
    PyObject* result;			/* Return value.		*/

    /* Make sure we that have the correct number and type of arguments (in this
     * case either none or one!).
     */
    if (PyTuple_Size(args) == 0)
    {
	/* Accessor.
	 *
	 * Create a Python integer object from 'yylineno'.
	 */
	result = PyInt_FromLong((long) yylineno);
    }
    else if (PyArg_ParseTuple(args, "O!", &PyInt_Type, &py_yylineno))
    {
	/* Modifier.
	 *
	 * Set 'yylineno'.
	 */
	yylineno = (int) PyInt_AsLong(py_yylineno);

	Py_INCREF(Py_None);
	result = Py_None;
    }
    else
    {
	/* Invalid arguments. */
	result = NULL;
    }

    return result;
}

static PyMethodDef BisonMethods [] =
{
    {"yyparse",		bison_yyparse,	1},
    {"yyin",		bison_yyin,	1},
    {"yylineno",	bison_yylineno,	1},
    {NULL, NULL, (int) NULL} /* Sentinel. */
};

void
initbison()
{
    PyObject* module;
    PyObject* dictionary;
    
    module = Py_InitModule("bison", BisonMethods);
    dictionary = PyModule_GetDict(module);

    /* Add the 'YYERROR' and 'YYABORT' exception types to the module. */
    Py_YYERROR = PyErr_NewException("bison.YYERROR", NULL, NULL);
    if (PyDict_SetItemString(dictionary, "YYERROR", Py_YYERROR) != 0)
	Py_FatalError ("Unable to add YYERROR to the module dictionary.");

    Py_YYABORT = PyErr_NewException("bison.YYABORT", NULL, NULL);
    if (PyDict_SetItemString(dictionary, "YYABORT", Py_YYABORT) != 0)
	Py_FatalError ("Unable to add YYABORT to the module dictionary.");
}

/***************************************************************/
/* end of bisonmodule.c */
