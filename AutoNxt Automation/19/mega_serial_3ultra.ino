#include <SoftwareSerial.h>
#include <AltSoftSerial.h>

const int lowerLimit = 30;        // Set your lower distance limit here
const int goStraightLimit = 15;   // Set the distance limit for "GO Straight" condition

void setup()
{
    Serial.begin(57600);
    Serial1.begin(9600); // Use Serial1 for sensor 1, connect the sensor to TX1 (pin 18) and RX1 (pin 19) on Arduino Mega
    Serial2.begin(9600);  // Use Serial2 for sensor 2, connect the sensor to TX1 (pin 16) and RX1 (pin 17) on Arduino Mega
    Serial3.begin(9600);  // Use Serial3 for sensor 3, connect the sensor to TX1 (pin 14) and RX1 (pin 15) on Arduino Mega
    pinMode(r_en, OUTPUT);
    pinMode(l_en, OUTPUT);
    pinMode(r_pwm, OUTPUT);
    pinMode(l_pwm, OUTPUT);
}

void loop()
{
    if (Serial1.available() >= 4 )
    {
        byte data[4];
        byte data2[4];
        byte data3[4];
        Serial1.readBytes(data, 4);
        uint16_t distance = (data[1] << 8) + data[2];
        Serial2.readBytes(data2, 4);
        uint16_t distance2 = (data2[1] << 8) + data2[2];
        Serial3.readBytes(data3, 4);
        uint16_t distance3 = (data3[1] << 8) + data3[2];
        Serial.println(distance);
        Serial.println(distance2);
        Serial.println(distance3);        
    }
}
