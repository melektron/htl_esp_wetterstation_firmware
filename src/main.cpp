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
#include "rxy.hpp"

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

    // RemoteXY initialization
    rxy::init();
}

void loop()
{
    static uint64_t last_update;
    rxy::update();

    if (last_update + UPDATE_PERIOD < millis())
    {
        last_update = millis();

        // read temperature and humidity
        float temp_c = sensor.getTemperature();
        float humid = sensor.getHumidity();
        // update LEDs
        leds::set_temperature(temp_c);
        // update displays
        display.set_temperature(temp_c);
        display.set_humidity(humid);
        // update RemoteXY
        rxy::set_temperature(temp_c);
        rxy::set_humidity(humid);
        rxy::set_packed_led(leds::get_packed_state());
    }
}
