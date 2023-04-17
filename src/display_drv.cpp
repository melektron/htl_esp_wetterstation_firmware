/*
ELEKTRON © 2022
Written by Matteo Reiter
www.elektron.work
21.11.22, 13:10

driver to show relevant information on the OLED
display of the weather station.
*/

#include "display_drv.hpp"

display_drv::display_drv()
:   oled_drv(U8G2_R0)
{
}

void display_drv::init()
{
    oled_drv.begin();
    oled_drv.enableUTF8Print();
    update();
}

void display_drv::update()
{
    oled_drv.firstPage();
    do
    {
        // Grafische elemente zeichnen
        oled_drv.setFont(u8g2_font_t0_11_tf); // Schrifthöhe 8 Pixel
        oled_drv.drawStr(0, 8, "WETTERSTATION");
        oled_drv.setFont(u8g2_font_8x13B_tf); // Schrifthöhe 10 Pixel
        oled_drv.drawStr(45, 22, "C");
        oled_drv.setCursor(5, 22);
        oled_drv.print(temperature, 1);
        oled_drv.drawStr(45, 36, "%");
        oled_drv.setCursor(5, 36);
        oled_drv.print(humidity, 1);
    } while (oled_drv.nextPage());
}

void display_drv::set_temperature(double _temp)
{
    temperature = _temp;
    update();
}

void display_drv::set_humidity(double _humi)
{
    humidity = _humi;
    update();
}