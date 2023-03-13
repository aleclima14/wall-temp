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
#include "peripherals.h"

float temperature;
float humidity;

void setup() 
{
  fnvInitPins();
  fnvStartDHT22();
  Serial.begin(9600);
}

void loop() 
{
  Serial.println("Init board");
  fnvEnableDHT22(true);
  fnvStatusLed(true);
  for(int i = 0; i < 3; i++)
  {
    temperature = fnfReadTemperatureDHT22();
    humidity = fnfReadHumidityDHT22();
    delay(1000);
  }

  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" Humid: ");
  Serial.println(humidity);

  fnvEnableDHT22(false);
  delay(100);
  fnvGoToSleep(DEEP_SLEEP, MINUTES_TO_SLEEP);
}

