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

/* DEFINES */

/* ENUMS */

/* FUNCTIONS */
void fnvInitPins(void);
void fnvStatusLed(boolean status);
void fnvStartDHT22(void);
void fnvEnableDHT22(boolean status);
void fnvEnableDallas(boolean status);
boolean fnbReadButton(void);
float fnfReadTemperatureDHT22(void);
float fnfReadHumidityDHT22(void);
float fnfReadTemperatureDallas(void);


#endif // end __peripherals_h__