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

#define SOFTWARE_RELEASE   0.01
#define YEAR_RELEASE       23
#define MOUTH_RELEASE      04
#define DAY_RELEASE        17

/* SENSORS PINS */
#define PIN_READ_DHT         GPIO_NUM_25
#define PIN_ENABLE_DHT       GPIO_NUM_26
#define PIN_READ_DALLAS      GPIO_NUM_33
#define PIN_ENABLE_DALLAS    GPIO_NUM_32

/* PERIPHERALS PINS */
#define PIN_BUTTON           GPIO_NUM_12
#define PIN_LED_STATUS       GPIO_NUM_22

#endif // end __configuration_h__