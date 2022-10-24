#include <iostream>
#include <fstream>

#include "create_sine_wave.h"

using namespace std;

const int bitDepth = 16;
const int duration = 1;
auto sineFrequency = 440;
auto sineAmplitude = 0.5;
SineWave createSineWave(sineFrequency, sineAmplitude);
auto max_amplitude = pow(2, bitDepth - 1) - 1;

void toWavFile(ofstream &file, int value, int size) {
    file.write(reinterpret_cast<const char*> (&value), size);
}

int main() {
    ofstream output;
    output.open("UserName504_sine-to-wav.wav", ios::binary);

    output << "RIFF";
    output << "SIZE";
    output << "WAVE";

    output << "fmt ";
    toWavFile(output, 16, 4);
    toWavFile(output, 1, 2);
    toWavFile(output, 1, 2);
    toWavFile(output, sampleRate, 4);
    toWavFile(output, sampleRate * bitDepth / 8, 4);
    toWavFile(output, bitDepth / 8, 2);
    toWavFile(output, bitDepth, 2);

    output << "data";
    output << "SIZE";

    int preAudioPosition = output.tellp();

    for(int i = 0; i < sampleRate * duration; i++) {
        auto sine = createSineWave.create();
        int intSample = static_cast<int> (sine * max_amplitude);
        toWavFile(output, intSample, 2);
    }

    int postAudioPosition = output.tellp();
    output.seekp(preAudioPosition - 4);
    toWavFile(output, postAudioPosition - preAudioPosition, 4);
    output.seekp(4, ios::beg);
    toWavFile(output, postAudioPosition - 8, 4);
    output.close();
    return 0;
}