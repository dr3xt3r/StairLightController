/*************************************************************************
 * @file         bsp_io_bout.h
 * @author       Richard Vano
 * @brief        bsp_io_bout dummy implementation
 *
 * Dummy implementation of the bsp_io_bout module
 *
 *************************************************************************/

/*************************************************************************
 * Includes
 *************************************************************************/
#include "bsp_io_bout.h"

bool_t bsp_io_bout_init(void)
{
	// Dummy initialization, always return TRUE
	return true;
}

bool_t bsp_io_bout_set(const bool_t bout_state)
{
	// Dummy set function, always return TRUE
	(void) (bout_state);
	return true;
}
