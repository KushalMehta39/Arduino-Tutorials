// C++ code
//Red -> 12
//Yellow -> 11
//Green -> 10
void setup()
{
  Serial.begin(9600);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop()
{
  digitalWrite(12,HIGH);
  delay(1000);
  digitalWrite(12,LOW);
  digitalWrite(11,HIGH);
  delay(2000);
  digitalWrite(11,LOW);
  digitalWrite(10,HIGH);
  delay(1000);
  digitalWrite(10,LOW);
}
