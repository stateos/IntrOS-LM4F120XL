/******************************************************************************

    @file    IntrOS: osport.c
    @author  Rajmund Szymanski
    @date    28.12.2017
    @brief   IntrOS port file for LM4F uC.

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

#include <oskernel.h>

/* -------------------------------------------------------------------------- */

void port_sys_init( void )
{
#if HW_TIMER_SIZE == 0

/******************************************************************************
 Non-tick-less mode: configuration of system timer
 It must generate interrupts with frequency OS_FREQUENCY
*******************************************************************************/

	#if (CPU_FREQUENCY)/(OS_FREQUENCY)-1 <= SysTick_LOAD_RELOAD_Msk

	SysTick_Config((CPU_FREQUENCY)/(OS_FREQUENCY));

	#elif defined(ST_FREQUENCY) && \
	    (ST_FREQUENCY)/(OS_FREQUENCY)-1 <= SysTick_LOAD_RELOAD_Msk

	NVIC_SetPriority(SysTick_IRQn, 0xFF);

	SysTick->LOAD = (ST_FREQUENCY)/(OS_FREQUENCY)-1;
	SysTick->VAL  = 0U;
	SysTick->CTRL = SysTick_CTRL_ENABLE_Msk|SysTick_CTRL_TICKINT_Msk;

	#else
	#error Incorrect SysTick frequency!
	#endif

/******************************************************************************
 End of configuration
*******************************************************************************/

#else //HW_TIMER_SIZE

/******************************************************************************
 Tick-less mode: configuration of system timer
 It must be rescaled to frequency OS_FREQUENCY
*******************************************************************************/

	#if (CPU_FREQUENCY)/(OS_FREQUENCY)-1 > UINT16_MAX
	#error Incorrect Timer frequency!
	#endif

	SYSCTL->RCGCWTIMER |= SYSCTL_RCGCWTIMER_R0;
	port_set_barrier();

	WTIMER0->CFG  = 4;
	WTIMER0->TAMR = TIMER_TAMR_TAMR_PERIOD;
	WTIMER0->TAPR = (CPU_FREQUENCY)/(OS_FREQUENCY)-1;
	WTIMER0->CTL  = TIMER_CTL_TAEN;

/******************************************************************************
 End of configuration
*******************************************************************************/

#endif//HW_TIMER_SIZE
}

/* -------------------------------------------------------------------------- */

#if HW_TIMER_SIZE == 0

/******************************************************************************
 Non-tick-less mode: interrupt handler of system timer
*******************************************************************************/

void SysTick_Handler( void )
{
	SysTick->CTRL;
	core_sys_tick();
}

/******************************************************************************
 End of the handler
*******************************************************************************/

#else //HW_TIMER_SIZE

/******************************************************************************
 Tick-less mode: interrupt handler of system timer
*******************************************************************************/

/******************************************************************************
 End of the handler
*******************************************************************************/

#endif//HW_TIMER_SIZE

/* -------------------------------------------------------------------------- */
