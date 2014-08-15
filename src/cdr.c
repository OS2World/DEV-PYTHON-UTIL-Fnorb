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
  File:         $Source: /units/arch/src/Fnorb-1.0/src/RCS/cdr.c,v $
  Version:      @(#)$RCSfile: cdr.c,v $ $Revision: 1.9 $


  Description:	Marshalling/unmarshalling functions for the CORBA Common Data
                Representation (CDR).

****************************************************************/

#if !defined(lint)
static const char rcsid[] = "@(#)$RCSfile: cdr.c,v $ $Revision: 1.9 $";
#endif

/*
 * Standard library includes (e.g., stdio)
 */
#include <stdlib.h>				/* malloc...		*/
#include <string.h>				/* memcpy...		*/

/*
 * Application library includes (e.g., X, DCE)
 */

/*
 * DSTC library includes (e.g., dstc_stdlib.h)
 */

/*
 * Project library includes              
 */
#include "fnorb.h"

/*
 * Local file includes
 */
#include "cdr.h"

/* Useful macros! */
#define MEMCPY(src, target, n) (void)memcpy((void*)(src), (void*)(target), (n))
#define SWAP(byte_order) ((byte_order) != HOST_BYTE_ORDER)


/*
 * The 'cdr_count_' functions calculate the space required to marshal data
 * onto an octet stream (including any padding that is required to abide by
 * the CDR alignment rules).
 */
unsigned long
cdr_count_boolean(CORBA_octet* os,    		/* Octet stream base.	*/
		  CORBA_octet** p,		/* Current position.	*/
		  CORBA_boolean byte_order,	/* Byte-order.		*/
		  CORBA_boolean val)		/* Value to marshal.	*/
{
    /* N.B. The parameters 'os', 'byte_order' and 'val',  are not used 	*/
    /* ---- in this function, but are left in to keep the interface to	*/
    /*      all of the 'cdr_' functions consistent.			*/
    (*p)++;

    return 1; /* Always 1 as no alignment required. */
}

unsigned long
cdr_count_char(CORBA_octet* os,    		/* Octet stream base.	*/
	       CORBA_octet** p,			/* Current position.	*/
	       CORBA_boolean byte_order,	/* Byte-order.		*/
	       CORBA_char val)			/* Value to marshal.	*/
{
    /* N.B. The parameters 'os', 'byte_order' and 'val',  are not used 	*/
    /* ---- in this function, but are left in to keep the interface to	*/
    /*      all of the 'cdr_' functions consistent.			*/
    (*p)++;

    return 1; /* Always 1 as no alignment required. */
}

unsigned long
cdr_count_octet(CORBA_octet* os,    		/* Octet stream base.	*/
		CORBA_octet** p,		/* Current position.	*/
		CORBA_boolean byte_order,	/* Byte-order.		*/
		CORBA_octet val)		/* Value to marshal.	*/
{
    /* N.B. The parameters 'os', 'byte_order' and 'val',  are not used 	*/
    /* ---- in this function, but are left in to keep the interface to	*/
    /*      all of the 'cdr_' functions consistent.			*/
    (*p)++;

    return 1; /* Always 1 as no alignment required. */
}

unsigned long
cdr_count_unsigned_short(CORBA_octet* os,	  /* Octet stream base.	*/
			 CORBA_octet** p,	  /* Current position.	*/
			 CORBA_boolean byte_order,/* Byte-order.	*/
			 CORBA_unsigned_short val)/* Value to marshal.	*/
{
    /* N.B. The parameters 'byte_order' and 'val',  are not used in 	*/
    /* ---- this function, but are left in to keep the interface to all */
    /*      of the 'cdr_' functions consistent.				*/

    CORBA_octet* start = *p;

    /* Within the octet stream the value must be aligned on a word	*/
    /* boundary that is a multiple of its size.				*/
    while ((unsigned long) ((*p) - os) % 2 != 0) {
	(*p)++;
    }
    (*p) += 2;

    return (*p) - start;
}

unsigned long
cdr_count_short(CORBA_octet* os,		/* Octet stream base.	*/
		CORBA_octet** p,		/* Current position.	*/
		CORBA_boolean byte_order,	/* Byte-order.		*/
		CORBA_short val)		/* Value to marshal.	*/
{
    return cdr_count_unsigned_short(os, p, byte_order, val);
}

unsigned long
cdr_count_unsigned_long(CORBA_octet* os,	 /* Octet stream base.	*/
			CORBA_octet** p, 	 /* Current position.	*/
			CORBA_boolean byte_order,/* Byte-order.		*/
			CORBA_unsigned_long val) /* Value to marshal.	*/
{
    /* N.B. The parameters 'byte_order' and 'val',  are not used in 	*/
    /* ---- this function, but are left in to keep the interface to all */
    /*      of the 'cdr_' functions consistent.				*/

    CORBA_octet* start = *p;

    /* Within the octet stream the value must be aligned on a word	*/
    /* boundary that is a multiple of its size.				*/
    while ((unsigned long) ((*p) - os) % 4 != 0) {
	(*p)++;
    }
    (*p) += 4;

    return (*p) - start;
}

unsigned long
cdr_count_long(CORBA_octet* os,			/* Octet stream base.	*/
	       CORBA_octet** p,			/* Current position.	*/
	       CORBA_boolean byte_order,	/* Byte-order.		*/
	       CORBA_long val)			/* Value to marshal.	*/
{
    return cdr_count_unsigned_long(os, p, byte_order, val);
}

unsigned long
cdr_count_unsigned_longlong(CORBA_octet* os,	        /* Octet stream base.*/
			    CORBA_octet** p,		/* Current position. */
			    CORBA_boolean byte_order,   /* Byte-order.       */
			    CORBA_unsigned_longlong val)/* Value to marshal. */
{
    /* N.B. The parameters 'byte_order' and 'val',  are not used in 	*/
    /* ---- this function, but are left in to keep the interface to all */
    /*      of the 'cdr_' functions consistent.				*/

    CORBA_octet* start = *p;

    /* Within the octet stream the value must be aligned on a word	*/
    /* boundary that is a multiple of its size.				*/
    while ((unsigned long) ((*p) - os) % 8 != 0) {
	(*p)++;
    }
    (*p) += 8;

    return (*p) - start;
}

unsigned long
cdr_count_longlong(CORBA_octet* os,		/* Octet stream base.	*/
		   CORBA_octet** p,		/* Current position.	*/
		   CORBA_boolean byte_order,	/* Byte-order.		*/
		   CORBA_longlong val)		/* Value to marshal.	*/
{
    return cdr_count_unsigned_longlong(os, p, byte_order, val);
}

unsigned long
cdr_count_float(CORBA_octet* os,		/* Octet stream base.	*/
		CORBA_octet** p,		/* Current position.	*/
		CORBA_boolean byte_order,	/* Byte-order.		*/
		CORBA_float val)		/* Value to marshal.	*/
{
    /* N.B. The parameters 'byte_order' and 'val',  are not used in 	*/
    /* ---- this function, but are left in to keep the interface to all */
    /*      of the 'cdr_' functions consistent.				*/

    CORBA_octet* start = *p;

    /* Within the octet stream the value must be aligned on a word	*/
    /* boundary that is a multiple of its size.				*/
    while ((unsigned long) ((*p) - os) % 4 != 0) {
	(*p)++;
    }
    (*p) += 4;

    return (*p) - start;
}

unsigned long
cdr_count_double(CORBA_octet* os,		/* Octet stream base.	*/
		 CORBA_octet** p,		/* Current position.	*/
		 CORBA_boolean byte_order,	/* Byte-order.		*/
		 CORBA_double val)		/* Value to marshal.	*/
{
    /* N.B. The parameters 'byte_order' and 'val',  are not used in 	*/
    /* ---- this function, but are left in to keep the interface to all */
    /*      of the 'cdr_' functions consistent.				*/

    CORBA_octet* start = *p;

    /* Within the octet stream the value must be aligned on a word	*/
    /* boundary that is a multiple of its size.				*/
    while ((unsigned long) ((*p) - os) % 8 != 0) {
	(*p)++;
    }
    (*p) += 8;

    return (*p) - start;
}

unsigned long
cdr_count_string(CORBA_octet* os,		/* Octet stream base.	*/
		 CORBA_octet** p,		/* Current position.	*/
		 CORBA_boolean byte_order,	/* Byte-order.		*/
		 CORBA_char* val)		/* Value to marshal.	*/
{
    CORBA_octet* start = *p;
    CORBA_unsigned_long len = strlen((char*) val) + 1;

    /* Calculate the space required for the length of the string.	*/
    (void) cdr_count_unsigned_long(os, p, byte_order, len);

    /* Now add on the space for the string itself.			*/
    (*p) += len;

    return (*p) - start;
}

unsigned long
cdr_count_octets(CORBA_octet* os,		/* Octet stream base.	*/
		 CORBA_octet** p,		/* Current position.	*/
		 CORBA_boolean byte_order,	/* Byte-order.		*/
		 CORBA_octet* val,		/* Value to marshal.	*/
		 CORBA_unsigned_long len)	/* Number of octets.	*/
{
    /* N.B. The parameter 'val' is not used in this function, but is  	*/
    /* ---- left in to keep the interface to all of the 'cdr_' 		*/
    /*      functions consistent.					*/

    CORBA_octet* start = *p;

    /* Calculate the space required for the length of the sequence.	*/
    (void) cdr_count_unsigned_long(os, p, byte_order, len);

    /* Now add on the space for the sequence itself.			*/
    (*p) += len;
    
    return (*p) - start;
}

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
		CORBA_boolean val)		/* Value to marshal.	*/
{
    /* N.B. The parameters 'os' and 'byte_order',  are not used in this	*/
    /* ---- function, but are left in to keep the interface to all of 	*/
    /*      the 'cdr_' functions consistent.			*/
    (*p)[0] = val;
    (*p)++;

    return 1; /* Always 1 as no alignment required. */
}

