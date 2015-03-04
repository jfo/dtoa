long previousMicros = 0;
long currentMicros;
unsigned long interval = freq_to_micros(440.0);
unsigned long new_interval = freq_to_micros(440.0);
int out = LOW;

int change = 0;

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

unsigned long freq_to_micros(float freq) {
    return (1000.0 / freq) * 1000.0;
}

// takes a pin and a step and returns 0 or 1 for whether that pin is active on that step
int activepin(int pin, int step) {
    int pins[8] = {1,2,4,8,16,32,64,128};
    int response = pins[pin] & step;
    if (response != 0) {
        return 1;
    } else {
        return 0;
    }
}

// takes a step and returns an array of pins with active or not on them
int * activepins(int step) {
    int output[8];
    for (int i = 0; i < 8; i++) {
        output[i] = activepin(i,step);
    }
    return output;
}

void reset_interval() {
    interval = freq_to_micros(Serial.parseFloat());
}


unsigned long sample_interval = freq_to_micros(44000.0);
unsigned long sine_interval = freq_to_micros(440.0);
unsigned long samplePreviousMicros = 0;
int step = 0;
int step_wise = 255;
int* binactivearray;

void sine() {

    if (step == 0) {
        step_wise = 100;
    } else if (step == 100) {
        step_wise = -100;
    }

    currentMicros = micros();
    if (currentMicros - samplePreviousMicros >= sample_interval) {
        samplePreviousMicros = currentMicros;
        if (currentMicros - previousMicros >= (sine_interval    ) ) {
            previousMicros = currentMicros;

            binactivearray = activepins(step);

            // for (int i = 0; i < 8; i += 1) {
            //     Serial.print(binactivearray[i]);
            // }
            // Serial.print('\n');

            for (int i = 0; i < 8; i++) {
                if (binactivearray[i]) {
                    digitalWrite(i, HIGH);
                } else {
                    digitalWrite(i, LOW);
                }
            }
            step += step_wise;
        }
    }
}


void loop()
{
    // square();
    sine();
}
