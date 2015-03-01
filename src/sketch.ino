void setup()
{
    for (int i = 0; i < 8; i++) {
        pinMode(i, OUTPUT);
    }
}

void square() {
    for (int i = 0; i < 8; i++) {
        digitalWrite(i, HIGH);
    }
    delayMicroseconds(4545 / 2);
    for (int i = 0; i < 8; i++) {
        digitalWrite(i, LOW);
    }
    delayMicroseconds(4545 / 2);
}

void loop()
{
    square();
}
