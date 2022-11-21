/*
ELEKTRON © 2022
Written by Matteo Reiter
www.elektron.work
21.11.22, 13:16

driver for controlling LEDs depending on temperature 
(and possibly humidity) values
*/

#pragma once

namespace leds
{
    /**
     * @brief initialize led pins
     */
    void init();

    /**
     * @brief sets the leds to indicate a provided temperature
     * 
     * @param _temp 
     */
    void set_temperature(double _temp);
};