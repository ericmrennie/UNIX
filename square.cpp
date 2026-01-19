#include "everything.h"

int main(int argc, char* argv[]) {
    float phase = 0;
    float frequency = 440; // square wave frequency in Hz
    float increment = 2 * pi * frequency / SAMPLE_RATE;

    for (int i = 0; i < SAMPLE_RATE; i++) { // 1 second of audio
        double sample;

        // Square wave: high for half the cycle, low for half
        if (phase < pi) {
            sample = 1.0;
        } else {
            sample = -1.0;
        }

        mono(sample);

        // advance phase
        phase += increment;
        if (phase >= 2 * pi)
            phase -= 2 * pi;
    }
}