unsigned long
cdr_put_char(CORBA_octet* os,    		/* Octet stream base.	*/
	     CORBA_octet** p,			/* Current position.	*/
	     CORBA_boolean byte_order,		/* Byte-order.		*/
	     CORBA_char val)			/* Value to marshal.	*/
{
    /* N.B. The parameters 'os' and 'byte_order',  are not used in this	*/
    /* ---- function, but are left in to keep the interface to all of 	*/
    /*      the 'cdr_' functions consistent.			*/
    (*p)[0] = val;
    (*p)++;

    return 1; /* Always 1 as no alignment required. */
}

unsigned long
cdr_put_octet(CORBA_octet* os,    		/* Octet stream base.	*/
	      CORBA_octet** p,			/* Current position.	*/
	      CORBA_boolean byte_order,		/* Byte-order.		*/
	      CORBA_octet val)			/* Value to marshal.	*/
{
    /* N.B. The parameters 'os' and 'byte_order',  are not used in this	*/
    /* ---- function, but are left in to keep the interface to all of 	*/
    /*      the 'cdr_' functions consistent.			*/
    (*p)[0] = val;
    (*p)++;

    return 1; /* Always 1 as no alignment required. */
}

unsigned long
cdr_put_unsigned_short(CORBA_octet* os,		 /* Octet stream base.	*/
		       CORBA_octet** p,		 /* Current position.	*/
		       CORBA_boolean byte_order, /* Byte-order.		*/
		       CORBA_unsigned_short val) /* Value to marshal.	*/
{
    CORBA_octet* start = *p;

    /* Within the octet stream the value must be aligned on a word	*/
    /* boundary that is a multiple of its size.				*/
    while ((unsigned long) ((*p) - os) % 2 != 0) {
	(*p)++;
    }

    if (SWAP(byte_order)) {
	(*p)[0] = ((CORBA_octet*) &val)[1];
	(*p)[1] = ((CORBA_octet*) &val)[0];
    }
    else {
	MEMCPY(*p, &val, 2);
    }
    (*p) += 2;

    return (*p) - start;
}

