/*************************************************************************
 * @file         led.h
 * @author       Richard Vano
 * @brief        LED abstraction module
 *
 * This module provides an abstraction for LED handling
 *
 *************************************************************************/

#ifndef LED_H
#define LED_H

/*************************************************************************
 * Includes
 *************************************************************************/
#include "data_types.h"

/*************************************************************************
 * Function prototypes
 *************************************************************************/
/**
 * @brief   Initializes the LED.
 *
 * @param   None
 * @return  None
 */
void ledInit(void);

/**
 * @brief   Turns on the LED.
 *
 * @param   state   The state of the LED (true = on, false = off)
 * @return  None
 */
void ledChangeState(bool_t state);

#endif // LED_H
