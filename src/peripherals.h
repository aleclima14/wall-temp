/**
 * @file peripherals.h
 * @author Alecsander Lima (aleclima14@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-11 (yyyy-mm-dd)
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __peripherals_h__
#define __peripherals_h__

/* INCLUDES */
#include "configuration.h"

/* FUNCTIONS */
void fnvInitPins(void);
void fnvStatusLed(boolean status);
void fnvEnableDHT22(boolean status);
void fnvEnableDallas(boolean status);
void fnvSmoothLedOut(void);
void fnvBlinkLedStatus(int blinkTimes, int blinkInterval);
float fnvBatteryMeasure (void);

#endif // end __peripherals_h__