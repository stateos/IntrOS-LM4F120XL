/******************************************************************************

    @file    IntrOS: osport.h
    @author  Rajmund Szymanski
    @date    28.12.2017
    @brief   IntrOS port definitions for LM4F uC.

 ******************************************************************************

    IntrOS - Copyright (C) 2013 Rajmund Szymanski.

    This file is part of IntrOS distribution.

    IntrOS is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published
    by the Free Software Foundation; either version 3 of the License,
    or (at your option) any later version.

    IntrOS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.

 ******************************************************************************/

#ifndef __INTROSPORT_H
#define __INTROSPORT_H

#include <LM4F120H5QR.h>
#include <inc/hw_timer.h>
#include <inc/hw_sysctl.h>
#ifndef   NOCONFIG
#include <osconfig.h>
#endif
#include <osdefs.h>

#ifdef __cplusplus
extern "C" {
#endif

/* -------------------------------------------------------------------------- */

#ifndef CPU_FREQUENCY
#define CPU_FREQUENCY  80000000 /* Hz */
#endif

/* -------------------------------------------------------------------------- */

#ifndef OS_FREQUENCY
#define OS_FREQUENCY       1000 /* Hz */
#endif

/* -------------------------------------------------------------------------- */

#ifdef  HW_TIMER_SIZE
#error  HW_TIMER_SIZE is an internal definition!
#elif   OS_FREQUENCY > 1000 
#define HW_TIMER_SIZE        32
#else
#define HW_TIMER_SIZE         0
#endif

/* -------------------------------------------------------------------------- */
// alternate clock source for SysTick

#ifdef  ST_FREQUENCY
#error  ST_FREQUENCY is an internal definition!
#else
#define ST_FREQUENCY  (16000000/4)
#endif

/* -------------------------------------------------------------------------- */
// return current system time

#if HW_TIMER_SIZE >= 32

__STATIC_INLINE
uint32_t port_sys_time( void )
{
	return -WTIMER0->TAV;
}

#endif

/* -------------------------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

/* -------------------------------------------------------------------------- */

#endif//__INTROSPORT_H
