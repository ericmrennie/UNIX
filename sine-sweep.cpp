#include "everything.h"

int main(int argc, char* argv[]) {
  float phase = 0; // where you are in the sine wave (0 -> 2PI)
  for (float note = 127; note > 0; note -= 0.001) { // time - note slowly decreases
    float frequency = mtof(note); // midi note changing every sample
    float v = sin(phase); // generate one sine wave
    mono(v * 0.707); // write one sample to the audio output // 0.707 volume scaling (avoid clipping)
    phase += 2 * pi * frequency / SAMPLE_RATE; // advance the phase based on frequency
    if (phase > 2 * pi)  // keep phase from growing forever
      phase -= 2 * pi;
  }
}
