/**
 * @file mqtt_server.cpp
 * @author Alecsander Lima (aleclima14@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-11 (yyyy-mm-dd)
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/* INCLUDES */
#include "mqtt_server.h"

char temperatureSurface [100];
char temperatureAmbient [100];
char humidityAmbient [100];
char batteryLevel [100];

float temperature;
float humidity;
float dallasTemp;
float battery;

EspMQTTClient client
(
  "ssd id",                                   //Wifi SSID
  "password ",                                //Wifi password
  "mqtt.tago.io",                             //MQTT Broker Server
  "Default",                                  //Username
  "4da5554a-77a0-4cd6-aba2-b3dcdf061102",     //Device Token 
  "Wall Temperature Logger",                  //Client name 
  1883                                        //The MQTT port, default to 1883. this line can be omitted
);

void fnvClientLoop(void)
{
   client.loop();
}

void fnvSendingMQTTServer (void)
{
   /*Sending data to MQTT server*/
   client.publish  ("info/temperatureSurface", temperatureSurface);
   client.publish  ("info/temperatureAmbient", temperatureAmbient);
   client.publish  ("info/humidityAmbient", humidityAmbient);
   client.publish  ("info/batteryLevel", batteryLevel);
}

void fnvPublishJSONVariables (void)
{
   for(int i = 0; i < 3; i++)
   {
      temperature = fnfReadTemperatureDHT22();
      humidity = fnfReadHumidityDHT22();
      dallasTemp = fnfReadTemperatureDallas();  
      battery = fnvBatteryMeasure();
      delay(1000);
   }
   /*Temperature Surface Sensor Data*/
   StaticJsonDocument<300> temperatureSurface_;
   temperatureSurface_["variable"] = "tempSurface";
   temperatureSurface_["value"] = dallasTemp;
   serializeJson(temperatureSurface_, temperatureSurface);

   /*Ambient Temperature Sensor Data*/
   StaticJsonDocument<300> temperatureAmbient_;
   temperatureAmbient_["variable"] = "tempAmbient";
   temperatureAmbient_["value"] = temperature;
   serializeJson(temperatureAmbient_, temperatureAmbient);

   /*Ambient Humidity Sensor Data*/
   StaticJsonDocument<300> humidityAmbient_;
   humidityAmbient_["variable"] = "humidAmbient";
   humidityAmbient_["value"] = humidity;
   serializeJson(humidityAmbient_, humidityAmbient);

   /*Battery Level Data*/
   StaticJsonDocument<300> batteryLevel_;
   batteryLevel_["variable"] = "batteryLevel";
   batteryLevel_["value"] = battery;
   serializeJson(batteryLevel_, batteryLevel);
}