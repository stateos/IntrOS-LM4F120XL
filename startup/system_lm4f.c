/******************************************************************************
 * @file    system_stm32f4xx.c
 * @author  Rajmund Szymanski
 * @date    20.11.2015
 * @brief   This file provides set of configuration functions for LM4F uC.
 ******************************************************************************/

#include <lm4f.h>
#include <hw_types.h>
#include <hw_sysctl.h>
#include <sysctl.h>
#include <rom.h>

/* -------------------------------------------------------------------------- */

__attribute__ (( weak ))
void SystemInit( void )
{
	ROM_SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ); // 80MHz
}

/* -------------------------------------------------------------------------- */

__attribute__ (( weak ))
uint32_t SystemCoreClock = 80000000;

/* -------------------------------------------------------------------------- */
