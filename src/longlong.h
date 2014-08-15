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
  File:         $Source: /units/arch/src/Fnorb/src/RCS/longlong.h,v $
  Version:      @(#)$RCSfile: longlong.h,v $ $Revision: 1.1 $


  Description:	Definitions for the implementation of CORBA 'long long's.

****************************************************************/
#ifndef LONGLONG_H
#define LONGLONG_H

#if defined (__cplusplus)
extern "C" {
#endif

#if !defined(lint)
static const char rcs_LONGLONG_H[] = "@(#)$RCSfile: longlong.h,v $ $Revision: 1.1 $";
#endif

/*
 * Application library includes (e.g., X, DCE)
 */
#include "Python.h"				/* Python API		*/

/*
 * Project library includes              
 */
#include "fnorb.h"

/* To allow for 64-bit integers on 32-bit platforms, we implement them as
 * as raw octets!
 */
typedef struct {
    CORBA_octet octets[8];

} CORBA_longlong, CORBA_unsigned_longlong;

/* 'Methods' on the 'long long' types. */
void
ulonglong_from_py_long(CORBA_unsigned_longlong* ulonglong, PyObject* py_long);

PyObject*
ulonglong_to_py_long(CORBA_unsigned_longlong* ulonglong);

void
longlong_from_py_long(CORBA_longlong* longlong, PyObject* py_long);

PyObject*
longlong_to_py_long(CORBA_longlong* longlong);

#if defined (__cplusplus)
}
#endif

/***************************************************************/
#endif /* LONGLONG_H */
