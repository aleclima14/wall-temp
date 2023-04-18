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

int count = 0;

void setup() 
{
   fnvStartPeripherals();
}

void onConnectionEstablished()
{}

void loop() 
{
   fnvEnableDHT22(true);
   fnvEnableDallas(true);

   fnvPublishJSONVariables();
   fnvSendingMQTTServer();
   fnvClientLoop();
   count++;
   
   delay(100);
   
   if(count > 5)
   fnvGoToSleep(DEEP_SLEEP, MINUTES_TO_SLEEP);
}

