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
   pinMode(PIN_BATTERY_MEASURE, INPUT);
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

/**
 * @brief Blinks the led according to the number of times and defined interval
 * 
 * @param blinkTimes 
 * @param blinkInterval 
 */
void fnvBlinkLedStatus(int blinkTimes, int blinkInterval)
{
   int blinkCont = 0;
   static long timerToBlink = 0;
   for(int i = 0; i < blinkTimes; i++)
   {
      fnvStatusLed(true);
      delay(blinkInterval);
      fnvStatusLed(false);
      delay(blinkInterval);
   }
}

/**
 * @brief Turn off the led gradually
 * 
 */
void fnvSmoothLedOut(void)
{
   for(int i = 0; i < 256; i++)
   {
      analogWrite(PIN_LED_STATUS, i);
      delay(4);
   }
}

/**
 * @brief Symmetrical voltage divider to measure battery voltage 
 * 
 * @return Battery Voltage (float) 
 */
float fnvBatteryMeasure (void)
{
     /*Read pin and convert to voltage value*/
    uint16_t batteryValue = analogRead (PIN_BATTERY_MEASURE);
    float batteryVoltage = (batteryValue * VCC / 4095) + BATTERY_OFFSET_CORRECTION;

    /*returns value multiplied by 2*/
    return batteryVoltage * 2;
}