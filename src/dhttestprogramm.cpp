
#include <Arduino.h>
#include <U8g2lib.h>
#include <DHTesp.h>



// Display instanz
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0); // // SCK am Display = D1   SDA am Display = D2

// Sensor instanz
DHTesp sensor;
#define DHT22Pin D5

void setup()
{
    // Display initialisieren
    u8g2.begin();
    u8g2.enableUTF8Print();
    
    // DHT Sensor initialisieren
    sensor.setup(DHT22Pin, DHTesp::DHT22); // Sensor DHT22 initialisieren

    // Serielle Schnittstelle initialisieren
    // Achtung: Baudrate = 115200
    Serial.begin(115200);
}

void loop()
{

    // Temperatur in °C vom Sensor lesen 
    float temp_c = sensor.getTemperature();

    // Werte auf dem seriellen Montitor ausgeben
    Serial.print("   Temperatur: ");
    Serial.print(temp_c, 1);
    Serial.println(" C°");

    // Picture loop
    u8g2.firstPage();
    do
    {
        // Grafische elemente zeichnen
        u8g2.setFont(u8g2_font_t0_11_tf); // Schrifthöhe 8 Pixel
        u8g2.drawStr(0, 8, "TESTPROG-TEMP.");
        u8g2.setFont(u8g2_font_8x13B_tf); // Schrifthöhe 10 Pixel
        u8g2.drawStr(45, 22, "C");
        u8g2.setCursor(5, 22);
        u8g2.print(temp_c, 1);

    } while (u8g2.nextPage());

    // Aktualisiere jede sekunde
    delay(3000);
}
