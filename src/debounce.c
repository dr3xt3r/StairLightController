/*************************************************************************
 * @file         debounce.c
 * @author       Richard Vano
 * @brief        Button debounce module
 *
 *************************************************************************/

/*************************************************************************
 * Includes
 *************************************************************************/
#include "debounce.h"
#include "button.h"

#ifdef USE_EMBOS
#include "RTOS.h"
#endif

/*************************************************************************
 * Global variables
 *************************************************************************/
// Variables to track button state
static uint8_t ct0			 = 0xFF; // NOLINT
static uint8_t ct1			 = 0xFF; // NOLINT
static uint8_t key_state = 0;		 // NOLINT
static uint8_t key_press = 0;		 // NOLINT

#ifdef USE_EMBOS
static OS_TIMER g_timerDebounce;
#endif

/*************************************************************************
 * Function definitions
 *************************************************************************/
static void debounceTimerCallback(void)
{
	uint8_t i = 0;

	i = buttonIsPressed() ? 0xFF : 0x00; // Simulate reading the key (pressed or not) // NOLINT
	i ^= key_state;											 // Key changed?
	ct0 = ~(ct0 & i);										 // Reset or count ct0 // NOLINT
	ct1 = ct0 ^ (ct1 & i);							 // Reset or count ct1 // NOLINT
	i &= ct0 & ct1;											 // Count until rollover // NOLINT
	key_state ^= i;											 // Toggle debounced state
	key_press |= key_state & i;					 // Detect key press // NOLINT

#ifdef USE_EMBOS
	OS_RetriggerTimer(&g_timerDebounce);
#endif
}

void debounceInit(void)
{
	// Initialize the RTOS timer with a 10 ms period for debouncing
#ifdef USE_EMBOS
	OS_CreateTImer(&g_timerDebounce, debounceTimerCallback, 10);
	OS_StartTimer(&g_timerDebounce);
#endif
}

uint8_t getDebouncedPress(void)
{
	uint8_t result = 0;

#ifdef USE_EMBOS
	OS_TASK_EnterRegion();
#endif
	result		= key_press;
	key_press = 0; // Clear after reading
#ifdef USE_EMBOS
	OS_TASK_LeaveRegion();
#endif

	return result;
}