unsigned long
cdr_put_short(CORBA_octet* os,			/* Octet stream base.	*/
	      CORBA_octet** p,			/* Current position.	*/
	      CORBA_boolean byte_order,		/* Byte-order.		*/
	      CORBA_short val)     		/* Value to marshal.	*/
{
    return cdr_put_unsigned_short(os,p, byte_order,(CORBA_unsigned_short) val);
}

unsigned long
cdr_put_unsigned_long(CORBA_octet* os,		/* Octet stream base.	*/
		      CORBA_octet** p,		/* Current position.	*/
		      CORBA_boolean byte_order,	/* Byte-order.		*/
		      CORBA_unsigned_long val)	/* Value to marshal.	*/
{
    CORBA_octet* start = *p;

    /* Within the octet stream the value must be aligned on a word	*/
    /* boundary that is a multiple of its size.				*/
    while ((unsigned long) ((*p) - os) % 4 != 0) {
	(*p)++;
    }

    if (SWAP(byte_order)) {
	 (*p)[0] = ((CORBA_octet*) &val)[3];
	 (*p)[1] = ((CORBA_octet*) &val)[2];
	 (*p)[2] = ((CORBA_octet*) &val)[1];
	 (*p)[3] = ((CORBA_octet*) &val)[0];
    }
    else {
	MEMCPY(*p, &val, 4);
    }
    (*p) += 4;

    return (*p) - start;
}

