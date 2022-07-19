// C++ code
//
void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH); // Turn the built-in LED on
  delay(500); // Wait for 500 millisecond(s)
  digitalWrite(13, LOW); // Turn the built-in LED off
  delay(500); // Wait for 500 millisecond(s)
}
