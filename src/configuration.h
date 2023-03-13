/**
 * @file configuration.h
 * @author Alecsander Lima (aleclima14@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-11 (yyyy-mm-dd)
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __configuration_h__
#define __configuration_h__

/* INCLUDES */
#include <Arduino.h>

#define MINUTES_TO_SLEEP   2

/* SENSORS PINS */
#define READ_DHT22         25
#define ENABLE_DHT22       26

#define READ_DS18B20       33
#define ENABLE_DS18B20     32

/* PERIPHERALS PINS */
#define READ_BUTTON        12
#define ENABLE_LED         22

/* DHT CONFIG */
#define DHT_TYPE DHT22

#endif // end __configuration_h__