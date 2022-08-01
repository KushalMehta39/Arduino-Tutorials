int red = 13;
int green = 12;
int blue = 11;
int fast = 200;
int slow = 400;
int realSlow = 600;
int longD = 2000;
  void setup()
{
  	pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
}

void loop()
{
  digitalWrite(red, HIGH);
  delay(fast);
  digitalWrite(red, LOW);
  delay(fast);
  digitalWrite(red, HIGH);
  delay(fast);
  digitalWrite(red, LOW);
  delay(fast);
  digitalWrite(red, HIGH);
  delay(fast);
  digitalWrite(red, LOW);
  delay(fast);
  digitalWrite(red, HIGH);
  delay(fast);
  digitalWrite(red, LOW);
  delay(fast);
  digitalWrite(red, HIGH);
  delay(fast);
  digitalWrite(red, LOW);
  delay(fast);
  
  
  digitalWrite(green, HIGH);
  delay(slow);
  digitalWrite(green, LOW);
  delay(slow);
  digitalWrite(green, HIGH);
  delay(slow);
  digitalWrite(green, LOW);
  delay(slow);
  digitalWrite(green, HIGH);
  delay(slow);
  digitalWrite(green, LOW);
  delay(slow);
  
  digitalWrite(blue, HIGH);
  delay(realSlow);
  digitalWrite(blue, LOW);
  delay(realSlow);
  digitalWrite(blue, HIGH);
  delay(realSlow);
  digitalWrite(blue, LOW);
  delay(longD);
}
