const int lowerLimit = 30; // Set your lower distance limit here

void setup()
{
    Serial.begin(57600);
    Serial1.begin(9600); // Use Serial1 for sensor, connect the sensor to TX1 (pin 18) and RX1 (pin 19) on Arduino Uno
}

void loop()
{
    if (Serial1.available() >= 4)
    {
        byte data[4];
        Serial1.readBytes(data, 4);

        uint16_t distance = (data[1] << 8) + data[2];

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
