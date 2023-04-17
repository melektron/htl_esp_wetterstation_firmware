/*
ELEKTRON © 2022
Written by Matteo Reiter
www.elektron.work
21.11.22, 13:12

configuration definitions

*/

#pragma once

#include <Arduino.h>


// LED pins
#define CONFIG_IO_LED_R D6 
#define CONFIG_IO_LED_Y D7
#define CONFIG_IO_LED_G D8

// DHT pin
#define CONFIG_IO_DHT D4

// Display Type
#define CONFIG_DISPLAY_TYPE U8G2_SH1106_128X64_NONAME_F_HW_I2C

// RemoteXY config
#define REMOTEXY_WIFI_SSID "WheatherXY"
#define REMOTEXY_WIFI_PASSWORD "passwort"
#define REMOTEXY_SERVER_PORT 6377

// Timing
#define UPDATE_PERIOD 1000