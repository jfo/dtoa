long previousMicros = 0;
long currentMicros;
unsigned long interval = freq_to_micros(440.0);
int out = LOW;

void setup()
{
    for (int i = 0; i < 8; i++) {
        pinMode(i, OUTPUT);
    }
}

unsigned long freq_to_micros(float freq) {
    return (1000.0 / freq) * 1000.0;
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
