/*
ELEKTRON © 2022
Written by Matteo Reiter
www.elektron.work
21.11.22, 13:16

driver for controlling LEDs depending on temperature 
(and possibly humidity) values
*/

#include <Arduino.h>
#include "leds.hpp"
#include "config.hpp"

static bool rs = false;
static bool ys = false;
static bool gs = false;

void leds::init()
{
    pinMode(CONFIG_IO_LED_R, OUTPUT);
    pinMode(CONFIG_IO_LED_Y, OUTPUT);
    pinMode(CONFIG_IO_LED_G, OUTPUT);
}

void leds::set_temperature(double _temp)
{
    if (_temp < 21.5)
    {
        digitalWrite(CONFIG_IO_LED_R, rs = 0);
        digitalWrite(CONFIG_IO_LED_Y, ys = 0);
        digitalWrite(CONFIG_IO_LED_G, gs = 1);
    }
    else if (_temp < 23.5)
    {
        digitalWrite(CONFIG_IO_LED_R, rs = 0);
        digitalWrite(CONFIG_IO_LED_Y, ys = 1);
        digitalWrite(CONFIG_IO_LED_G, gs = 1);
    }
    else
    {
        digitalWrite(CONFIG_IO_LED_R, rs = 1);
        digitalWrite(CONFIG_IO_LED_Y, ys = 1);
        digitalWrite(CONFIG_IO_LED_G, gs = 1);
    }
}

uint8_t leds::get_packed_state()
{
    return (gs << 2) | (ys << 1) | rs;
}