unsigned long
cdr_put_long(CORBA_octet* os,			/* Octet stream base.	*/
	     CORBA_octet** p,			/* Current position.	*/
	     CORBA_boolean byte_order,		/* Byte-order.		*/
	     CORBA_long val)     		/* Value to marshal.	*/
{
    return cdr_put_unsigned_long(os, p, byte_order, (CORBA_unsigned_long) val);
}

unsigned long
cdr_put_unsigned_longlong(CORBA_octet* os,             /* Octet stream base. */
			  CORBA_octet** p,	       /* Current position.  */
			  CORBA_boolean byte_order,    /* Byte-order.	     */
			  CORBA_unsigned_longlong val) /* Value to marshal.  */
{
    CORBA_octet* start = *p;

    /* Within the octet stream the value must be aligned on a word	*/
    /* boundary that is a multiple of its size.				*/
    while ((unsigned long) ((*p) - os) % 8 != 0) {
	(*p)++;
    }

    if (SWAP(byte_order)) {
	(*p)[0] = (val.octets)[7];
	(*p)[1] = (val.octets)[6];
	(*p)[2] = (val.octets)[5];
	(*p)[3] = (val.octets)[4];
	(*p)[4] = (val.octets)[3];
	(*p)[5] = (val.octets)[2];
	(*p)[6] = (val.octets)[1];
	(*p)[7] = (val.octets)[0];
    }
    else {
	MEMCPY(*p, val.octets, 8);
    }
    (*p) += 8;

    return (*p) - start;
}

unsigned long
cdr_put_longlong(CORBA_octet* os,		/* Octet stream base.	*/
		 CORBA_octet** p,		/* Current position.	*/
		 CORBA_boolean byte_order,	/* Byte-order.		*/
		 CORBA_longlong val)     	/* Value to marshal.	*/
{
    return cdr_put_unsigned_longlong(os, p, byte_order, val);
}

unsigned long
cdr_put_float(CORBA_octet* os,			/* Octet stream base.	*/
	      CORBA_octet** p,			/* Current position.	*/
	      CORBA_boolean byte_order,		/* Byte-order.		*/
	      CORBA_float val)			/* Value to marshal.	*/
{
    CORBA_octet* start = *p;

    /* Within the octet stream the value must be aligned on a word	*/
    /* boundary that is a multiple of its size.				*/
    while ((unsigned long) ((*p) - os) % 4 != 0) {
	(*p)++;
    }

    if (SWAP(byte_order)) {
	(*p)[0] = ((CORBA_octet*) &val)[3];
	(*p)[1] = ((CORBA_octet*) &val)[2];
	(*p)[2] = ((CORBA_octet*) &val)[1];
	(*p)[3] = ((CORBA_octet*) &val)[0];
    }
    else {
	MEMCPY(*p, &val, 4);
    }
    (*p) += 4;

    return (*p) - start;
}

