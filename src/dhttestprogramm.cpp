/*
ELEKTRON © 2022
Written by Matteo Reiter
www.elektron.work
21.11.22, 14:38

Wetterstation main programm
*/
#include <Arduino.h>
#include <DHTesp.h>
#include "config.hpp"
#include "leds.hpp"
#include "display_drv.hpp"



// Display instanz
display_drv display;
// Sensor instanz
DHTesp sensor;

void setup()
{
    // Display initialisieren
    display.init();
    
    // DHT Sensor initialisieren
    sensor.setup(CONFIG_IO_DHT, DHTesp::DHT22); // Sensor DHT22 initialisieren

    // LED initialization
    leds::init();
}

void loop()
{

    // read temperature and humidity
    float temp_c = sensor.getTemperature();
    float humid = sensor.getHumidity();
    // update LEDs
    leds::set_temperature(temp_c);
    // update displays
    display.set_temperature(temp_c);
    display.set_humidity(humid);
    // upate again after a second
    delay(1000);
}
