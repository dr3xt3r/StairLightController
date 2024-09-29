/*************************************************************************
 * @file         led.c
 * @author       Richard Vano
 * @brief        LED abstraction module
 *
 * This module provides an abstraction for LED handling
 *
 *************************************************************************/

/*************************************************************************
 * Includes
 *************************************************************************/
#include "led.h"
#include "bsp_io_bout.h" // Provided LED library

/*************************************************************************
 * Function definitions
 *************************************************************************/
void ledInit(void)
{
	bsp_io_bout_init(); // Initialize the LED (hardware-specific)
}

void ledChangeState(bool_t state)
{
	if (state == true)
	{
		bsp_io_bout_set(true); // Turn on the LED (hardware-specific)
	}
	else
	{
		bsp_io_bout_set(false); // Turn off the LED (hardware-specific)
	}
}

void ledOff(void)
{
	bsp_io_bout_set(false); // Turn off the LED (hardware-specific)
}
