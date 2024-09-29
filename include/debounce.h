/*************************************************************************
 * @file         debounce.h
 * @author       Richard Vano
 * @brief        Button debounce module
 *
 *************************************************************************/

#ifndef DEBOUNCE_H
#define DEBOUNCE_H

/*************************************************************************
 * Includes
 *************************************************************************/
#include <stdint.h>

/*************************************************************************
 * Function prototypes
 *************************************************************************/
/**
 * @brief Initialize debounce logic
 */
void debounceInit(void);

/**
 * @brief Check for debounced button press
 * @return Non-zero if a debounced button press was detected, 0 otherwise
 */
uint8_t getDebouncedPress(void);

#endif /* DEBOUNCE_H */
