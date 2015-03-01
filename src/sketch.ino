long previousMicros = 0;
long currentMicros;
unsigned long interval = 4545/2;
int out = LOW;

void setup()
{
    for (int i = 0; i < 8; i++) {
        pinMode(i, OUTPUT);
    }
}

void square() {

    currentMicros = micros();
    if (currentMicros - previousMicros > interval) {
        previousMicros = micros();

        if (out == HIGH) {
            out = LOW;
        } else if (out == LOW) {
            out = HIGH;
        }

        for (int i = 0; i < 8; i++) {
            digitalWrite(i, out);
        }
    }

}

void loop()
{
    square();
}
