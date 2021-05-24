
/*---------------------------------------------------------------*/
/*--- begin                             libvex_guest_mips32.h ---*/
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
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307, USA.

   The GNU General Public License is contained in the file COPYING.
*/

#ifndef __LIBVEX_PUB_GUEST_MIPS32_H
#define __LIBVEX_PUB_GUEST_MIPS32_H

#include "libvex_basictypes.h"


/*---------------------------------------------------------------*/
/*--- Vex's representation of the MIPS32 CPU state.           ---*/
/*---------------------------------------------------------------*/

typedef
   struct {
      /*    0 */ ::u32 host_EvC_FAILADDR;
      /*    4 */ ::u32 host_EvC_COUNTER;

      /* CPU Registers */
      /*    8 */ ::u32 guest_r0;   /* Hardwired to 0. */
      /*   12 */ ::u32 guest_r1;   /* Assembler temporary */
      /*   16 */ ::u32 guest_r2;   /* Values for function returns ...*/
      /*   20 */ ::u32 guest_r3;   /* ... and expression evaluation */
      /*   24 */ ::u32 guest_r4;   /* Function arguments */
      /*   28 */ ::u32 guest_r5;
      /*   32 */ ::u32 guest_r6;
      /*   36 */ ::u32 guest_r7;
      /*   40 */ ::u32 guest_r8;   /* Temporaries */
      /*   44 */ ::u32 guest_r9;
      /*   48 */ ::u32 guest_r10;
      /*   52 */ ::u32 guest_r11;
      /*   56 */ ::u32 guest_r12;
      /*   60 */ ::u32 guest_r13;
      /*   64 */ ::u32 guest_r14;
      /*   68 */ ::u32 guest_r15;
      /*   72 */ ::u32 guest_r16;  /* Saved temporaries */
      /*   76 */ ::u32 guest_r17;
      /*   80 */ ::u32 guest_r18;
      /*   84 */ ::u32 guest_r19;
      /*   88 */ ::u32 guest_r20;
      /*   92 */ ::u32 guest_r21;
      /*   96 */ ::u32 guest_r22;
      /*  100 */ ::u32 guest_r23;
      /*  104 */ ::u32 guest_r24;  /* Temporaries */
      /*  108 */ ::u32 guest_r25;
      /*  112 */ ::u32 guest_r26;  /* Reserved for OS kernel */
      /*  116 */ ::u32 guest_r27;
      /*  120 */ ::u32 guest_r28;  /* Global pointer */
      /*  124 */ ::u32 guest_r29;  /* Stack pointer */
      /*  128 */ ::u32 guest_r30;  /* Frame pointer */
      /*  132 */ ::u32 guest_r31;  /* Return address */
      /*  136 */ ::u32 guest_PC;   /* Program counter */
      /*  140 */ ::u32 guest_HI;   /* Multiply and divide reg higher result */
      /*  144 */ ::u32 guest_LO;   /* Multiply and divide reg lower result */
      /*  148 */ ::u32 _padding1;

      /* FPU Registers */
      /*  152 */ ULong guest_f0;  /* Floating point general purpose registers */
      /*  160 */ ULong guest_f1;
      /*  168 */ ULong guest_f2;
      /*  176 */ ULong guest_f3;
      /*  184 */ ULong guest_f4;
      /*  192 */ ULong guest_f5;
      /*  200 */ ULong guest_f6;
      /*  208 */ ULong guest_f7;
      /*  216 */ ULong guest_f8;
      /*  224 */ ULong guest_f9;
      /*  232 */ ULong guest_f10;
      /*  240 */ ULong guest_f11;
      /*  248 */ ULong guest_f12;
      /*  256 */ ULong guest_f13;
      /*  264 */ ULong guest_f14;
      /*  272 */ ULong guest_f15;
      /*  280 */ ULong guest_f16;
      /*  288 */ ULong guest_f17;
      /*  296 */ ULong guest_f18;
      /*  304 */ ULong guest_f19;
      /*  312 */ ULong guest_f20;
      /*  320 */ ULong guest_f21;
      /*  328 */ ULong guest_f22;
      /*  336 */ ULong guest_f23;
      /*  344 */ ULong guest_f24;
      /*  352 */ ULong guest_f25;
      /*  360 */ ULong guest_f26;
      /*  368 */ ULong guest_f27;
      /*  376 */ ULong guest_f28;
      /*  384 */ ULong guest_f29;
      /*  392 */ ULong guest_f30;
      /*  400 */ ULong guest_f31;

      /*  408 */ ::u32 guest_FIR;
      /*  412 */ ::u32 guest_FCCR;
      /*  416 */ ::u32 guest_FEXR;
      /*  420 */ ::u32 guest_FENR;
      /*  424 */ ::u32 guest_FCSR;

      /* TLS pointer for the thread. It's read-only in user space.
         On Linux it is set in user space by various thread-related
         syscalls.
         User Local Register.
         This register provides read access to the coprocessor 0
         UserLocal register, if it is implemented. In some operating
         environments, the UserLocal register is a pointer to a
         thread-specific storage block.
      */
      /*  428 */ ::u32 guest_ULR;

      /* Emulation notes */
      /*  432 */ ::u32 guest_EMNOTE;

      /* For clflush: record start and length of area to invalidate. */
      /*  436 */ ::u32 guest_CMSTART;
      /*  440 */ ::u32 guest_CMLEN;
      /*  444 */ ::u32 guest_NRADDR;

      /*  448 */ ::u32 guest_COND;

      /* MIPS32 DSP ASE(r2) specific registers. */
      /*  452 */ ::u32 guest_DSPControl;
      /*  456 */ ULong guest_ac0;
      /*  464 */ ULong guest_ac1;
      /*  472 */ ULong guest_ac2;
      /*  480 */ ULong guest_ac3;

      /*  488 */ ::u32 guest_CP0_status;

      /*  492 */ ::u32 guest_LLaddr;
      /*  496 */ ::u32 guest_LLdata;

      /*  500 */ ::u32 _padding2[3];
} VexGuestMIPS32State;
/*---------------------------------------------------------------*/
/*--- Utility functions for MIPS32 guest stuff.               ---*/
/*---------------------------------------------------------------*/

/* ALL THE FOLLOWING ARE VISIBLE TO LIBRARY CLIENT. */

/* Initialise all guest MIPS32 state. */

extern
void LibVEX_GuestMIPS32_initialise ( /*OUT*/VexGuestMIPS32State* vex_state );

/* FR bit of CP0_STATUS_FR register */
#define MIPS_CP0_STATUS_FR (1ul << 26)

#endif /* ndef __LIBVEX_PUB_GUEST_MIPS32_H */


/*---------------------------------------------------------------*/
/*---                                   libvex_guest_mips32.h ---*/
/*---------------------------------------------------------------*/
