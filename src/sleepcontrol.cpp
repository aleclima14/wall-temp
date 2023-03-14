/**
 * @file sleepcontrol.cpp
 * @author Alecsander Lima (aleclima14@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-11 (yyyy-mm-dd)
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/* INCLUDES */
#include "sleepcontrol.h"

void fnvGoToSleep(EnSleepMode sleepType, uint16_t sleepTime)
{
   esp_sleep_enable_timer_wakeup((uint64_t)sleepTime * SLEEP_TIMER);
   esp_sleep_enable_ext0_wakeup(PIN_BUTTON, LOW);

   switch (sleepType)
   {
      case LIGHT_SLEEP:
      {
         esp_light_sleep_start();
      }
      break;

      case DEEP_SLEEP:
      {
         esp_deep_sleep_start();
      }
      break;
      
      default:
      break;
   }
}