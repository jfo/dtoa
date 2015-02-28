void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  delayMicroseconds(4510 / 4);
  digitalWrite(13, LOW);
  delayMicroseconds(4510 / 4);
}
