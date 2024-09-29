/***************************************************************************//**
 *  @file bsp_io_bout.h
 *  @brief Board Support for Binary output
 *
 *  This module covers access for controller's binary output.
 *
 *  @par Copyright (c) 2013 ComAp a.s.  All rights reserved.
 ******************************************************************************/
#ifndef __BSP_IO_BOUT_H__
#define __BSP_IO_BOUT_H__

#include "data_types.h"


/***************************************************************************//**
 *  @addtogroup bsp_io_bout
 *  @{
 ******************************************************************************/


/***************************************************************************//**
 *  @brief Initialize binary output
 *
 *  Function initialize peripheries used for binary output. Default
 *  configuration of outputs depends on board's modification but shoul be
 *  configured as LSS and outputs in third state. 
 *
 *  @param  none
 *
 *  @retval TRUE => initialization was successful
 *  @retval FALSE => initialization failed
 ******************************************************************************/
bool_t bsp_io_bout_init(void);


/***************************************************************************//**
 *  @brief Write state to the binary output
 *
 *  @param bout_state  ... set bout state
 *
 *  @retval TRUE => successful
 *  @retval FALSE => failed
 ******************************************************************************/
bool_t bsp_io_bout_set(const bool_t bout_state);


/****************************************************************************//**
 *  Close the Doxygen group
 *  @}
 ******************************************************************************/

#endif /* __BSP_IO_BOUT_H__ */
