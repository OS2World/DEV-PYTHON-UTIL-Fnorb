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
  File:         $Source: /units/arch/src/Fnorb/src/RCS/cdr.h,v $
  Version:      @(#)$RCSfile: cdr.h,v $ $Revision: 1.5 $


  Description:	Marshalling/unmarshalling functions for the CORBA Common Data
                Representation (CDR).

****************************************************************/
#ifndef CDR_H
#define CDR_H

#if defined (__cplusplus)
extern "C" {
#endif

#include "fnorb.h"				/* ORB types etc...	*/

#if !defined(lint)
static const char rcs_CDR_H[] = "@(#)$RCSfile: cdr.h,v $ $Revision: 1.5 $";
#endif

/*
 * The 'cdr_count_' functions calculate the space required to marshal data
 * onto an octet stream (including padding).
 */
unsigned long
cdr_count_boolean(CORBA_octet* os,    		/* Octet stream base.	*/
		  CORBA_octet** p,		/* Current position.	*/
		  CORBA_boolean byte_order,	/* Byte-order.		*/
		  CORBA_boolean val);		/* Value to count.	*/
unsigned long
cdr_count_char(CORBA_octet* os,    		/* Octet stream base.	*/
	       CORBA_octet** p,			/* Current position.	*/
	       CORBA_boolean byte_order,	/* Byte-order.		*/
	       CORBA_octet val);		/* Value to count.	*/
unsigned long
cdr_count_octet(CORBA_octet* os,    		/* Octet stream base.	*/
		CORBA_octet** p,		/* Current position.	*/
		CORBA_boolean byte_order,	/* Byte-order.		*/
		CORBA_octet val);		/* Value to count.	*/
unsigned long
cdr_count_unsigned_short(CORBA_octet* os,	   /* Octet stream base.*/
			 CORBA_octet** p,	   /* Current position.	*/
			 CORBA_boolean byte_order, /* Byte-order.	*/
			 CORBA_unsigned_short val);/* Value to count.	*/
unsigned long
cdr_count_short(CORBA_octet* os,		/* Octet stream base.	*/
		CORBA_octet** p,		/* Current position.	*/
		CORBA_boolean byte_order,	/* Byte-order.		*/
		CORBA_short val);		/* Value to count.	*/
unsigned long
cdr_count_unsigned_long(CORBA_octet* os,	 /* Octet stream base.	*/
			CORBA_octet** p, 	 /* Current position.	*/
			CORBA_boolean byte_order,/* Byte-order.		*/
			CORBA_unsigned_long val);/* Value to count.	*/
unsigned long
cdr_count_long(CORBA_octet* os,			/* Octet stream base.	*/
	       CORBA_octet** p,			/* Current position.	*/
	       CORBA_boolean byte_order,	/* Byte-order.		*/
	       CORBA_long val);			/* Value to count.	*/

unsigned long
cdr_count_unsigned_longlong(CORBA_octet* os,	 /* Octet stream base.	*/
			    CORBA_octet** p, 	 /* Current position.	*/
			    CORBA_boolean byte_order,/* Byte-order.	*/
			    CORBA_unsigned_longlong val);/* Value to count.*/
unsigned long
cdr_count_longlong(CORBA_octet* os,		/* Octet stream base.	*/
		   CORBA_octet** p,		/* Current position.	*/
		   CORBA_boolean byte_order,	/* Byte-order.		*/
		   CORBA_longlong val);		/* Value to count.	*/
unsigned long
cdr_count_float(CORBA_octet* os,		/* Octet stream base.	*/
		CORBA_octet** p,		/* Current position.	*/
		CORBA_boolean byte_order,	/* Byte-order.		*/
		CORBA_float val);		/* Value to count.	*/
unsigned long
cdr_count_double(CORBA_octet* os,		/* Octet stream base.	*/
		 CORBA_octet** p,		/* Current position.	*/
		 CORBA_boolean byte_order,	/* Byte-order.		*/
		 CORBA_double val);		/* Value to count.	*/
unsigned long
cdr_count_string(CORBA_octet* os,		/* Octet stream base.	*/
		 CORBA_octet** p,		/* Current position.	*/
		 CORBA_boolean byte_order,	/* Byte-order.		*/
		 CORBA_char* val);		/* Value to count.	*/
unsigned long
cdr_count_octets(CORBA_octet* os,		/* Octet stream base.	*/
		 CORBA_octet** p,		/* Current position.	*/
		 CORBA_boolean byte_order,	/* Byte-order.		*/
		 CORBA_octet* val,		/* Value to count.	*/
		 CORBA_unsigned_long len);	/* Number of octets.	*/
/*
 * MARSHALLING functions.
 *
 * All of the functions defined in this section are 'assert friendly' i.e. they
 * return NON-zero for success and zero for failure.  The return value is
 * actually the number of octets that were required to marshal the data
 * (including any padding).  This may or may not be useful ;^)
 */
unsigned long
cdr_put_boolean(CORBA_octet* os,    		/* Octet stream base.	*/
		CORBA_octet** p,		/* Current position.	*/
		CORBA_boolean byte_order,	/* Byte-order.		*/
		CORBA_boolean val);		/* Value to marshal.	*/
unsigned long
cdr_put_char(CORBA_octet* os,    		/* Octet stream base.	*/
	     CORBA_octet** p,			/* Current position.	*/
	     CORBA_boolean byte_order,		/* Byte-order.		*/
	     CORBA_char val);			/* Value to marshal.	*/
unsigned long
cdr_put_octet(CORBA_octet* os,    		/* Octet stream base.	*/
	      CORBA_octet** p,			/* Current position.	*/
	      CORBA_boolean byte_order,		/* Byte-order.		*/
	      CORBA_octet val);			/* Value to marshal.	*/
unsigned long
cdr_put_unsigned_short(CORBA_octet* os,		 /* Octet stream base.	*/
		       CORBA_octet** p,		 /* Current position.	*/
		       CORBA_boolean byte_order, /* Byte-order.		*/
		       CORBA_unsigned_short val);/* Value to marshal.	*/
unsigned long
cdr_put_short(CORBA_octet* os,			/* Octet stream base.	*/
	      CORBA_octet** p,			/* Current position.	*/
	      CORBA_boolean byte_order,		/* Byte-order.		*/
	      CORBA_short val);     		/* Value to marshal.	*/
unsigned long
cdr_put_unsigned_long(CORBA_octet* os,		/* Octet stream base.	*/
		      CORBA_octet** p,		/* Current position.	*/
		      CORBA_boolean byte_order, /* Byte-order.		*/
		      CORBA_unsigned_long val);	/* Value to marshal.	*/
unsigned long
cdr_put_long(CORBA_octet* os,			/* Octet stream base.	*/
	     CORBA_octet** p,			/* Current position.	*/
	     CORBA_boolean byte_order,		/* Byte-order.		*/
	     CORBA_long val);     		/* Value to marshal.	*/
unsigned long
cdr_put_unsigned_longlong(CORBA_octet* os,	/* Octet stream base.	*/
			  CORBA_octet** p,	/* Current position.	*/
			  CORBA_boolean byte_order, /* Byte-order.	*/
			  CORBA_unsigned_longlong val);/* Value to marshal.*/
unsigned long
cdr_put_longlong(CORBA_octet* os,		/* Octet stream base.	*/
		 CORBA_octet** p,		/* Current position.	*/
		 CORBA_boolean byte_order,	/* Byte-order.		*/
		 CORBA_longlong val);  		/* Value to marshal.	*/
unsigned long
cdr_put_float(CORBA_octet* os,			/* Octet stream base.	*/
	      CORBA_octet** p,			/* Current position.	*/
	      CORBA_boolean byte_order,		/* Byte-order.		*/
	      CORBA_float val);			/* Value to marshal.	*/
unsigned long
cdr_put_double(CORBA_octet* os,			/* Octet stream base.	*/
	       CORBA_octet** p,			/* Current position.	*/
	       CORBA_boolean byte_order,	/* Byte-order.		*/
	       CORBA_double val);		/* Value to marshal.	*/
unsigned long
cdr_put_string(CORBA_octet* os,			/* Octet stream base.	*/
	       CORBA_octet** p,			/* Current position.	*/
	       CORBA_boolean byte_order,	/* Byte-order.		*/
	       CORBA_char* val);		/* Value to marshal.	*/
unsigned long
cdr_put_octets(CORBA_octet* os,			/* Octet stream base.	*/
	       CORBA_octet** p,			/* Current position.	*/
	       CORBA_boolean byte_order,	/* Byte-order.		*/
	       CORBA_octet* val,		/* Value to marshal.	*/
	       CORBA_unsigned_long len);	/* Number of octets.	*/
/*
 * UNMARSHALLING functions.
 *
 * All of the functions defined in this section are 'assert friendly' i.e. they
 * return NON-zero for success and zero for failure.  The return value is
 * actually the length of the data that was unmarshalled (NOT including
 * padding or length words).  This may or may not be useful ;^)
 */
unsigned long
cdr_get_boolean(CORBA_octet* os,		/* Octet stream base.	*/
		CORBA_octet** p,		/* Current position.	*/
		CORBA_boolean byte_order,	/* Byte-order.		*/
		CORBA_boolean* val);		/* Unmarshalled value.	*/
unsigned long
cdr_get_char(CORBA_octet* os,			/* Octet stream base.	*/
	     CORBA_octet** p,			/* Current position.	*/
	     CORBA_boolean byte_order,		/* Byte-order.		*/
	     CORBA_char* val);			/* Unmarshalled value.	*/
unsigned long
cdr_get_octet(CORBA_octet* os,			/* Octet stream base.	*/
	      CORBA_octet** p,			/* Current position.	*/
	      CORBA_boolean byte_order,		/* Byte-order.		*/
	      CORBA_octet* val);		/* Unmarshalled value.	*/
unsigned long
cdr_get_unsigned_short(CORBA_octet* os,	   	  /* Octet stream base.	*/
		       CORBA_octet** p,	   	  /* Current position.	*/
		       CORBA_boolean byte_order,  /* Byte-order. 	*/
		       CORBA_unsigned_short* val);/* Unmarshalled value.*/
unsigned long
cdr_get_short(CORBA_octet* os,			/* Octet stream base.	*/
	      CORBA_octet** p,			/* Current position.	*/
	      CORBA_boolean byte_order,		/* Byte-order.		*/
	      CORBA_short* val);     		/* Unmarshalled value.	*/
unsigned long
cdr_get_unsigned_long(CORBA_octet* os,		/* Octet stream base.	*/
		      CORBA_octet** p,		/* Current position.	*/
		      CORBA_boolean byte_order, /* Byte-order.		*/
		      CORBA_unsigned_long* val);/* Unmarshalled value.	*/
unsigned long
cdr_get_long(CORBA_octet* os,			/* Octet stream base.	*/
	     CORBA_octet** p,			/* Current position.	*/
	     CORBA_boolean byte_order,		/* Byte-order.		*/
	     CORBA_long* val);     		/* Unmarshalled value.	*/
unsigned long
cdr_get_unsigned_longlong(CORBA_octet* os,	/* Octet stream base.	*/
			  CORBA_octet** p,	/* Current position.	*/
			  CORBA_boolean byte_order, /* Byte-order.	*/
			  CORBA_unsigned_longlong* val);/*Unmarshalled value.*/
unsigned long
cdr_get_longlong(CORBA_octet* os,		/* Octet stream base.	*/
		 CORBA_octet** p,		/* Current position.	*/
		 CORBA_boolean byte_order,	/* Byte-order.		*/
		 CORBA_longlong* val);    	/* Unmarshalled value.	*/
unsigned long
cdr_get_float(CORBA_octet* os,			/* Octet stream base.	*/
	      CORBA_octet** p,			/* Current position.	*/
	      CORBA_boolean byte_order,		/* Byte-order.		*/
	      CORBA_float* val);		/* Unmarshalled value.	*/
unsigned long
cdr_get_double(CORBA_octet* os,			/* Octet stream base.	*/
	       CORBA_octet** p,			/* Current position.	*/
	       CORBA_boolean byte_order,	/* Byte-order.		*/
	       CORBA_double* val);		/* Unmarshalled value.	*/
unsigned long
cdr_get_string(CORBA_octet* os,			/* Octet stream base.	*/
	       CORBA_octet** p,			/* Current position.	*/
	       CORBA_boolean byte_order,	/* Byte-order.		*/
	       CORBA_char** val);		/* Unmarshalled value.	*/
unsigned long
cdr_get_octets(CORBA_octet* os,			/* Octet stream base.	*/
	       CORBA_octet** p,			/* Current position.	*/
	       CORBA_boolean byte_order,	/* Byte-order.		*/
	       CORBA_octet** val);		/* Unmarshalled value.	*/

#if defined (__cplusplus)
}
#endif

/***************************************************************/
#endif /* CDR_H */
