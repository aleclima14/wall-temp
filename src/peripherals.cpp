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

/**
 * @brief Init output and input pins
 * 
 */
void fnvInitPins(void)
{
   pinMode(PIN_LED_STATUS, OUTPUT);
   pinMode(PIN_ENABLE_DHT, OUTPUT);
   pinMode(PIN_ENABLE_DALLAS, OUTPUT);
   pinMode(PIN_BUTTON, INPUT_PULLUP);
}

/**
 * @brief Set pin status
 * 
 * @param status 
 */
void fnvStatusLed(boolean status)
{
   digitalWrite(PIN_LED_STATUS, !status);
}

/**
 * @brief Enable DHT22 sensor
 * 
 * @param status 
 */
void fnvEnableDHT22(boolean status)
{
   digitalWrite(PIN_ENABLE_DHT, status);
}

/**
 * @brief Enable Dallas sensor
 * 
 * @param status 
 */
void fnvEnableDallas(boolean status)
{
   digitalWrite(PIN_ENABLE_DALLAS, status);
}