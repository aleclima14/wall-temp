/**
 * @file main.cpp
 * @author Alecsander Lima (aleclima14@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-11 (yyyy-mm-dd)
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/* INCLUDES */
#include <Arduino.h>
#include "sleepcontrol.h"
#include "peripherals_app.h"
#include "mqtt_server.h"

unsigned long timerToSleep = 0;

void setup() 
{
   fnvStartPeripherals();
   fnvEnableDHT22(true);
   fnvEnableDallas(true);
   fnvStatusLed(false);
}

void onConnectionEstablished()
{
   fnvPublishJSONVariables();
   fnvSendingMQTTServer();
   fnvBlinkLedStatus(2, 200);
}

void loop() 
{
   fnvClientLoop();

   if((millis() - timerToSleep) > 10000)
   {
      timerToSleep = millis();
      fnvGoToSleep(DEEP_SLEEP, MINUTES_TO_SLEEP);
   }
}

