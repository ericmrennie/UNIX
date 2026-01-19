#include "everything.h"

int main(int argc, char* argv[]) {
    float phase = 0;

    // time → pitch sweep
    for (float note = 127; note > 0; note -= 0.001) {
        float frequency = mtof(note);
        float increment = 2 * pi * frequency / SAMPLE_RATE;

        double sample = 0.0;

        // impulse at start of each cycle
        if (phase < increment) {
            sample = 1.0;
        }

        mono(sample);

        phase += increment;
        if (phase >= 2 * pi)
            phase -= 2 * pi;
    }
}
