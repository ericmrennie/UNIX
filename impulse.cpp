#include "everything.h"

int main(int argc, char* argv[]) {
    float phase = 0;
    float frequency = 440; // impulse frequency in Hz
    float increment = 2 * pi * frequency / SAMPLE_RATE;

    for (int i = 0; i < SAMPLE_RATE; i++) { // 1 second of audio
        double sample = 0.0;

        // generate impulse: spike at start of each period
        if (phase < increment) {
            sample = 1.0;  // spike
        } else {
            sample = 0.0;  // silence
        }

        mono(sample);

        // advance phase
        phase += increment;
        if (phase >= 2 * pi)
            phase -= 2 * pi;
    }
}
