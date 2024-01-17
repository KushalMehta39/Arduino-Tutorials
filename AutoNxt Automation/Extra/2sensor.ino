#include <SoftwareSerial.h>
#include <AltSoftSerial.h>

SoftwareSerial mySerial1(2, 3); // RX, TX for the first sensor
AltSoftSerial mySerial2;        // RX, TX for the second sensor


const int lowerLimit = 10; // Set your lower distance limit here

void setup()
{
    Serial.begin(57600);
    mySerial1.begin(9600);
    mySerial2.begin(9600);
}

void loop()
{
    readSensorData(mySerial1, "Sensor 1: ");
    readSensorData(mySerial2, "Sensor 2: ");
}

void readSensorData(Stream& serial, const char* sensorName)
{
    if (serial.available() >= 4)
    {
        byte data[4];
        serial.readBytes(data, 4);

        uint16_t distance = (data[1] << 8) + data[2];

        Serial.print(sensorName);
        if (distance > lowerLimit)
        {
            Serial.println(distance / 10.0);
        }
        else
        {
            Serial.println("Below lower limit.");
        }
    }
}
