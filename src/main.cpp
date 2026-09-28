 /*******************************************************************************
  * @file main.cpp
  * @brief Testing the spi communication RDA1846
  * @author Amal Thomas
  *
  *
  * Wiring
  *
  * MODE  - HIGH (3  wire spi interface Select)
  * SDIO  - A4 (SDIO)
  * SCLK  - A5 (SCK)
  * nSEN  - A1 (CS)

 *******************************************************************************/

#include <Arduino.h>
#include "HamShield_comms.h"
#include "HamShield.h"
#include "demo.h"

//#define nSEN    5


void setup()
{
    Serial.begin(9600);

    pinMode(nSEN, OUTPUT);
    digitalWrite(nSEN, HIGH);

    pinMode(CLK, OUTPUT);
    digitalWrite(CLK, LOW);

    pinMode(DAT, INPUT);

}

void loop()
{
    uint16_t data = 0;

    HSreadWord(nSEN, 0x30, &data);

    Serial.print("RDA1846[0x30] = 0x");
    Serial.print(data, HEX);

    Serial.print("Binary = ");

    for (uint8_t bit = 15; bit >= 0; bit--) {
        Serial.print((data >> bit) & 1);

        if (bit == 12 || bit == 8 || bit == 4)
            Serial.print(" ");
    }
    Serial.println();

    // ham_init();
}
