/**
 * @file peripherals.cpp
 * @author Alecsander Lima (aleclima14@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-11 (yyyy-mm-dd)
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/* INCLUDES */
#include "peripherals.h"

void fnvInitPins(void)
{
   pinMode(LED_BUILTIN, OUTPUT);
}

void fnvStatusLed(boolean status)
{
   digitalWrite(LED_BUILTIN, !status);
}