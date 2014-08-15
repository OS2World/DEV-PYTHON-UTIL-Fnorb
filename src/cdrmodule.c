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
     Level 7, Gehrmann Labs
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
  File:         $Source: /units/arch/src/Fnorb-1.0/src/RCS/cdrmodule.c,v $
  Version:      @(#)$RCSfile: cdrmodule.c,v $ $Revision: 1.12 $


  Description:	Python interface to CORBA CDR marshalling/unmarshalling
                functions.

****************************************************************/

#if !defined(lint)
static const char rcsid[] = "@(#)$RCSfile: cdrmodule.c,v $ $Revision: 1.12 $";
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
#include "fnorb.h"
#include "cdr.h"

/*
 * Local file includes
 */

/*
 * CDR error object.
 */
#define CDR_ERROR		"error"
#define CDR_ERROR_STRING	"cdr.error"

static PyObject* CDRError;

/*
 * Version.
 */
#define CDR_VERSION "1.1"

/*
 * Raise a CDR error (return NULL for convenience).
 */
static PyObject*
cdr_error(char* message, int status)
{
    PyObject* error_value;
    
    /*
     * Initialise the error value.
     */
    error_value = Py_BuildValue("zi", message, (long) status);    
    if (error_value != NULL)
    {
	PyErr_SetObject(CDRError, error_value);
	Py_DECREF(error_value);
    }

    return NULL;
}

static PyObject*
cdr_version(PyObject* self, PyObject* args)
{
    /* Return the version of this module! */
    return PyString_FromString(CDR_VERSION);
}

static PyObject*
cdr_host_byte_order(PyObject* self, PyObject* args)
{
    /* The return value is 0 if the host byte order is BIG endian, 1 if the
     * host byte order is LITTLE endian.
     */
    return PyInt_FromLong((long) HOST_BYTE_ORDER);
}

static PyObject*
cdr_octet_to_ASCII(PyObject* self, PyObject* args)
{
    PyObject* py_octet;
    CORBA_octet* octet;
    CORBA_unsigned_long len_octet;

    PyObject* py_ascii;
    char* ascii;

    CORBA_unsigned_long i;
    char s[3];

    /* Parse the arguments. */
    if (!PyArg_ParseTuple(args, "O!", &PyString_Type, &py_octet)) {
	return NULL;
    }

    /* Get the size of the octet stream. */
    len_octet = PyString_Size(py_octet);

    /* Each octet is represented as two ASCII characters, so (not surprisingly)
     * we create a string that is twice the size of the octet stream.
     */
    py_ascii = PyString_FromStringAndSize((char*) NULL, len_octet * 2);

    /* Get to the 'innards' of the octet and ASCII Python string objects. */
    octet = (CORBA_octet*) PyString_AsString(py_octet);
    ascii = PyString_AsString(py_ascii);

    /* Do the translation! */
    for(i = 0; i < len_octet; i++, octet++)
    {
	sprintf(s, "%02X", *octet);
	strcpy(&ascii[i * 2], s);
    }

    return py_ascii;
}

static PyObject*
cdr_ASCII_to_octet(PyObject* self, PyObject* args)
{
    PyObject* py_ascii;
    char* ascii;
    CORBA_unsigned_long len_ascii;

    PyObject* py_octet;
    CORBA_octet* octet;

    CORBA_unsigned_long i;
    CORBA_long val;
    char hex[3];
    hex[2] = '\0';

    /* Parse the arguments. */
    if (!PyArg_ParseTuple(args, "O!", &PyString_Type, &py_ascii)) {
	return NULL;
    }

    /* Get the size of the ASCII string. */
    len_ascii = PyString_Size(py_ascii);

    /* Make sure that there are an even number of ASCII characters! */
    if (len_ascii % 2 != 0) {
	return cdr_error("Odd length ASCII string", len_ascii);
    }

    /* Every two ASCII characters becomes a single octet, so (again, not
     * surprisingly) we create a string that is half the size of the ASCII
     * string.
     */
    py_octet = PyString_FromStringAndSize((char*) NULL, len_ascii / 2);

    /* Get to the 'innards' of the ASCII and octet Python string objects. */
    ascii = PyString_AsString(py_ascii);
    octet = (CORBA_octet*) PyString_AsString(py_octet);

    for(i = 0; i < len_ascii / 2; i++)
    {
	hex[0] = *ascii++;
	hex[1] = *ascii++;
	sscanf(hex, "%x", &val);
	octet[i] = val;
    }

    return py_octet;
}

static PyObject*
cdr_count(PyObject* self, PyObject* args)
{
    /* Arguments. */
    char format;
    PyObject* octet_string;
    unsigned long offset;
    PyObject* value;
    CORBA_boolean byte_order;

    /* The return value is the new offset after 'marshalling' the data. */
    PyObject* result;

    /* Stuff to get the job done! */
    CORBA_octet* os;
    CORBA_octet* p;

    CORBA_boolean boolean_val;
    CORBA_octet octet_val;
    CORBA_unsigned_short ushort_val;
    CORBA_short short_val;
    CORBA_unsigned_long ulong_val;
    CORBA_long long_val;
    CORBA_unsigned_longlong ulonglong_val;
    CORBA_longlong longlong_val;
    CORBA_float float_val;
    CORBA_double double_val;
    CORBA_char* string_val;
    CORBA_octet* octets_val;
    CORBA_unsigned_long len;
    
    /* Parse the arguments. */
    if (!PyArg_ParseTuple(args, "cO!lbO", &format, &PyString_Type,
			  &octet_string, (long*) &offset, &byte_order, &value))
    {
	return NULL;
    }

    /* Get a pointer to the data of the Python string. */
    os = (CORBA_octet*) PyString_AsString(octet_string);
    p = &os[offset];

    switch(format) {

    case 'b':
	/* boolean */
	boolean_val = (CORBA_boolean) PyInt_AsLong(value);
	(void) cdr_count_boolean(os, &p, byte_order, boolean_val);
	result = Py_BuildValue ("l", p - os);
 	break;

    case 'c':
	/* char */
	string_val = (CORBA_char*) PyString_AsString(value);
	(void) cdr_count_char(os, &p, byte_order, (CORBA_char) string_val[0]);
	result = Py_BuildValue ("l", p - os);
	break;

    case 'o':
	/* octet */
	octet_val = (CORBA_octet) PyInt_AsLong(value);
	(void) cdr_count_octet(os, &p, byte_order, octet_val);
	result = Py_BuildValue ("l", p - os);
	break;

    case 'h':
	/* short */
	short_val = (CORBA_short) PyInt_AsLong(value);
	(void) cdr_count_short(os, &p, byte_order, short_val);
	result = Py_BuildValue ("l", p - os);
	break;

    case 'H':
	/* unsigned short */
	ushort_val = (CORBA_unsigned_short) PyInt_AsLong(value);
	(void) cdr_count_unsigned_short(os,&p, byte_order, ushort_val);
	result = Py_BuildValue ("l", p - os);
	break;

    case 'l':
	/* long */
	long_val = (CORBA_long) PyInt_AsLong(value);
	(void) cdr_count_long(os, &p, byte_order, long_val);
	result = Py_BuildValue ("l", p - os);
	break;

    case 'L':
	/* unsigned long */
	if PyInt_Check(value) {
	  ulong_val = (CORBA_unsigned_long) PyInt_AsLong(value);
	}
	else {
	  ulong_val = (CORBA_unsigned_long) PyLong_AsUnsignedLong(value);
        }
	(void) cdr_count_unsigned_long(os, &p, byte_order, ulong_val);
	result = Py_BuildValue ("l", p - os);
	break;

    case 'n':
	/* long long */
	(void) cdr_count_longlong(os, &p, byte_order, longlong_val);
	result = Py_BuildValue ("l", p - os);
	break;

    case 'N':
	/* unsigned long long */
	(void) cdr_count_unsigned_longlong(os, &p, byte_order, ulonglong_val);
	result = Py_BuildValue ("l", p - os);
	break;

    case 'f':
	/* float */
	float_val = (CORBA_float) PyFloat_AsDouble(value);
	(void) cdr_count_float(os, &p, byte_order, float_val);
	result = Py_BuildValue ("l", p - os);
	break;

    case 'd':
	/* double */
	double_val = (CORBA_double) PyFloat_AsDouble(value);
	(void) cdr_count_double(os, &p, byte_order, double_val);
	result = Py_BuildValue ("l", p - os);
	break;

    case 's':
	/* string */
	string_val = (CORBA_char*) PyString_AsString(value);
	(void) cdr_count_string(os, &p, byte_order, string_val);
	result = Py_BuildValue ("l", p - os);
	break;

    case 'O':
	/* sequence of octets */
	len = PyString_Size(value);
	octets_val = (CORBA_octet*) PyString_AsString(value);
	(void) cdr_count_octets(os, &p, byte_order, octets_val, len);
	result = Py_BuildValue ("l", p - os);
	break;

    default:
	return cdr_error("Invalid format character", 0);
    };

    return result;
}

static PyObject*
cdr_marshal(PyObject* self, PyObject* args)
{
    /* Arguments. */
    char format;
    PyObject* octet_string;
    unsigned long offset;
    PyObject* value;
    CORBA_boolean byte_order;

    /* Return value is the new offset after marshalling the data. */
    PyObject* result;

    /* Stuff to get the job done! */
    CORBA_octet* os;
    CORBA_octet* p;

    CORBA_boolean boolean_val;
    CORBA_octet octet_val;
    CORBA_unsigned_short ushort_val;
    CORBA_short short_val;
    CORBA_unsigned_long ulong_val;
    CORBA_long long_val;
    CORBA_unsigned_longlong ulonglong_val;
    CORBA_longlong longlong_val;
    CORBA_float float_val;
    CORBA_double double_val;
    CORBA_char* string_val;
    CORBA_octet* octets_val;
    CORBA_unsigned_long len;

    /* Parse the arguments. */
    if (!PyArg_ParseTuple(args, "cO!lbO", &format, &PyString_Type,
			  &octet_string, (long*) &offset, &byte_order, &value))
    {
	return NULL;
    }

    /* Get a pointer to the data of the Python string. */
    os = (CORBA_octet*) PyString_AsString(octet_string);
    p = &os[offset];

    switch(format) {

    case 'b':
	/* boolean */
	boolean_val = (CORBA_boolean) PyInt_AsLong(value);
	(void) cdr_put_boolean(os, &p, byte_order, boolean_val);
	result = Py_BuildValue ("l", p - os);
 	break;

    case 'c':
	/* char */
	string_val = (CORBA_char*) PyString_AsString(value);
	(void) cdr_put_char(os, &p, byte_order, (CORBA_char) string_val[0]);
	result = Py_BuildValue ("l", p - os);
	break;

    case 'o':
	/* octet */
	octet_val = (CORBA_octet) PyInt_AsLong(value);
	(void) cdr_put_octet(os, &p, byte_order, octet_val);
	result = Py_BuildValue ("l", p - os);
	break;

    case 'h':
	/* short */
	short_val = (CORBA_short) PyInt_AsLong(value);
	(void) cdr_put_short(os, &p, byte_order, short_val);
	result = Py_BuildValue ("l", p - os);
	break;

    case 'H':
	/* unsigned short */
	ushort_val = (CORBA_unsigned_short) PyInt_AsLong(value);
	(void) cdr_put_unsigned_short(os, &p, byte_order, ushort_val);
	result = Py_BuildValue ("l", p - os);
	break;

    case 'l':
	/* long */
	long_val = (CORBA_long) PyInt_AsLong(value);
	(void) cdr_put_long(os, &p, byte_order, long_val);
	result = Py_BuildValue ("l", p - os);
	break;

    case 'L':
	/* unsigned long */
	if PyInt_Check(value)
	{
	  ulong_val = (CORBA_unsigned_long) PyInt_AsLong(value);
	}
	else
        {
	  ulong_val = (CORBA_unsigned_long) PyLong_AsUnsignedLong(value);
        }
	(void) cdr_put_unsigned_long(os, &p, byte_order, ulong_val);
	result = Py_BuildValue ("l", p - os);
	break;

    case 'n':
	/* long long */
	longlong_from_py_long(&longlong_val, value);
	(void) cdr_put_longlong(os, &p, byte_order, longlong_val);
	result = Py_BuildValue ("l", p - os);
	break;

    case 'N':
	/* unsigned long long */
	ulonglong_from_py_long(&ulonglong_val, value);
	(void) cdr_put_unsigned_longlong(os, &p, byte_order, ulonglong_val);
	result = Py_BuildValue ("l", p - os);
	break;

    case 'f':
	/* float */
	float_val = (CORBA_float) PyFloat_AsDouble(value);
	(void) cdr_put_float(os, &p, byte_order, float_val);
	result = Py_BuildValue ("l", p - os);
	break;

    case 'd':
	/* double */
	double_val = (CORBA_double) PyFloat_AsDouble(value);
	(void) cdr_put_double(os, &p, byte_order, double_val);
	result = Py_BuildValue ("l", p - os);
	break;

    case 's':
	/* string */
	string_val = (CORBA_char*) PyString_AsString(value);
	(void) cdr_put_string(os, &p, byte_order, string_val);
	result = Py_BuildValue ("l", p - os);
	break;

    case 'O':
	/* sequence of octets */
	len = PyString_Size(value);
	octets_val = (CORBA_octet*) PyString_AsString(value);
	(void) cdr_put_octets(os, &p, byte_order, octets_val, len);
	result = Py_BuildValue ("l", p - os);
	break;

    default:
	return cdr_error("Invalid format character", 0);
    };

    return result;
}

static PyObject*
cdr_unmarshal(PyObject* self, PyObject* args)
{
    /* Arguments. */
    char format;
    PyObject* octet_string;
    unsigned long offset;
    CORBA_boolean byte_order;

    /* Return value is a tuple (NewOffset, UnmarshalledValue). */
    PyObject* result;
    PyObject* py_long_val;

    /* Stuff to get the job done! */
    CORBA_octet* os;
    CORBA_octet* p;

    /* fixme: Should probably use a union here! */
    CORBA_boolean boolean_val;
    CORBA_octet octet_val;
    CORBA_unsigned_short ushort_val;
    CORBA_short short_val;
    CORBA_unsigned_long ulong_val;
    CORBA_long long_val;
    CORBA_unsigned_longlong ulonglong_val;
    CORBA_longlong longlong_val;
    CORBA_float float_val;
    CORBA_double double_val;
    CORBA_char* string_val;
    CORBA_octet* octets_val;
    CORBA_unsigned_long len;
    CORBA_char char_val[2] = {'\0', '\0'};

    /* Parse the arguments. */
    if (!PyArg_ParseTuple(args, "cO!lb", &format, &PyString_Type,
			  &octet_string, (long*) &offset, &byte_order)) {
	return NULL;
    }

    /* Get a pointer to the data of the Python string. */
    os = (CORBA_octet*) PyString_AsString(octet_string);
    p = &os[offset];

    switch(format) {

    case 'b':
	/* boolean */
	(void) cdr_get_boolean(os, &p, byte_order, &boolean_val);
	result = Py_BuildValue ("(lb)", p - os,  boolean_val);
 	break;

    case 'c':
	/* char */
	(void) cdr_get_char(os, &p, byte_order, &char_val[0]);
	result = Py_BuildValue ("(ls#)", p - os, char_val, 1);
	break;

    case 'o':
	/* octet */
	(void) cdr_get_octet(os, &p, byte_order, &octet_val);
	result = Py_BuildValue ("(lb)", p - os, octet_val);
	break;

    case 'h':
	/* short */
	(void) cdr_get_short(os, &p, byte_order, &short_val);
	result = Py_BuildValue ("(lh)", p - os, short_val);
	break;

    case 'H':
	/* unsigned short */
	(void) cdr_get_unsigned_short(os, &p, byte_order, &ushort_val);
	result = Py_BuildValue ("(lh)", p - os, ushort_val);
	break;

    case 'l':
	/* long */
	(void) cdr_get_long(os, &p, byte_order, &long_val);
	result = Py_BuildValue ("(ll)", p - os, long_val);
	break;

    case 'L':
	/* unsigned long */
	(void) cdr_get_unsigned_long(os, &p, byte_order, &ulong_val);
	py_long_val = PyLong_FromUnsignedLong(ulong_val);
	result = Py_BuildValue ("(lO)", p - os, py_long_val);

	/* 'Py_BuildValue' increments the reference count. */
	Py_DECREF(py_long_val);
	break;

    case 'n':
	/* long long */
	(void) cdr_get_longlong(os, &p, byte_order, &longlong_val);
	py_long_val = longlong_to_py_long(&longlong_val);
	result = Py_BuildValue ("(lO)", p - os, py_long_val);

	/* 'Py_BuildValue' increments the reference count. */
	Py_DECREF(py_long_val);
	break;

    case 'N':
	/* unsigned long long */
	(void) cdr_get_unsigned_longlong(os, &p, byte_order, &ulonglong_val);
	py_long_val = ulonglong_to_py_long(&ulonglong_val);
	result = Py_BuildValue ("(lO)", p - os, py_long_val);

	/* 'Py_BuildValue' increments the reference count. */
	Py_DECREF(py_long_val);
	break;

    case 'f':
	/* float */
	(void) cdr_get_float(os, &p, byte_order, &float_val);
	result = Py_BuildValue ("(lf)", p - os, float_val);
	break;

    case 'd':
	/* double */
	(void) cdr_get_double(os, &p, byte_order, &double_val);
	result = Py_BuildValue ("(ld)", p - os, double_val);
	break;

    case 's':
	/* string */

	/* Strings CANNOT be zero length because the length always 	*/
	/* includes the NULL terminator.  Therefore, even an 'empty' 	*/
	/* string is of	length 1. 					*/
	len = cdr_get_string(os, &p, byte_order, &string_val);
	if (len > 0) {
	    /* If we didn't get a buffer then one could not be allocated */
	    /* to match the size of the string.                          */
	    /* This can be caused by a bad string length value.          */
	    if (string_val == 0)
		return cdr_error("Invalid string sequence", 0);
	    
	    result = Py_BuildValue ("(ls)", p - os, string_val);
	    free(string_val);
	}
	/* If we *do* get a zero length string, then the message must	*/
	/* have come from some other (buggy!) ORB. In a remarkable 	*/
	/* display of tolerance, we don't raise an exception, but 	*/
	/* instead, just create an "empty" string!			*/
	else {
	    /* This is what we *should* do!				*/
	    /* return cdr_error("Zero length string", 0);		*/

	    /* But this is what we actually do!				*/
	    result = Py_BuildValue ("(ls)", p - os, "");
	}
	break;

    case 'O':
	/* sequence of octets */		
	len = cdr_get_octets(os, &p, byte_order, &octets_val);
	if (len > 0) {
	    /* If we didn't get a buffer then one could not be allocated */
	    /* to match the size of the sequence.                        */
	    /* This can be caused by a bad sequence length value.        */
	    if (octets_val == 0)
		return cdr_error("Invalid octet sequence", 0);
	    result = Py_BuildValue ("(ls#)", p - os, octets_val, len);
	    free(octets_val);
	}
	else {
	    result = Py_BuildValue ("(ls#)", p - os, octets_val, len);
	}
	break;

    default:
	return cdr_error("Invalid format character", 0);
    };

    return result;
}

static PyMethodDef CDRMethods [] =
{
    {"version",         cdr_version,		1},
    {"host_byte_order", cdr_host_byte_order,	1},
    {"octet_to_ASCII",  cdr_octet_to_ASCII,	1},
    {"ASCII_to_octet",  cdr_ASCII_to_octet,	1},
    {"count",           cdr_count,		1},
    {"marshal",		cdr_marshal,		1},
    {"unmarshal",	cdr_unmarshal,		1},
    {NULL, NULL, (int) NULL} /* Sentinel. */
};

void
initcdr()
{
    PyObject* module;
    PyObject* dict;
    
    module = Py_InitModule("cdr", CDRMethods);
    dict = PyModule_GetDict(module);

    CDRError = PyString_FromString(CDR_ERROR_STRING);
    if (CDRError == NULL)
    {
	Py_FatalError ("Unable to create CDR error object.");
    }

    if (PyDict_SetItemString(dict, CDR_ERROR, CDRError) != 0)
    {
	Py_FatalError ("Unable to add CDR error name to dictionary.");
    }	
}

/***************************************************************/
/* end of cdrmodule.c */
