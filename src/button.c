/*************************************************************************
 * @file         button.c
 * @author       Richard Vano
 * @brief        Button abstraction module
 *
 * This module provides an abstraction for button handling
 *
 *************************************************************************/

/*************************************************************************
 * Includes
 *************************************************************************/
#include "button.h"
#include "bsp_io_bin.h" // Provided button library

/*************************************************************************
 * Function definitions
 *************************************************************************/
void buttonInit(void)
{
	bsp_io_bin_init(); // Initialize the button (hardware-specific)
}

bool buttonIsPressed(void)
{
	return bsp_io_bin_get(); // Read the button state (hardware-specific)
}
