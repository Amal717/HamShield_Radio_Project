#include "demo.h"
#include "Arduino.h"
#include "HamShield.h"

#define MIC_PIN     3
#define RESET_PIN   A3
#define SWITCH_PIN  2


void ham_init()
{

    ham_soft_reset();
    ham_set_reference_clock(12.8);
    ham_set_rf_band(RF_BAND_134_174_MHZ);
    ham_set_frequency(145.5);
    ham_set_transmitter(TX_OFF);
    ham_set_receiver(RX_ON);

    Serial.print("RX status: ");
    Serial.println(ham_get_rx_on_status());

    Serial.print("TX status: ");
    Serial.println(ham_get_tx_on_status());

    Serial.print("RSSI raw: ");
    Serial.println(ham_get_rssi());

    Serial.print("VSSI raw: ");
    Serial.println(ham_get_vssi());
}

void ham_setup()
{
    /* if not using PWM out, it should be held low
       to avoid tx noise  */
    pinMode(MIC_PIN, OUTPUT);
    digitalWrite(MIC_PIN, LOW);

    // prep the switch
    pinMode(SWITCH_PIN, INPUT_PULLUP);

    // set up the reset control pin
    pinMode(RESET_PIN, OUTPUT);
    digitalWrite(RESET_PIN, LOW);

    Serial.begin(9600);

    while (digitalRead(SWITCH_PIN) && !Serial.available());
    Serial.read(); // flush

    digitalWrite(RESET_PIN, HIGH);
    delay(5);

    ham_set_sq(SQ_OFF);
    ham_set_frequency(432.100);
    ham_set_receiver(RX_ON);

}
