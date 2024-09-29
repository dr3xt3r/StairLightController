/*************************************************************************
 * @file         bsp_io_bin.c
 * @author       Richard Vano
 * @brief        bsp_io_bin dummy implementation
 *
 * Dummy implementation of the bsp_io_bin module
 *
 *************************************************************************/

/*************************************************************************
 * Includes
 *************************************************************************/
#include "bsp_io_bin.h"

/*************************************************************************
 * Function definitions
 *************************************************************************/
bool_t bsp_io_bin_init(void)
{
	// Dummy implementation, always return TRUE
	return true;
}

bool_t bsp_io_bin_get(void)
{
	// Dummy implementation, always return false
	return false;
}

bool_t bsp_io_bin_interrupt_en(void (*int_callback)(void))
{
	// Dummy interrupt enable, always return TRUE
	(void) (int_callback);
	return true;
}
