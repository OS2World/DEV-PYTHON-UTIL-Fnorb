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
  File:         $Source: /units/arch/src/Fnorb/src/RCS/longlong.c,v $
  Version:      @(#)$RCSfile: longlong.c,v $ $Revision: 1.1 $


  Description:	Implementation of CORBA 'long long's.

****************************************************************/

#if !defined(lint)
static const char rcsid[] = "@(#)$RCSfile: longlong.c,v $ $Revision: 1.1 $";
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
#include "longlong.h"

/*
 * Local file includes
 */

/*
 * 'Methods' for CORBA 'unsigned long long's.
 */
void
ulonglong_from_py_long(CORBA_unsigned_longlong* ulonglong, PyObject* py_long)
{
  PyObject* x;
  PyObject* y;
  PyObject* z;

  int i;

  /* 'Constants' ;^) */
  PyObject* eight = PyLong_FromLong(8);
  PyObject* mask  = PyLong_FromUnsignedLong(0xff);

  /* Starting with the Python long value. */
  x = py_long;
  Py_INCREF(x);

#ifdef __FNORB_BIG_ENDIAN
  for (i = 7; i >= 0; i--) {
#else
  for (i = 0; i <= 7; i++) {
#endif
    /* Get the LSB. */
    y = PyNumber_And(x, mask);
    
    /* Extract the LSB as an octet and add it to the result. */
    ulonglong->octets[i] = (CORBA_octet) PyLong_AsLong(y);

    /* Shift right to get the next octet. */
    z = PyNumber_Rshift(x, eight);

    /* Clean up. */
    Py_DECREF(x);
    Py_DECREF(y);

    x = z;
  }

  /* Clean up the unused final shifted value. */
  Py_DECREF(x);

  /* Clean up the constants. */
  Py_DECREF(eight);
  Py_DECREF(mask);
}

PyObject*
ulonglong_to_py_long(CORBA_unsigned_longlong* ulonglong)
{
  PyObject* x;
  PyObject* y;
  PyObject* z;

  int i;

  PyObject* result = PyLong_FromLong(0);

  /* 'Constants' ;^) */
  PyObject* eight  = PyInt_FromLong(8);
  PyObject* mask   = PyInt_FromLong(0xff);

#ifdef __FNORB_BIG_ENDIAN
  for (i = 0; i <= 6; i++) {
#else
  for (i = 7; i >= 1; i--) {
#endif
    /* Get the MSB as a Python long. */
    x = PyLong_FromLong((long) ulonglong->octets[i]);

    /* Add it to the result. */
    y = PyNumber_Or(result, x);

    /* Shift right to 'make room' for the next octet! */
    z = PyNumber_Lshift(y, eight);

    /* Clean up. */
    Py_DECREF(result);
    Py_DECREF(x);
    Py_DECREF(y);

    result = z;
  }

  /* Finishing up with the LSB. */
#ifdef __FNORB_BIG_ENDIAN
  x = PyLong_FromLong((long) ulonglong->octets[7]);
#else
  x = PyLong_FromLong((long) ulonglong->octets[0]);
#endif

  /* Add it to the result. */
  y = PyNumber_Or(result, x);
  
  /* Clean up. */
  Py_DECREF(result);
  Py_DECREF(x);

  result = y;

  /* Clean up */
  Py_DECREF(eight);
  Py_DECREF(mask);

  return result;
}

/*
 * 'Methods' for CORBA 'long long's.
 */
void
longlong_from_py_long(CORBA_longlong* longlong, PyObject* py_long)
{
    ulonglong_from_py_long((CORBA_unsigned_longlong*) longlong, py_long);
}

PyObject*
longlong_to_py_long(CORBA_longlong* longlong)
{
  PyObject* result;
  PyObject* x;
  PyObject* y;

  /* 'Constants' ;^) */
  PyObject* two         = PyLong_FromLong(2);
  PyObject* sixty_three = PyLong_FromLong(63);
  PyObject* big         = PyNumber_Power(two, sixty_three, Py_None);
  PyObject* not_big     = PyNumber_Invert(big);

  /* Get the result as for an 'unsigned long long'. */
  result = ulonglong_to_py_long((CORBA_unsigned_longlong*) longlong);

  /* Now check the sign bit! */
#ifdef __FNORB_BIG_ENDIAN
  if (longlong->octets[0] & 0x80) {
#else
  if (longlong->octets[7] & 0x80) {
#endif
    x = PyNumber_And(result, not_big);
    y = PyNumber_Subtract(x, big);

    /* Clean up. */
    Py_DECREF(x);
    Py_DECREF(result);

    result = y;
  }

  /* Clean up */
  Py_DECREF(two);
  Py_DECREF(sixty_three);
  Py_DECREF(big);
  Py_DECREF(not_big);

  return result;
}

/***************************************************************/
/* end of longlong.c */
