/**
 * @file temperature_app.h
 * @author Alecsander Lima (aleclima14@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-04 (yyyy-mm-dd)
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __temperature_app_h__
#define __temperature_app_h__

/* INCLUDES */
#include "configuration.h"
#include "temperature.h"
#include "peripherals.h"

/* STRUCTS */
typedef struct 
{
   float dallasTemperature;
   float dhtTemperature;
   float dhtHumidity;
}StReadData;

/* FUNCTIONS */
void fnvStartPeripherals (void);

#endif // end __temperature_app_h__