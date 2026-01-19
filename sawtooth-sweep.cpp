#include "everything.h"

int main(int argc, char* argv[]) {
    float phase = 0;

    // time → pitch sweep
    for (float note = 127; note > 0; note -= 0.001) {
        float frequency = mtof(note);
        float increment = 2 * pi * frequency / SAMPLE_RATE;

        // sawtooth wave: -1 → 1 ramp
        double sample = 2.0 * (phase / (2.0 * pi)) - 1.0;

        mono(sample * 0.5); // scale to avoid clipping

        phase += increment;
        if (phase >= 2 * pi)
            phase -= 2 * pi;
    }
}
