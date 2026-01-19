#include "everything.h"

int main(int argc, char* argv[]) {
    float phase = 0;
    float frequency = 440; // triangle wave frequency
    float increment = 2 * pi * frequency / SAMPLE_RATE;

    for (int i = 0; i < SAMPLE_RATE; i++) { // 1 second
        double sample;

        if (phase < pi) {
            // rising slope
            sample = (2.0 * phase / pi) - 1.0;
        } else {
            // falling slope
            sample = 3.0 - (2.0 * phase / pi);
        }

        mono(sample);

        phase += increment;
        if (phase >= 2 * pi)
            phase -= 2 * pi;
    }
}
