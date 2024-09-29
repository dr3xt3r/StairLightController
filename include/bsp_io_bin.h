/***************************************************************************//**
 *  @file bsp_io_bin.h
 *  @brief Board Support Package for Binary inputs
 *
 *  This module covers access for controller's binary input.
 *
 *  @par Copyright (c) 2013 ComAp a.s.  All rights reserved.
 ******************************************************************************/
#ifndef __BSP_IO_BIN_H__
#define __BSP_IO_BIN_H__


#include "data_types.h"


/***************************************************************************//**
 *  @addtogroup bsp_io_bin
 *  @{
 ******************************************************************************/

/***************************************************************************//**
 *  @brief Initialize binary inputs
 *
 *  Function initialize peripheries used for binary inputs.
 *
 *  @param  none
 *
 *  @retval TRUE => initialization was successful
 *  @retval FALSE => initialization failed
 ******************************************************************************/
bool_t bsp_io_bin_init(void); // NOLINT(readability-identifier-naming)


/***************************************************************************//**
 *  @brief Initialize and enable binary input interrupt.
 *
 *  Function initializes and enables interrupt of binary input. 
 *  Input is configured in mode: CHANGE to trigger the interrupt whenever
 *  the pin changes value.
 *
 *  @param  int_callback ... HW interrupt callback function
 *
 *  @retval TRUE => initialization was successful
 *  @retval FALSE => initialization failed
 ******************************************************************************/
bool_t bsp_io_bin_interrupt_en(void (*int_callback)(void));


/***************************************************************************//**
 *  @brief Get actual state of binary input
 *
 *  Function is reading actual state of binary input.
 *
 *  @return state of binary input
 ******************************************************************************/
bool_t bsp_io_bin_get(void); // NOLINT(readability-identifier-naming)


/***************************************************************************//**
 * Close the Doxygen group
 * @}
 ******************************************************************************/


#endif /* __BSP_IO_BIN_H__ */