unsigned long
cdr_put_double(CORBA_octet* os,			/* Octet stream base.	*/
	       CORBA_octet** p,			/* Current position.	*/
	       CORBA_boolean byte_order,	/* Byte-order.		*/
	       CORBA_double val)		/* Value to marshal.	*/
{
    CORBA_octet* start = *p;

    /* Within the octet stream the value must be aligned on a word	*/
    /* boundary that is a multiple of its size.				*/
    while ((unsigned long) ((*p) - os) % 8 != 0) {
	(*p)++;
    }

    if (SWAP(byte_order)) {
	(*p)[0] = ((CORBA_octet*) &val)[7];
	(*p)[1] = ((CORBA_octet*) &val)[6];
	(*p)[2] = ((CORBA_octet*) &val)[5];
	(*p)[3] = ((CORBA_octet*) &val)[4];
	(*p)[4] = ((CORBA_octet*) &val)[3];
	(*p)[5] = ((CORBA_octet*) &val)[2];
	(*p)[6] = ((CORBA_octet*) &val)[1];
	(*p)[7] = ((CORBA_octet*) &val)[0];
    }
    else {
	MEMCPY(*p, &val, 8);
    }
    (*p) += 8;

    return (*p) - start;
}

unsigned long
cdr_put_string(CORBA_octet* os,			/* Octet stream base.	*/
	       CORBA_octet** p,			/* Current position.	*/
	       CORBA_boolean byte_order,	/* Byte-order.		*/
	       CORBA_char* val)			/* Value to marshal.	*/
{
    CORBA_octet* start = *p;
    CORBA_unsigned_long len = strlen((char*) val) + 1;

    /* Marshal the length of the string (including the NULL!).		*/
    cdr_put_unsigned_long(os, p, byte_order, len);

    /* Now marshal the actual contents of the string.			*/
    MEMCPY(*p, val, len);
    (*p) += len;
    
    return (*p) - start;
}

unsigned long
cdr_put_octets(CORBA_octet* os,			/* Octet stream base.	*/
	       CORBA_octet** p,			/* Current position.	*/
	       CORBA_boolean byte_order,	/* Byte-order.		*/
	       CORBA_octet* val,		/* Value to marshal.	*/
	       CORBA_unsigned_long len)		/* Number of octets.	*/
{
    CORBA_octet* start = *p;

    /* Marshal the length of the sequence.				*/
    cdr_put_unsigned_long(os, p, byte_order, len);

    /* Now marshal the actual octets.					*/
    MEMCPY(*p, val, len);
    (*p) += len;

    return (*p) - start;
}

/*
 * UNMARSHALLING functions.
 *
 * All of the functions defined in this section are 'assert friendly' i.e. they
 * return NON-zero for success and zero for failure.  The return value is
 * actually the length of the data that was unmarshalled (NOT INCLUDING
 * PADDING OR LENGTH WORDS).  This may or may not be useful ;^)
 */
unsigned long
cdr_get_boolean(CORBA_octet* os,    		/* Octet stream base.	*/
		CORBA_octet** p,		/* Current position.	*/
		CORBA_boolean byte_order,	/* Byte-order.		*/
		CORBA_boolean* val)		/* Unmarshalled value.	*/
{
    /* N.B. The parameters 'os' and 'byte_order' are not used in this 	*/
    /* ---- function, but are left in to keep the interface to all of	*/
    /*      the 'cdr_get' functions consistent.				*/
    *val = (CORBA_boolean) (*p)[0];
    (*p)++;

    return 1;
}

unsigned long
cdr_get_char(CORBA_octet* os,			/* Octet stream base	*/
	     CORBA_octet** p,			/* Current position.	*/
	     CORBA_boolean byte_order,		/* Byte-order.		*/
	     CORBA_char* val)			/* Unmarshalled value.	*/
{
    /* N.B. The parameters 'os' and 'byte_order' are not used in this 	*/
    /* ---- function, but are left in to keep the interface to all of	*/
    /*      the 'cdr_get' functions consistent.				*/
    *val = (CORBA_char) (*p)[0];
    (*p)++;

    return 1;
}

