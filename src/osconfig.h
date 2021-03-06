/******************************************************************************

    @file    IntrOS: osconfig.h
    @author  Rajmund Szymanski
    @date    16.12.2020
    @brief   IntrOS config file for LM4F uC.

 ******************************************************************************

   Copyright (c) 2018 Rajmund Szymanski. All rights reserved.

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to
   deal in the Software without restriction, including without limitation the
   rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
   sell copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included
   in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
   OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
   THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
   IN THE SOFTWARE.

 ******************************************************************************/

#pragma once

// ----------------------------
// cpu frequency in Hz
// default value: 80000000
#define CPU_FREQUENCY  80000000

// ----------------------------
// os frequency in Hz
// dafault value: 1000
#define OS_FREQUENCY       1000

// ----------------------------
// critical sections protection level
// OS_LOCK_LEVEL == 0 or  __CORTEX_M <  3 => entrance to a critical section blocks all interrupts
// OS_LOCK_LEVEL >  0 and __CORTEX_M >= 3 => entrance to a critical section blocks interrupts with urgency lower or equal (the priority value greater or equal) than OS_LOCK_LEVEL
// default value: 0
#define OS_LOCK_LEVEL         0

// ----------------------------
// default task stack size in bytes
// default value: 256
#define OS_STACK_SIZE      1024

// ----------------------------
// task stack guard size in bytes (if MPU is present, indicates the size of the MPU region)
// DEBUG => the default value depends on the port settings
// otherwise => default value: 0
#define OS_GUARD_SIZE        32

// ----------------------------
// bit size of system timer counter
// available values: 16, 32, 64
// default value: 32
#define OS_TIMER_SIZE        32

// ----------------------------
// system procedure for starting the task
// available values: 0, 1
// 0 => task function will be executed into an infinite system-implemented loop
// 1 => while return from the task function, tsk_exit will be executed
// default value: 0
#define OS_TASK_EXIT          0

// ----------------------------
// indicates the use of atomic functions
// available values: 0, 1
// default value: 0
#define OS_ATOMICS            0
