const int outPin =  13;
long previousMicros = 0;
unsigned long interval = 4545/2;
int out = LOW;
unsigned long currentMicros;

void setup() {
    pinMode(outPin, OUTPUT);
}


void loop()
{
    currentMicros = micros();

    if (currentMicros - previousMicros > interval) {
        previousMicros = currentMicros;

        if (out == HIGH) {
            out = LOW;
        } else if (out == LOW) {
            out = HIGH;
        }

        digitalWrite(outPin, out);
    }
}
