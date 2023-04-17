/*
ELEKTRON © 2022
Written by melektron
www.elektron.work
17.04.23, 14:24

functions for remotexy
*/

#pragma once


namespace rxy
{
    /**
     * @brief initializes remotexy
     * 
     */
    void init();

    /**
     * @brief calls the remotexy loop handler
     * 
     */
    void update();

    /**
     * @brief updates the displayed temperature
     * 
     * @param _temp 
     */
    void set_temperature(double _temp);

    /**
     * @brief updates the displayed humidity
     * 
     * @param _humid 
     */
    void set_humidity(double _humid);

    /**
     * @brief retrieves the led states from the packed byte and 
     * displays them
     * 
     * @param _leds  state of all LEDs
     * Bit 1 = LED R;
     * Bit 2 = LED Y;
     * Bit 3 = LED G;
     */
    void set_packed_led(uint8_t _leds);
};