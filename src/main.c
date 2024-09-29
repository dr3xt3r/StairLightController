/*************************************************************************
 * @file         led.c
 * @author       Richard Vano
 * @brief        LED abstraction module
 *
 * This module provides an abstraction for LED handling
 *
 *************************************************************************/

/*************************************************************************
 * Includes
 *************************************************************************/
#include <assert.h>
#include <stdio.h>

#include "button.h"
#include "config.h"
#include "debounce.h"
#include "led.h"
#include "main.h"

#ifdef USE_EMBOS
#include "RTOS.h"
#endif

/*************************************************************************
 * Global variables
 *************************************************************************/
/**
 * @brief Remaining time for the LED to be ON
 */
static int g_remainingTimeMs = 0;

#ifdef USE_EMBOS
/**
 * @brief embOS specific data
 */
static OS_STACKPTR int taskStack[128]; // Task stacks  // NOLINT
static OS_TASK				 mainTask;			 // Task control blocks // NOLINT
static OS_TIMER				 timerLED;			 // Timer control block // NOLINT
#endif																 // USE_EMBOS

/*************************************************************************
 * Main function
 *************************************************************************/
int main()
{
	// Initialize the RTOS and GPIOS
#ifdef USE_EMBOS
	OS_Init();
	OS_InitHW();
#endif
	buttonInit();
	debounceInit();
	ledInit();

#ifdef USE_EMBOS
	OS_TASK_CREATE(&mainTask, "Main Task", 100, mainTaskRoutine, taskStack);
	OS_CreateTimer(&timerLED, callbackTimerLED, 5000);
#endif

#ifdef USE_EMBOS
	OS_Start();
#endif

	return 0;
}

/*************************************************************************
 * Function definitions
 *************************************************************************/
void mainTaskRoutine(void)
{
	bool_t ledTimerRunning = false;
	while (1)
	{
		if (getDebouncedPress())
		{
#ifdef USE_EMBOS
			ledTimerRunning = OS_GetTimerStatus(&timerLED);
#endif

			// If the LED is already on (timer running), add 5 seconds to the remaining time
			if (ledTimerRunning)
			{
#ifdef USE_EMBOS
				g_remainingTimeMs = OS_GetTimerValue(&timerLED) + ADD_LED_TIME_MS;
#endif

				if (g_remainingTimeMs > MAX_LED_TIME_MS)
				{
					g_remainingTimeMs = MAX_LED_TIME_MS; // Cap the remaining time at 15 seconds
				}

#ifdef USE_EMBOS
				OS_StopTimer(&timerLED);
				OS_SetTimerPeriod(&timerLED, g_remainingTimeMs);
				OS_RetriggerTimer(&timerLED);
#endif
			}
			else
			{
				// LED is off, turn ON for 5 seconds
				g_remainingTimeMs = ADD_LED_TIME_MS;
				ledChangeState(true); // Turn on the LED
#ifdef USE_EMBOS
				OS_SetTimerPeriod(&timerLED, g_remainingTimeMs);
				OS_RetriggerTimer(&timerLED);
#endif
			}
		}
	}
}

void callbackTimerLED(void)
{
	// Timer expired, turn off the LED
	ledChangeState(false);
	g_remainingTimeMs = 0; // Reset the remaining time
}
