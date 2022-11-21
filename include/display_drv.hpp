/*
ELEKTRON © 2022
Written by Matteo Reiter
www.elektron.work
21.11.22, 13:10

driver to show relevant information on the OLED
display of the weather station.
*/

#pragma once

#include <Arduino.h>
#include <U8g2lib.h>
#include "config.hpp"

class display_drv
{
private:
    CONFIG_DISPLAY_TYPE oled_drv;

    double temperature, humidity;

    /**
     * @brief redraws the screen elements from the stored data
     */
    void update();

public:
    /**
     * @brief initializes u8g2 oled driver
     */
    display_drv();

    /**
     * @brief starts display and draws static screen elements
     */
    void init();

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
};