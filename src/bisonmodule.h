#ifndef __BISON_MODULE_H
#define __BISON_MODULE_H

#include "Python.h"

/* Exceptions defined in 'bisonmodule.c'. */
extern PyObject* Py_YYERROR;
extern PyObject* Py_YYABORT;

/* The Python instance that implements the semantic actions. */
PyObject* py_parser;

/* Shorthand. */
#define CALL_METHOD PyObject_CallMethod

#define CALL_0(m)	      CALL_METHOD(py_parser, (m), NULL)
#define CALL_1(m, a) 	      CALL_METHOD(py_parser, (m), "O", (a))
#define CALL_2(m, a, b)	      CALL_METHOD(py_parser, (m), "OO", (a), (b))
#define CALL_3(m, a, b, c)    CALL_METHOD(py_parser, (m), "OOO", (a), (b), (c))
#define CALL_4(m, a, b, c, d) CALL_METHOD(py_parser, (m), "OOOO", \
					  (a), (b), (c), (d))
#define CHECK_EXCEPTION \
if (PyErr_Occurred() != NULL) \
{ \
    if (PyErr_ExceptionMatches(Py_YYERROR)) \
    { \
        PyErr_Clear(); \
        yynerrs++; \
        YYERROR; \
    } \
    else if (PyErr_ExceptionMatches(Py_YYABORT)) \
    { \
        PyErr_Clear(); \
        YYABORT; \
    } \
    else \
    { \
        PyErr_Print(); \
        YYABORT; \
    } \
}

#endif /* # ifndef __BISON_MODULE_H */
