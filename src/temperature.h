/**
 * @file temperature.h
 * @author Alecsander Lima (aleclima14@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-11 (yyyy-mm-dd)
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __temperature_h__
#define __temperature_h__

/* INCLUDES */
#include "configuration.h"

/* DEFINES */
#define DHT_TYPE DHT22

/* ENUMS */

/* FUNCTIONS */
void fnvStartDHT22(void);
void fnvStartDallas(void);
float fnfReadTemperatureDHT22(void);
float fnfReadHumidityDHT22(void);
float fnfReadTemperatureDallas(void);

#endif // end __temperature_h__