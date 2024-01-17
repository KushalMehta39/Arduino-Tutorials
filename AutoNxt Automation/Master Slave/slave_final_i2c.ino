/*
  *@File  : slave arduino; pin 22 has overall output
  *@Brief : Based off code given with datasheet
*/

// 2 semsors with 1m range, 1 sensor with 1.5m + 4 sensor (1.5m) input from the other board
// U1: 1.5m, U2,3: 1m
#include <SoftwareSerial.h>
#include <Wire.h>

//#define mosSwitch 24


//unsigned char data4[4] = {};
unsigned char data3[4] = {};
unsigned char data2[4] = {};
unsigned char data1[4] = {};

//float distance
float distCm3;
float distCm2;
float distCm1;

int ll = 3;
int ul1 = 100;
int ul2 = 150;
int f;

//float distAvg;


void setup() {
  //Serial.begin(57600);  //used for Serial comp
  //Serial4.begin(9600);  //11/10
  Serial3.begin(9600);  //RX3, TX3
  Serial2.begin(9600);  //RX2, TX2
  Serial1.begin(9600);  //RX1, TX1
  //Wire.begin(9);

//  pinMode(mosSwitch, OUTPUT);
  //pinMode(LED_BUILTIN, OUTPUT);
  //pinMode(24, OUTPUT); //test
  //pinMode(26, INPUT);
  pinMode(22, OUTPUT);  //LED on digital pin 22
  Wire.onReceive(receiveEvent);
}

void receiveEvent(int bytes) {
  f = Wire.read();  // read one character from the I2C
 }

// void debug(float d1, float d2, float d3, float d4, float d5) {
//   int n = 0;
//   if (d1 > ll && d1 < ul) n = 1;
//   if (d2 > ll && d2 < ul) n = 2;
//   if (d3 > ll && d3 < ul) n = 3;
//   if (d4 > ll && d4 < ul) n = 4;
//   if (d5 >= 1) {
//     n = d5;
//     Serial.print("f=");
//   }
//   Serial.println(n);
// }

void loop() {
  do {
    //Serial.print("reading 3");
    for (int i = 0; i < 4; i++) {
      data3[i] = Serial3.read();
      //Serial.print(i);
      //Serial.print(data[i]);
    }
  } while (Serial3.read() == 0xff);


  do {
    //Serial.print("reading 2");
    for (int i = 0; i < 4; i++) {
      data2[i] = Serial2.read();
      //Serial.print(i);
      //Serial.print(data[i]);
    }
  } while (Serial2.read() == 0xff);


  do {
    //Serial.print("reading 1");
    for (int i = 0; i < 4; i++) {
      data1[i] = Serial1.read();
      //Serial.print(i);
      //Serial.print(data[i]);
    }
  } while (Serial1.read() == 0xff);


  // Serial4.listen();
  // do {
  //   for (int i = 0; i < 4; i++) {
  //     data4[i] = Serial4.read();
  //   }
  // } while (Serial4.read() == 0xff);

  // Serial4.flush();
  Serial3.flush();
  Serial2.flush();
  Serial1.flush();
  //Serial.println("Entering If here");
  //if(data3[0]==0xff && data2[0] == 0xff && data1[0] == 0xff && data4[0] == 0xff) // && data5[0] == 0xff)
  if (data1[0] == 0xff && data2[0] == 0xff && data3[0] == 0xff) {  //&& data4[0] == 0xff) {
    // Serial.println("Entered If here");
    // delay(500);
    int sum1, sum2, sum3;  // sum4;  // sum3, sum2,
    // sum4 = (data4[0] + data4[1] + data4[2]) & 0x00FF;
    sum3 = (data3[0] + data3[1] + data3[2]) & 0x00FF;
    sum2 = (data2[0] + data2[1] + data2[2]) & 0x00FF;
    sum1 = (data1[0] + data1[1] + data1[2]) & 0x00FF;

    if (sum1 == data1[3] && sum2 == data2[3] && sum3 == data3[3])  // && sum4 == data4[3])  // sum3==data3[3] && sum2==data2[3] &&
    {
      // distCm4 = (((data4[1] << 8) + data4[2]) / 10);
      distCm3 = (((data3[1] << 8) + data3[2]) / 10);
      distCm2 = (((data2[1] << 8) + data2[2]) / 10);
      distCm1 = (((data1[1] << 8) + data1[2]) / 10);



      //distAvg = (distCm3 + distCm2 + distCm1)/3;
      //if(distCm3 < 30  || distCm2 < 30 || distCm1 < 30 || distCm4 < 30)
      //delay(1000); //for fluctuations
      if ((distCm1 > ll && distCm1 < ul2) || (distCm2 > ll && distCm2 < ul1) || (distCm3 > ll && distCm3 < ul1) || f > 0)  // && transVal == 1
      {
        digitalWrite(22, HIGH);
        //digitalWrite(mosSwitch, HIGH);
        // debug(distCm1, distCm2, distCm3, distCm4, f);
        // Serial.print("1:");
        // Serial.println(distCm1);
        // Serial.print("2:");
        // Serial.println(distCm2);
        // Serial.print("3:");
        // Serial.println(distCm3);
        // Serial.print("4:");
        // Serial.println(distCm4);
        // Serial.print("f:");
        // Serial.println(f);

      } else {
        digitalWrite(22, LOW);
        //Serial.println("NO DATA");
        // Serial.print("1:");
        // Serial.println(distCm1);
        // Serial.print("2:");
        // Serial.println(distCm2);
        // Serial.print("3:");
        // Serial.println(distCm3);
        // Serial.print("4:");
        // Serial.println(distCm4);
        // Serial.print("f:");
        // Serial.println(f);


        //   digitalWrite(LED_BUILTIN, HIGH);
        //  // digitalWrite(22, HIGH);
        //   delay(10);
        //   digitalWrite(LED_BUILTIN, LOW);
        // digitalWrite(22, LOW);
      }
    } else {
      //Serial.println("ERRRRR");
      //digitalWrite(22, LOW);
      //   digitalWrite(LED_BUILTIN, HIGH);
      //  // digitalWrite(22, HIGH);
      //   delay(10);
      //   digitalWrite(LED_BUILTIN, LOW);
      // digitalWrite(22, HIGH);
      // delay(100);
      // //digitalWrite(LED_BUILTIN, LOW);
      // digitalWrite(22, LOW);
    }  //Serial.println("ERROR");
  }
  delay(100);
}
