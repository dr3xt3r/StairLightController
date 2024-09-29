/*************************************************************************
 * @file         button.h
 * @author       Richard Vano
 * @brief        Button abstraction module
 *
 * This module provides an abstraction for button handling
 *
 *************************************************************************/

#ifndef BUTTON_H
#define BUTTON_H

/*************************************************************************
 * Includes
 *************************************************************************/
#include "data_types.h"

/*************************************************************************
 * Function prototypes
 *************************************************************************/
/**
 * @brief   Initializes the button.
 *
 * @param   None
 * @return  None
 */
void buttonInit(void);

/**
 * @brief   Checks if the button is pressed.
 *
 * @param   None
 * @return  true if the button is pressed, false otherwise.
 */
bool_t buttonIsPressed(void);

#endif // BUTTON_H
