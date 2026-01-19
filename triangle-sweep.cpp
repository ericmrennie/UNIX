#include "everything.h"

int main(int argc, char* argv[]) {
    float phase = 0;

    // time → pitch sweep
    for (float note = 127; note > 0; note -= 0.001) {
        float frequency = mtof(note);
        float increment = 2 * pi * frequency / SAMPLE_RATE;

        double sample;

        if (phase < pi) {
            // rising slope: -1 → 1
            sample = (2.0 * phase / pi) - 1.0;
        } else {
            // falling slope: 1 → -1
            sample = 3.0 - (2.0 * phase / pi);
        }

        mono(sample * 0.5); // scale to avoid clipping

        phase += increment;
        if (phase >= 2 * pi)
            phase -= 2 * pi;
    }
}

