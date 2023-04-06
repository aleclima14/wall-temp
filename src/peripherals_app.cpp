/**
 * @file peripherals_app.cpp
 * @author Alecsander Lima (aleclima14@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-04 (yyyy-mm-dd)
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/* INCLUDES */
#include "peripherals_app.h"

/**
 * @brief Start all peripherals
 * 
 */
void fnvStartPeripherals (void)
{
   fnvInitPins();
   fnvStartDHT22();
   fnvStartDallas();
}