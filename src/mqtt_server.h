/**
 * @file mqtt_server.h
 * @author Alecsander Lima (aleclima14@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-11 (yyyy-mm-dd)
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __mqtt_server_h__
#define __mqtt_server_h__

/* INCLUDES */
#include <ArduinoJson.h>
#include "EspMQTTClient.h"
#include "peripherals_app.h"

void fnvSendingMQTTServer (void);
void fnvPublishJSONVariables (void);
void onConnectionEstablished();
void fnvClientLoop(void);



#endif // end __mqtt_server_h__
