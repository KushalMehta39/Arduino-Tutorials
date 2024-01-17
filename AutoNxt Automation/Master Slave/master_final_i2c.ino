/*
  *@File  : Master Arduino// sending data to the slave, which is sending the final outpute
  *@Brief : Based off code given with the datasheet
*/


// 4 sensors with 1.5m range

#include <SoftwareSerial.h>
#include <Wire.h>
SoftwareSerial Serial4(11, 10);  // RX, TX
//SoftwareSerial Serial5(13,12); // RX, TX

unsigned char data4[4] = {};
unsigned char data3[4] = {};
unsigned char data2[4] = {};
unsigned char data1[4] = {};

//float distance;
float distCm4;
float distCm3;
float distCm2;
float distCm1;

int ll = 3;
int ul1 = 100; 
int ul2 = 150;
int flag = 0;
//float distAvg;

void setup() {
  Wire.begin();
  // Serial.begin(57600);
  Serial3.begin(9600);  //RX3, TX3
  Serial2.begin(9600);  //RX2, TX2
  Serial1.begin(9600);  //RX1, TX1
  Serial4.begin(9600);  //11/10


  pinMode(LED_BUILTIN, OUTPUT);
  //pinMode(22, OUTPUT); //LED on digital pin 22
}

void debFlag(float d1, float d2, float d3, float d4) {
  //int n = 0;
  if (d1 > ll && d1 < ul2) flag = 1;
  if (d2 > ll && d2 < ul2) flag = 2;
  if (d3 > ll && d3 < ul2) flag = 3;
  if (d4 > ll && d4 < ul2) flag = 4;
  //if(d5 == 1) flag = 5;
  //Serial.println(n);
}


void loop() {
  do {
    for (int i = 0; i < 4; i++) {
      data3[i] = Serial3.read();
    }
  } while (Serial3.read() == 0xff);

  do {
    for (int i = 0; i < 4; i++) {
      data2[i] = Serial2.read();
    }
  } while (Serial2.read() == 0xff);

  do {
    for (int i = 0; i < 4; i++) {
      data1[i] = Serial1.read();
    }
  } while (Serial1.read() == 0xff);

  Serial4.listen();
  do {
    for (int i = 0; i < 4; i++) {
      data4[i] = Serial4.read();
    }
  } while (Serial4.read() == 0xff);

  // Serial5.listen();

  Serial3.flush();
  Serial2.flush();
  Serial1.flush();
  Serial4.flush();
  //Serial5.flush();


  if (data3[0] == 0xff && data2[0] == 0xff && data1[0] == 0xff && data4[0] == 0xff) {

    int sum3, sum2, sum1, sum4;
    sum3 = (data3[0] + data3[1] + data3[2]) & 0x00FF;
    sum2 = (data2[0] + data2[1] + data2[2]) & 0x00FF;
    sum1 = (data1[0] + data1[1] + data1[2]) & 0x00FF;
    sum4 = (data4[0] + data4[1] + data4[2]) & 0x00FF;

    if (sum3 == data3[3] && sum2 == data2[3] && sum1 == data1[3] && sum4 == data4[3])  // && sum5==data5[3])
    {
      distCm3 = ((data3[1] << 8) + data3[2]) / 10;
      distCm2 = ((data2[1] << 8) + data2[2]) / 10;
      distCm1 = ((data1[1] << 8) + data1[2]) / 10;
      distCm4 = ((data4[1] << 8) + data4[2]) / 10;


      if ((distCm1 > ll && distCm1 < ul2) || (distCm2 > ll && distCm2 < ul2) || (distCm3 > ll && distCm3 < ul2) || (distCm4 > ll && distCm4 < ul2)) {
        //flag = 1;
        debFlag(distCm1, distCm2, distCm3, distCm4);
        /*Debugging statements*/
        //  Serial.print("distance3=");
        //  Serial.print(distCm3);
        //  Serial.println("cm");
        //  Serial.println("STOP");
        //  Serial.println(flag);
        //  Serial.print("distance3=");
        //  Serial.print(distCm3);
        //  Serial.println("cm");
        //  Serial.print("distance2=");
        //  Serial.print(distCm2);
        //  Serial.println("cm");
        //  Serial.print("distance1=");
        //  Serial.print(distCm1);
        //  Serial.println("cm");
        //  Serial.print("distance4=");
        //  Serial.print(distCm4);
        //  Serial.println("cm");
        //  digitalWrite(LED_BUILTIN, HIGH);
        //  delay(500);
        //  digitalWrite(LED_BUILTIN, LOW);
      } else {
        flag = 0;
        //  Serial.println("0");
        //  Serial.print("distance3=");
        //  Serial.print(distCm3);
        //  Serial.println("cm");
        //  Serial.println(flag);
        //  Serial.print("distance3=");
        //  Serial.print(distCm3);
        //  Serial.println("cm");
        //  Serial.print("distance2=");
        //  Serial.print(distCm2);
        //  Serial.println("cm");
        //  Serial.print("distance1=");
        //  Serial.print(distCm1);
        //  Serial.println("cm");
        //  Serial.print("distance4=");
        //  Serial.print(distCm4);
        //  Serial.println("cm");
      }
    } else {
      //Serial.println("ERROR");
  }
  Wire.beginTransmission(9);
  Wire.write(flag);
  Wire.endTransmission();
  delay(100);
}
}
