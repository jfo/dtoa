long previousMicros = 0;
long currentMicros;
unsigned long interval = freq_to_micros(440.0);
int out = LOW;

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

void beep() {
    int now = millis();
    while (millis() < now + 250) {
        square();
    }
}

void setup()
{
    for (int i = 0; i < 8; i++) {
        pinMode(i, OUTPUT);
    }

    Serial.begin(115200);
    Serial.setTimeout(10);
    beep();
}

float freq_to_micros(float freq) {
    return (1000.0 / freq) * 1000.0;
}

void reset_interval() {
    interval = freq_to_micros(Serial.parseFloat());
}

int sample_interval = freq_to_micros(112640);
int* binactivearray;

unsigned long t = 0;
float v = 0;
float diff;

void sine() {

    currentMicros = micros();

    diff = currentMicros - previousMicros;

    if (diff >= sample_interval) {
        // v = (((sin(440.0 * 3.1415 * t)) + 1 ) * 128) -1;
        // t += diff;
        previousMicros = currentMicros;

        // Serial.print(t);
        // Serial.print('\n');


        // y = (sin(freq * pi * x) + 1) * 128) - 1

    }
}

int i = 0;
int d = 1;
void thingy() {
    PORTD = i;
    delayMicroseconds(40 );
    i += d;
    if (i == 255) {
        d = -5;
    } else if (i == 0){
        d = 5;
    }
}

void loop()
{
    // square();
    // sine();
    thingy();
}
