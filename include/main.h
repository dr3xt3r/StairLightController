/*************************************************************************
 * @file         main.h
 * @author       Richard Vano
 * @brief        Application main header file
 *
 *************************************************************************/

#ifndef MAIN_H
#define MAIN_H

/*************************************************************************
 * Function prototypes
 *************************************************************************/
/**
 * @brief   Timer callback function
 *
 * @param   None
 * @return  None
 */
void callbackTimerLED(void);

/**
 * @brief   RTOS Main task function
 *
 * @param   None
 * @return  None
 */
void mainTaskRoutine(void);

#endif // MAIN_H
