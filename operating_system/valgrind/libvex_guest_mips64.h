
/*---------------------------------------------------------------*/
/*--- begin                             libvex_guest_mips64.h ---*/
/*---------------------------------------------------------------*/

/*
   This file is part of Valgrind, a dynamic binary instrumentation
   framework.

   Copyright (C) 2010-2017 RT-RK
      mips-valgrind@rt-rk.com

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
   02110-1301, USA.

   The GNU General Public License is contained in the file COPYING.

   Neither the names of the U.S. Department of Energy nor the
   University of California nor the names of its contributors may be
   used to endorse or promote products derived from this software
   without prior written permission.
*/

#ifndef __LIBVEX_PUB_GUEST_MIPS64_H
#define __LIBVEX_PUB_GUEST_MIPS64_H

#include "libvex_basictypes.h"
#include "libvex_emnote.h"


/*---------------------------------------------------------------*/
/*--- Vex's representation of the MIPS64 CPU state.           ---*/
/*---------------------------------------------------------------*/

typedef
   struct {
      /*    0 */ ULong host_EvC_FAILADDR;
      /*    8 */ unsigned int host_EvC_COUNTER;
      /*   12 */ unsigned int _padding1;

      /* CPU Registers */
      /*   16 */ ULong guest_r0;   /* Hardwired to 0. */
      /*   24 */ ULong guest_r1;   /* Assembler temporary */
      /*   32 */ ULong guest_r2;   /* Values for function returns ...*/
      /*   40 */ ULong guest_r3;   /* ... and expression evaluation */
      /*   48 */ ULong guest_r4;   /* Function arguments */
      /*   56 */ ULong guest_r5;
      /*   64 */ ULong guest_r6;
      /*   72 */ ULong guest_r7;
      /*   80 */ ULong guest_r8;
      /*   88 */ ULong guest_r9;
      /*   96 */ ULong guest_r10;
      /*  104 */ ULong guest_r11;
      /*  112 */ ULong guest_r12;  /* Temporaries */
      /*  120 */ ULong guest_r13;
      /*  128 */ ULong guest_r14;
      /*  136 */ ULong guest_r15;
      /*  144 */ ULong guest_r16;  /* Saved temporaries */
      /*  152 */ ULong guest_r17;
      /*  160 */ ULong guest_r18;
      /*  168 */ ULong guest_r19;
      /*  176 */ ULong guest_r20;
      /*  184 */ ULong guest_r21;
      /*  192 */ ULong guest_r22;
      /*  200 */ ULong guest_r23;
      /*  208 */ ULong guest_r24;  /* Temporaries */
      /*  216 */ ULong guest_r25;
      /*  224 */ ULong guest_r26;  /* Reserved for OS kernel */
      /*  232 */ ULong guest_r27;
      /*  240 */ ULong guest_r28;  /* Global pointer */
      /*  248 */ ULong guest_r29;  /* Stack pointer */
      /*  256 */ ULong guest_r30;  /* Frame pointer */
      /*  264 */ ULong guest_r31;  /* Return address */
      /*  272 */ ULong guest_PC;   /* Program counter */
      /*  280 */ ULong guest_HI;   /* Multiply and divide reg higher result */
      /*  288 */ ULong guest_LO;   /* Multiply and divide reg lower result */

      /* FPU Registers */
      /*  296 */ ULong guest_f0;   /* Floating point gen. purpose registers */
      /*  304 */ ULong guest_f1;
      /*  312 */ ULong guest_f2;
      /*  320 */ ULong guest_f3;
      /*  328 */ ULong guest_f4;
      /*  336 */ ULong guest_f5;
      /*  344 */ ULong guest_f6;
      /*  352 */ ULong guest_f7;
      /*  360 */ ULong guest_f8;
      /*  368 */ ULong guest_f9;
      /*  376 */ ULong guest_f10;
      /*  384 */ ULong guest_f11;
      /*  392 */ ULong guest_f12;
      /*  400 */ ULong guest_f13;
      /*  408 */ ULong guest_f14;
      /*  416 */ ULong guest_f15;
      /*  424 */ ULong guest_f16;
      /*  432 */ ULong guest_f17;
      /*  440 */ ULong guest_f18;
      /*  448 */ ULong guest_f19;
      /*  456 */ ULong guest_f20;
      /*  464 */ ULong guest_f21;
      /*  472 */ ULong guest_f22;
      /*  480 */ ULong guest_f23;
      /*  488 */ ULong guest_f24;
      /*  496 */ ULong guest_f25;
      /*  504 */ ULong guest_f26;
      /*  512 */ ULong guest_f27;
      /*  520 */ ULong guest_f28;
      /*  528 */ ULong guest_f29;
      /*  536 */ ULong guest_f30;
      /*  544 */ ULong guest_f31;

      /*  552 */ unsigned int guest_FIR;
      /*  556 */ unsigned int guest_FCCR;
      /*  560 */ unsigned int guest_FEXR;
      /*  564 */ unsigned int guest_FENR;
      /*  568 */ unsigned int guest_FCSR;
      /*  572 */ unsigned int guest_CP0_status;

      /* TLS pointer for the thread. It's read-only in user space. On Linux it
         is set in user space by various thread-related syscalls.
         User Local Register.
         This register provides read access to the coprocessor 0
         UserLocal register, if it is implemented. In some operating
         environments, the UserLocal register is a pointer to a thread-specific
         storage block.
      */
      /*  576 */ ULong guest_ULR;

      /* Emulation notes */
      /*  584 */ unsigned int guest_EMNOTE;
      /*  588 */ unsigned int guest_COND;

      /* For clflush: record start and length of area to invalidate */
      /*  592 */ ULong guest_CMSTART;
      /*  600 */ ULong guest_CMLEN;

      /*  608 */ ULong guest_NRADDR;

      /*  616 */ ULong guest_LLaddr;
      /*  624 */ ULong guest_LLdata;

      /*  632 */ ULong _padding2;
} VexGuestMIPS64State;

/*---------------------------------------------------------------*/
/*--- Utility functions for MIPS64 guest stuff.               ---*/
/*---------------------------------------------------------------*/

/* ALL THE FOLLOWING ARE VISIBLE TO LIBRARY CLIENT. */

/* Initialise all guest MIPS64 state. */

extern
void LibVEX_GuestMIPS64_initialise ( /*OUT*/VexGuestMIPS64State* vex_state );

/* FR bit of CP0_STATUS_FR register */
#define MIPS_CP0_STATUS_FR (1ul << 26)

#endif /* ndef __LIBVEX_PUB_GUEST_MIPS64_H */

/*---------------------------------------------------------------*/
/*---                                   libvex_guest_mips64.h ---*/
/*---------------------------------------------------------------*/

