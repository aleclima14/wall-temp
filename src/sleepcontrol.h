/**
 * @file sleepcontrol.h
 * @author Alecsander Lima (aleclima14@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-11 (yyyy-mm-dd)
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __sleepcontrol_h__
#define __sleepcontrol_h__

/* INCLUDES */
#include "configuration.h"

/* DEFINES */
#define US_TO_SECONDS 1000000ULL
#define SLEEP_TIMER  US_TO_SECONDS * 60  //1 minute in us
#define MINUTES_TO_SLEEP   10

/* ENUMS */
typedef enum
{
   LIGHT_SLEEP,
   DEEP_SLEEP,
}EnSleepMode;

/* FUNCTIONS */
void fnvGoToSleep(EnSleepMode sleepType, uint16_t sleepTime);

#endif // end __sleepcontrol_h__