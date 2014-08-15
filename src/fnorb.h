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
  File:         $Source: /units/arch/src/Fnorb/src/RCS/fnorb.h,v $
  Version:      @(#)$RCSfile: fnorb.h,v $ $Revision: 1.12 $


  Description:	ORB Type definitions etc.

****************************************************************/
#ifndef FNORB_H
#define FNORB_H

#if defined (__cplusplus)
extern "C" {
#endif

#if !defined(lint)
static const char rcs_FNORB_H[] = "@(#)$RCSfile: fnorb.h,v $ $Revision: 1.12 $";
#endif

/* The following definitions work on Linux, Digital Unix, Solaris, and
 * Windows 95/NT!!
 *
 * If you want to port this code to other platforms you must choose native
 * datatypes of the appropriate size.
 */
typedef unsigned char	CORBA_boolean;			/* 8 bits	*/
typedef unsigned char	CORBA_char;			/* 8 bits	*/
typedef unsigned char	CORBA_octet;			/* 8 bits	*/
typedef unsigned short	CORBA_unsigned_short;		/* 16 bits	*/
typedef short           CORBA_short;			/* 16 bits	*/
typedef unsigned int    CORBA_unsigned_long;		/* 32 bits	*/
typedef int		CORBA_long;			/* 32 bits	*/
typedef float		CORBA_float;			/* 32 bits	*/
typedef double		CORBA_double;			/* 64 bits	*/

/* The implementation of CORBA 'long long' and 'unsigned long long' - 64 bit
 * integers.
 */
#include "longlong.h"

/* The script 'fnendian' is used by the Makefile to determine the byte order of
 * the target architecture.  Here we translate the pre-processor symbols into
 * the values required by GIOP (Big Endian = 0, Little Endian = 1).
 *
 * e.g.	Linux        on Intel     is Little
 *	Digital Unix on Dec/Alpha is Little
 * 	Solaris      on Sparc     is Big
 *	Windows95/NT on Dec/Alpha is Little
 *	Windows95/NT on Intel	  is Little
 */
#ifdef __FNORB_BIG_ENDIAN
#define HOST_BYTE_ORDER 0
#endif

#ifdef __FNORB_LITTLE_ENDIAN
#define HOST_BYTE_ORDER 1
#endif

#if defined (__cplusplus)
}
#endif

/***************************************************************/
#endif /* FNORB_H */
