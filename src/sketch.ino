long previousMicros = 0;
long currentMicros;
unsigned long interval = freq_to_micros(440.0);
unsigned long new_interval = freq_to_micros(440.0);
int out = LOW;

int change = 0;

void setup()
{
    for (int i = 0; i < 8; i++) {
        pinMode(i, OUTPUT);
    }

    Serial.begin(115200);
    Serial.setTimeout(10);
}

unsigned long freq_to_micros(float freq) {
    return (1000.0 / freq) * 1000.0;
}

void reset_interval() {
    interval = freq_to_micros(Serial.parseFloat());
}

void square() {

    if (Serial.available()) {
        reset_interval();
    }

    if (interval != 0.0) {
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

}

void loop()
{
    square();
}
