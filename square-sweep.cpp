#include "everything.h"

int main(int argc, char* argv[]) {
    float phase = 0;

    // time → pitch sweep
    for (float note = 127; note > 0; note -= 0.001) {
        float frequency = mtof(note);
        float increment = 2 * pi * frequency / SAMPLE_RATE;

        double sample;

        // square wave
        if (phase < pi) {
            sample = 1.0;
        } else {
            sample = -1.0;
        }

        mono(sample * 0.5); // scale to avoid clipping

        phase += increment;
        if (phase >= 2 * pi)
            phase -= 2 * pi;
    }
}

