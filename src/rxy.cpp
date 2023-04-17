/*
   -- New project --

   This source code of graphical user interface
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.8 or later version
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/
     - for ANDROID 4.11.1 or later version;
     - for iOS 1.9.1 or later version;

   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

#include <stdint.h>

// RemoteXY select connection mode and include library
#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h>

#include <RemoteXY.h>
#include "rxy.hpp"
#include "config.hpp"

// RemoteXY configurate
#pragma pack(push, 1)
static uint8_t RemoteXY_CONF[] = // 101 bytes
    {255, 0, 0, 11, 0, 94, 0, 16, 233, 1, 70, 16, 9, 22, 9, 9, 26, 37, 0, 70,
     16, 9, 33, 9, 9, 26, 79, 0, 70, 16, 9, 44, 9, 9, 26, 120, 0, 71, 56, 32,
     20, 15, 15, 0, 2, 24, 135, 0, 0, 160, 193, 0, 0, 72, 66, 0, 0, 160, 65, 0,
     0, 32, 65, 0, 0, 0, 64, 24, 0, 71, 56, 32, 38, 15, 15, 0, 2, 24, 135, 0,
     0, 0, 0, 0, 0, 200, 66, 0, 0, 160, 65, 0, 0, 32, 65, 0, 0, 0, 64, 24,
     0};

// this structure defines all the variables and events of your control interface
struct
{

    // output variables
    uint8_t Hot;       // led state 0 .. 1
    uint8_t Medium;    // led state 0 .. 1
    uint8_t Cold;      // led state 0 .. 1
    float Temperature; // from -20 to 50
    float Humidity;    // from 0 to 100

    // other variable
    uint8_t connect_flag; // =1 if wire connected, else =0

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

void rxy::init()
{
    remotexy = new CRemoteXY(
        RemoteXY_CONF_PROGMEM,
        &RemoteXY,
        REMOTEXY_ACCESS_PASSWORD,
        new CRemoteXYConnectionServer(
            new CRemoteXYComm_WiFiPoint(REMOTEXY_WIFI_SSID, REMOTEXY_WIFI_PASSWORD),
            REMOTEXY_SERVER_PORT
        )
    );
}


void rxy::update()
{
    remotexy->handler();
}

void rxy::set_temperature(double _temp)
{
    RemoteXY.Temperature = _temp;
}

void rxy::set_humidity(double _humid)
{
    RemoteXY.Humidity = _humid;
}

void rxy::set_packed_led(uint8_t _leds)
{
    RemoteXY.Hot = 1 & _leds;
    RemoteXY.Medium = 1 & (_leds >> 1);
    RemoteXY.Cold = 1 & (_leds >> 2);
}