unsigned long
cdr_get_octet(CORBA_octet* os,			/* Octet stream base.	*/
	      CORBA_octet** p,			/* Current position.	*/
	      CORBA_boolean byte_order,		/* Byte-order.		*/
	      CORBA_octet* val)			/* Unmarshalled value.	*/
{
    /* N.B. The parameters 'os' and 'byte_order' are not used in this 	*/
    /* ---- function, but are left in to keep the interface to all of	*/
    /*      the 'cdr_get' functions consistent.				*/
    *val = (CORBA_octet) (*p)[0];
    (*p)++;

    return 1;
}

unsigned long
cdr_get_unsigned_short(CORBA_octet* os,		 /* Octet stream base.	*/
		       CORBA_octet** p,		 /* Current position.	*/
		       CORBA_boolean byte_order, /* Byte-order.		*/
		       CORBA_unsigned_short* val)/* Unmarshalled value.	*/
{
    /* Within the octet stream the value must be aligned on a word	*/
    /* boundary that is a multiple of its size.				*/
    while ((unsigned long) ((*p) - os) % 2 != 0) {
	(*p)++;
    }

    if (SWAP(byte_order)) {
	((CORBA_octet*) val)[1] = (*p)[0];
	((CORBA_octet*) val)[0] = (*p)[1];
    }
    else {
	MEMCPY(val, *p, 2);
    }
    (*p) += 2;

    return 2;
}

unsigned long
cdr_get_short(CORBA_octet* os,			/* Octet stream base.	*/
	      CORBA_octet** p,			/* Current position.	*/
	      CORBA_boolean byte_order,		/* Byte-order.		*/
	      CORBA_short* val)     		/* Unmarshalled value.	*/
{
    return cdr_get_unsigned_short(os,p,byte_order,(CORBA_unsigned_short*) val);
}

unsigned long
cdr_get_unsigned_long(CORBA_octet* os,		/* Octet stream base.	*/
		      CORBA_octet** p,		/* Current position.	*/
		      CORBA_boolean byte_order,	/* Byte-order.		*/
		      CORBA_unsigned_long* val)	/* Unmarshalled value.	*/
{
    /* Within the octet stream the value must be aligned on a word	*/
    /* boundary that is a multiple of its size.				*/
    while ((unsigned long) ((*p) - os) % 4 != 0) {
	(*p)++;
    }

    if (SWAP(byte_order)) {
	((CORBA_octet*) val)[3] = (*p)[0];
	((CORBA_octet*) val)[2] = (*p)[1];
	((CORBA_octet*) val)[1] = (*p)[2];
	((CORBA_octet*) val)[0] = (*p)[3];
    }
    else {
	MEMCPY(val, *p, 4);
    }
    (*p) += 4;

    return 4;
}

unsigned long
cdr_get_long(CORBA_octet* os,			/* Octet stream base.	*/
	     CORBA_octet** p,			/* Current position.	*/
	     CORBA_boolean byte_order,		/* Byte-order.		*/
	     CORBA_long* val)     		/* Unmarshalled value.	*/
{
    return cdr_get_unsigned_long(os, p, byte_order, (CORBA_unsigned_long*)val);
}

unsigned long
cdr_get_unsigned_longlong(CORBA_octet* os,	/* Octet stream base.	*/
			  CORBA_octet** p,	/* Current position.	*/
			  CORBA_boolean byte_order,/* Byte-order.	*/
			  CORBA_unsigned_longlong* val)	/* Unmarshalled value.*/
{
    /* Within the octet stream the value must be aligned on a word	*/
    /* boundary that is a multiple of its size.				*/
    while ((unsigned long) ((*p) - os) % 8 != 0) {
	(*p)++;
    }

    if (SWAP(byte_order)) {
	(val->octets)[7] = (*p)[0];
	(val->octets)[6] = (*p)[1];
	(val->octets)[5] = (*p)[2];
	(val->octets)[4] = (*p)[3];
	(val->octets)[3] = (*p)[4];
	(val->octets)[2] = (*p)[5];
	(val->octets)[1] = (*p)[6];
	(val->octets)[0] = (*p)[7];
    }
    else {
	MEMCPY(val->octets, *p, 8);
    }
    (*p) += 8;

    return 8;
}

