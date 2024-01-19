#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

const int lowerLimit = 30;        // Set your lower distance limit here
const int goStraightLimit = 15;   // Set the distance limit for "GO Straight" condition

void setup()
{
    Serial.begin(57600);
    mySerial.begin(9600);
}

void loop()
{
    if (mySerial.available() >= 4)
    {
        byte data[4];
        mySerial.readBytes(data, 4);

        uint16_t distance = (data[1] << 8) + data[2];

        if (distance > lowerLimit)
        {
            Serial.println(distance / 10.0);
            float dist1 = distance / 10.0;  // Declare dist1 variable

            if (dist1 > goStraightLimit)
            {
                Serial.println("GO Straight");
            }
            else
            {
                Serial.println("Go back");
            }
        }
        else
        {
            Serial.println("Below lower limit.");
        }
    }
}
