/**
 * @file main.cpp
 * @author Alecsander Lima (aleclima14@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-11 (yyyy-mm-dd)
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/* INCLUDES */
#include <Arduino.h>
#include "sleepcontrol.h"
#include "peripherals.h"

void setup() 
{
  fnvInitPins();
}

void loop() 
{
  fnvStatusLed(true);
  delay(1000);
  fnvGoToSleep(DEEP_SLEEP, 2);
}