unsigned long
cdr_get_longlong(CORBA_octet* os,		/* Octet stream base.	*/
		 CORBA_octet** p,		/* Current position.	*/
		 CORBA_boolean byte_order,	/* Byte-order.		*/
		 CORBA_longlong* val)  		/* Unmarshalled value.	*/
{
    return cdr_get_unsigned_longlong(os, p, byte_order,
				     (CORBA_unsigned_longlong*) val);
}

unsigned long
cdr_get_float(CORBA_octet* os,			/* Octet stream base.	*/
	      CORBA_octet** p,			/* Current position.	*/
	      CORBA_boolean byte_order,		/* Byte-order.		*/
	      CORBA_float* val)			/* Unmarshalled value.	*/
{
    /* Within the octet stream the value must be aligned on a word	*/
    /* boundary that is a multiple of its size.				*/
    while ((unsigned long) ((*p) - os) % 4 != 0) {
	(*p)++;
    }

    if (SWAP(byte_order)) {
	((CORBA_octet*) val)[3] = (*p)[0];
	((CORBA_octet*) val)[2] = (*p)[1];
	((CORBA_octet*) val)[1] = (*p)[2];
	((CORBA_octet*) val)[0] = (*p)[3];
    }
    else {
	MEMCPY(val, *p, 4);
    }
    (*p) += 4;

    return 4;
}

unsigned long
cdr_get_double(CORBA_octet* os,			/* Octet stream base.	*/
	       CORBA_octet** p,			/* Current position.	*/
	       CORBA_boolean byte_order,	/* Byte-order.		*/
	       CORBA_double* val)		/* Unmarshalled value.	*/
{
    /* Within the octet stream the value must be aligned on a word	*/
    /* boundary that is a multiple of its size.				*/
    while ((unsigned long) ((*p) - os) % 8 != 0) {
	(*p)++;
    }

    if (SWAP(byte_order)) {
	((CORBA_octet*) val)[7] = (*p)[0];
	((CORBA_octet*) val)[6] = (*p)[1];
	((CORBA_octet*) val)[5] = (*p)[2];
	((CORBA_octet*) val)[4] = (*p)[3];
	((CORBA_octet*) val)[3] = (*p)[4];
	((CORBA_octet*) val)[2] = (*p)[5];
	((CORBA_octet*) val)[1] = (*p)[6];
	((CORBA_octet*) val)[0] = (*p)[7];
    }
    else {
	MEMCPY(val, *p, 8);
    }
    (*p) += 8;

    return 8;
}

unsigned long
cdr_get_string(CORBA_octet* os,			/* Octet stream base.	*/
	       CORBA_octet** p,			/* Current position.	*/
	       CORBA_boolean byte_order,	/* Byte-order.		*/
	       CORBA_char** val)		/* Unmarshalled value.	*/
{
    CORBA_unsigned_long len;

    /* Get the length of the string (the length *includes* the NULL!).	*/
    cdr_get_unsigned_long(os, p, byte_order, &len);

    /* Strings CANNOT be zero length because the length always includes	*/
    /* the NULL terminator.  Therefore, even an 'empty' string is of	*/
    /* length 1.							*/
    if (len == 0) {
	return 0;
    }

    *val = (CORBA_char*) malloc(len);
    if (*val != 0) {
	/* Now get the actual contents of the string.			*/
	MEMCPY(*val, *p, len);
	(*p) += len;
    }
    
    return len;
}

unsigned long
cdr_get_octets(CORBA_octet* os,			/* Octet stream base.	*/
	       CORBA_octet** p,			/* Current position.	*/
	       CORBA_boolean byte_order,	/* Byte-order.		*/
	       CORBA_octet** val)		/* Unmarshalled value.	*/
{
    CORBA_unsigned_long len;

    /* Get the number of octets.					*/
    cdr_get_unsigned_long(os, p, byte_order, &len);
    if (len != 0) {
	*val = (CORBA_octet*) malloc(len);
	if (*val != 0) {
	    /* Now get the actual octets.			        */
	    MEMCPY(*val, *p, len);
	    (*p) += len;
	}
    }
    
    return len;
}

/************************************************************************/
/* end of cdr.c */
