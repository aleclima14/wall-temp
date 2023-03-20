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
float dallasTemp;

void setup() 
{
  fnvInitPins();
  fnvStartDHT22();
  fnvStartDallas();
  fnvStatusLed(false);
  Serial.begin(9600);
}

void loop() 
{
  fnvEnableDHT22(true);
  fnvEnableDallas(true);
  fnvStatusLed(true);
  Serial.println("");
  Serial.println("Init board");

  for(int i = 0; i < 3; i++)
  {
    temperature = fnfReadTemperatureDHT22();
    humidity = fnfReadHumidityDHT22();
    dallasTemp = fnfReadTemperatureDallas();
    delay(1000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Temp: ");
  Serial.print(temperature, 1);
  Serial.print(" Humid: ");
  Serial.print(humidity, 0);
  Serial.print(" Dallas: ");
  Serial.println(dallasTemp, 1);

  fnvEnableDHT22(false);
  fnvEnableDallas(false);
  delay(100);
  Serial.println("Go to sleep zzZZ");
  fnvGoToSleep(DEEP_SLEEP, MINUTES_TO_SLEEP);
}

