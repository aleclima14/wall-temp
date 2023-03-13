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
#include <DHT.h>


/**
 * @brief DHT Constructor
 * 
 * @return DHT 
 */
DHT dht(READ_DHT22, DHT_TYPE);   

/**
 * @brief Init output and input pins
 * 
 */
void fnvInitPins(void)
{
   pinMode(ENABLE_LED, OUTPUT);
   pinMode(ENABLE_DHT22, OUTPUT);
   pinMode(ENABLE_DS18B20, OUTPUT);

   pinMode(READ_DS18B20, INPUT);
   pinMode(READ_BUTTON, INPUT_PULLUP);
}

/**
 * @brief Set pin status
 * 
 * @param status 
 */
void fnvStatusLed(boolean status)
{
   digitalWrite(ENABLE_LED, !status);
}

void fnvStartDHT22(void)
{
   dht.begin();
}

/**
 * @brief Enable DHT22 sensor
 * 
 * @param status 
 */
void fnvEnableDHT22(boolean status)
{
   digitalWrite(ENABLE_DHT22, status);
}

/**
 * @brief Enable Dallas sensor
 * 
 * @param status 
 */
void fnvEnableDallas(boolean status)
{
   digitalWrite(ENABLE_DS18B20, status);
}

/**
 * @brief Read Ambient Temperature
 * 
 * @return Temperature 
 */
float fnfReadTemperatureDHT22(void)
{
   return dht.readTemperature();
}

/**
 * @brief Read Ambient Humidity
 * 
 * @return Temperature 
 */
float fnfReadHumidityDHT22(void)
{
   return dht.readHumidity();
}
