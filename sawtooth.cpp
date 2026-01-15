#include "everything.h"

int main(int argc, char* argv[]) {
    float phase = 0;
    float frequency = 440; // sawtooth frequency in Hz
    float increment = 2 * pi * frequency / SAMPLE_RATE;

    for (int i = 0; i < SAMPLE_RATE; i++) { // 1 second of audio
        // Sawtooth wave formula: linearly rising from -1 to 1
        double sample = 2.0 * (phase / (2.0 * pi)) - 1.0;

        mono(sample);

        // advance phase
        phase += increment;
        if (phase >= 2 * pi)
            phase -= 2 * pi;
    }
}
